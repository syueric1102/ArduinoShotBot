#include <Servo.h>

Servo spout;

const int sensorPinLeft = A0; //pin A0 to read analog input
const int sensorPinRight = A1;
boolean rightState;
boolean leftState;




//Variables:

int valueLeft; //save analog value
int valueRight;


void setup(){
  Serial.begin(9600);       //Begin serial communication

  spout.attach(12);
  spout.write(90);
  pinMode(10, OUTPUT);

  rightState = false;
  leftState = false;
}

boolean getStateRight(){
  valueRight = analogRead(sensorPinRight);       //Read and save analog value from potentiometer
  if(valueRight > 70){
    return true;
  }
  return false;
}

boolean getStateLeft(){
  valueLeft = analogRead(sensorPinLeft);
  if(valueLeft > 70){
    return true;
  }
  return false;
}



void loop(){
  Serial.println(analogRead(sensorPinRight));               //Print value
  Serial.print(" ");
  Serial.print(analogRead(sensorPinLeft));               //Print value

  if(getStateRight() != rightState){                     //if there is a change in state
    if(getStateRight() == true){
      spout.write(120);
      delay(1000);
      /*
      int temp1 = analogRead(sensorPinRight);
      digitalWrite(10, HIGH);
      while(true){
        int temp2 = analogRead(sensorPinRight);
        int difference = temp2 - temp1;
        if(difference > 90){
          digitalWrite(10, LOW);
          break;
        }
        delay(10);
      }
      */
      
      digitalWrite(10, HIGH);
      delay(1750);
      digitalWrite(10, LOW);
      
      delay(1000);
      spout.write(90);
      rightState = getStateRight();
    }
    else{
      spout.write(90);
      rightState = getStateRight();
    }
  }
  delay(200);
  if(getStateLeft() != leftState){                     //if there is a change in state
    if(getStateLeft() == true){
      spout.write(60);
      delay(1000);
      /*
      int temp3 = analogRead(sensorPinLeft);
      digitalWrite(10, HIGH);
      while(true){
        int temp4 = analogRead(sensorPinLeft);
        int difference = temp3 - temp4;
        if(difference > 90){
          digitalWrite(10, LOW);
          break;
        }
        delay(10);
      }
      */
      
      digitalWrite(10, HIGH);
      delay(1750);
      digitalWrite(10, LOW);
      delay(1000);
      
      spout.write(90);
      leftState = getStateLeft();
    }
    else{
      spout.write(90);
      leftState = getStateLeft();
    }
  }
  
 
  delay(200);                          //Small delay
}







