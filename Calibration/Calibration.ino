
const int sensorPinLeft = A0; //pin A0 to read analog input
const int sensorPinRight = A1;


//Variables:

int valueLeft; //save analog value
int valueRight;


void setup(){
  Serial.begin(9600);       //Begin serial communication
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
  Serial.print(analogRead(sensorPinLeft));               //Print value
  Serial.print(" ");
  Serial.println(analogRead(sensorPinRight));               //Print value
  
  delay(200);
 
}







