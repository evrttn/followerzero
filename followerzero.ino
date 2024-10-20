#define Left_mot 5 // Left motor PWM
#define Right_mot 10 // Right motor PWM

int in1_MA = 9, in2_MA = 8, in3_MB = 7, in4_MB = 6;

int L_sens; // Left Sensor
int R_sens; // Right Sensor
int state; //which state the robot is in (turning left, turning right, straight)

void setup(){ // Will apply 5V to each of these pins when needed 
  pinMode (Left_mot, OUTPUT);
  pinMode (Right_mot, OUTPUT);

  pinMode(in1_MA, OUTPUT);
  pinMode(in2_MA, OUTPUT);
  pinMode(in3_MB, OUTPUT);
  pinMode(in4_MB, OUTPUT);

  // set motor direction to forward
  digitalWrite(in1_MA, LOW);
  digitalWrite(in2_MA, HIGH);
  digitalWrite(in3_MB, HIGH);
  digitalWrite(in4_MB, LOW);

  state = 1; //state will equal 1 and bot will go straight
}

void loop() // start of main function and will keep repeating
{ 
  L_sens = analogRead(0)/4; // Reads the left sensor
  R_sens = analogRead(4)/4; // Reads the right sensor
  
//-----------------------------------------------------------------------------------  
  if (state ==1) //state will make robot go straight or continue with the last state it was in
  {
       
  analogWrite(Left_mot,255);
  analogWrite(Right_mot,255);
      
    if (R_sens < 100) // Compares the right sensor to a certain range
    {
      state = 2;
    }
    else if (L_sens < 100) // Compares the left sensor to a certain range
    {
      state = 3;
    }
  }  
//-----------------------------------------------------------------------------------  
  else if (state == 2) // state where robot is turning right
  {
    
    analogWrite(Right_mot,45); // Writes a PWM signal to the Left motor pin
    analogWrite(Left_mot,255); // Writes a PWM signal to the Right motor pin
  
    if (L_sens < 100) // Compares the right sensor to a certain range
    {
      state = 3;
    }
    else if (R_sens < 100 && L_sens < 100)
    {
      state = 1;
    }
  }
//---------------------------------------------------
  else if(state == 3) // state where robot is turning left
  {  
    analogWrite(Right_mot,255); // Writes a PWM signal to the Right motor pin
    analogWrite(Left_mot,45); // Writes a PWM signal to the Left motor pin
  
    if (R_sens < 100) // Compares the right sensor to a certain range
    {
      state = 2;
    }  
    else if (R_sens < 100 && L_sens < 100)

    {
      state = 1;
    }
  }
}