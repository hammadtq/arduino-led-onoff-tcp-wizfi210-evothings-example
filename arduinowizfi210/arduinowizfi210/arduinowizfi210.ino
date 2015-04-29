/*
Arduino Turn LED On/Off using Serial Commands
Created April 29, 2015
Hammad Tariq, Incubator (Pakistan)

It's a simple sketch which waits for a character on serial
and in case of a desirable character, it turns an LED on/off.

Possible string values:
a (to turn the LED on)
b (tor turn the LED off)
*/

char junk;
String inputString="";


void setup()                    // run once, when the sketch starts
{
 Serial.begin(115200); 
 pinMode(12, OUTPUT);
}

void loop()
{
  if(Serial.available()){
  while(Serial.available())
    {
      char inChar = (char)Serial.read(); //read the input from serial
      inputString += inChar;
    }
    Serial.println(inputString);
    while (Serial.available() > 0)  
    { junk = Serial.read() ; }      // clear the buffer
    if(inputString == "a"){     // in case of 'a', turn the LED on
      digitalWrite(12, HIGH);  
    }else if(inputString == "b"){ // in case of 'b', turn the LED off
      digitalWrite(12, LOW);
    }
    inputString = "";
  }
}
