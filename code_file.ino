#include <Keyboard.h>

#include <Servo.h>
Servo s1;
Servo s2;
Servo claw;

int joyx = A1;
int joyy = A0;
int button = 2;
int joyvalx,joyvaly;
bool buttonpressed;

void setup() {
pinMode(joyx, INPUT);
pinMode(joyy, INPUT);
pinMode(button, INPUT_PULLUP);

s1.attach(3);
s2.attach(4);
claw.attach(5);


}

void loop() {
joyvalx = analogRead(joyx);
joyvalx = map(joyvalx,0,1023,0,180);  //s1 servo will control x-z plane
s1.write(joyvalx);

joyvaly = analogRead(joyy);
joyvaly = map(joyvaly,0,1023,0,180);
s2.write(joyvaly);

buttonpressed = digitalRead(button) == LOW; //buttonpressed is true if the joystick is pressed
if(buttonpressed == 'true')
claw.write(90); //90 degree rotation of the claw servo to open the arms
else
claw.write(0);

}
