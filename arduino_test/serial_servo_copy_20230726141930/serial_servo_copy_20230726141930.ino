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

Servo myservo;
int pos = 0;
String dataIn = "";
char c;

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  myservo.attach(9);
}

void loop() {
  get_serial_data();

  if (c == '\n') {
    pos = dataIn.toInt();
    c = 0;
    dataIn = "";
  }

  myservo.write(pos);


}

void get_serial_data() {
  
  while(Serial.available() > 0) {

    c = Serial.read();
    // Serial.println(c);

    if (c == '\n') {
      break;
    } else {
      dataIn += c;
    }
  }

}