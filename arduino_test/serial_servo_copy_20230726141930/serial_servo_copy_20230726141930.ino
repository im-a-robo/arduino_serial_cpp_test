/*
  Serial Event example

  When new serial data arrives, this sketch adds it to a String.
  When a newline is received, the loop prints the string and clears it.

  A good test for this is to try it with a GPS receiver that sends out
  NMEA 0183 sentences.

  NOTE: The serialEvent() feature is not available on the Leonardo, Micro, or
  other ATmega32U4 based boards.

  created 9 May 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/SerialEvent
*/

#include <Servo.h>

String inputString = "";      // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

Servo basePlate;
Servo bottomArm;
Servo topArm;
String dataIn = "";
String arrData = "";
char c;
int posIndex;
int poses[3] = {90, 90, 90};

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  basePlate.attach(8);
  bottomArm.attach(10);
  topArm.attach(12);
}

void loop() {
  get_serial_data();

  if (c == '\n') {
    for(int i = 0; i <= dataIn.length(); i++) {
      if(dataIn[i] != ' ' && i != dataIn.length()) {
        arrData += dataIn[i];
      } else {
        poses[posIndex] = arrData.toInt();
        posIndex++;
        arrData = ""; 
      }
    }
    posIndex = 0;
    c = 0;
    dataIn = "";
  }

  basePlate.write(poses[0]);
  bottomArm.write(poses[1]);
  topArm.write(poses[2]);


}

void get_serial_data() {
  
  while(Serial.available() > 0) {

    c = Serial.read();

    if (c == '\n') {
      break;
    } else {
      dataIn += c;
    }
  }

}