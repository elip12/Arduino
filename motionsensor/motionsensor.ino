#include <Servo.h>

const int spin = 8; //servo pin
const int ppin = A0;
Servo serv;
bool state;
int minl, maxl, adjval, val, counter;

void setup() 
{
  serv.attach(spin);
  serv.writeMicroseconds(1500);
  state = true;

  val = analogRead(ppin);
  minl = val - 20;
  maxl = val;
  counter = 0;
  Serial.begin(9600);

}

void loop() 
{
  val = analogRead(ppin);
  if(val < minl)
    minl = val;
  if(val > maxl)
    maxl = val;
  adjval = map(val, minl, maxl, 0, 100);
  Serial.println(adjval);
  counter++;
  if (adjval < 75 && counter > 10)
  {
    counter = 0;
    state = !state;
  }
  if (state == true)
     serv.write(150);
  else
    serv.write(10);

  delay(50);
}
