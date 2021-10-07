/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep

 refined 2016/03/18 by Realtek
*/

#include <AmebaServo.h>

// create servo object to control a servo
// 4 servo objects can be created correspond to PWM pins
AmebaServo myservo;

const int servo_pin = 10;
const int trigger_pin = 6;
const int echo_pin = 7;

// variable to store the servo position
int pos = 0;

void setup() {
    Serial.begin(115200);
    pinMode(trigger_pin, OUTPUT);
    pinMode(echo_pin, INPUT);
    myservo.attach(servo_pin);
}

void loop() {
    float duration;
    int distance;

    // trigger a 10us HIGH pulse at trigger pin
    digitalWrite(trigger_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger_pin, LOW);

    // measure time cost of pulse HIGH at echo pin
    duration = pulseIn (echo_pin, HIGH);

    // calculate the distance from duration
    distance = duration / 58;

    pos = map(distance, 2, 15, 15, 100);
    myservo.write(pos);

    Serial.print(distance);
    Serial.println(" cm");

    delay(100);
}
