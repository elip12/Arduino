// Eli Pandolfo
// v0.1
// range finder: user rotates servo with Ping ultrasonic sensor on it,
// to measure distance with the Ping, and prints the distance to an LCD

// one potentiometer controls the angle of the servo, the other controls 
// the contrast of the LCD display

// in this program, ms refers to microseconds
// accurate to cm from 2 cm to ~1 m, accurate to 1/2 m from ~1 to ~3 m 

#include <LiquidCrystal.h>
#include <Servo.h>

const int ppin = 8; // ping pin
const int spin = 9; // servo pin
const int potpin = A0; // servo potentiometer input pin
int val; // value from potentiometer

LiquidCrystal lcd(12,11,5,4,3,2);
Servo serv;

/* lcd pins:
 * 1: gnd
 * 2: vdd
 * 3: v0
 * 4: rs
 * 5: rw
 * 6: e
 * 7-14: db0-db7
 * 15: bl1
 * 16: bl2
 */

void setup() 
{
  Serial.begin(9600);
  
  // set up lcd # of cols and rows
  lcd.begin(16,2);
  
  //set up servo
  serv.attach(spin);
  serv.writeMicroseconds(1500); // 1.5 ms stay-still signal
  
}

void loop() 
{
  long duration, cm; // input from ping sensor

  //Ping is triggered by HIGH pulse for 2 or more ms
  // give short LOW pulse beforehand to ensure clean high pulse
  pinMode(ppin, OUTPUT);
  digitalWrite(ppin, LOW);
  delayMicroseconds(2);
  digitalWrite(ppin, HIGH);
  delayMicroseconds(5);
  digitalWrite(ppin, LOW);

  //read input with same pin
  pinMode(ppin, INPUT);
  duration = pulseIn(ppin, HIGH);
  cm = ms_to_cm(duration);

  //print distange and angle to LCD
  lcd.print("Distance: ");
  lcd.print(cm);
  lcd.print(" cm");
  lcd.setCursor(0,1);
  lcd.print("Angle: ");
  lcd.print(val);
  lcd.print(" deg");

  val = analogRead(potpin); // reads servo potentiometer value
  val = map(val,0,1023,0,180); // maps 1023 pot vals to 180 servo vals
  serv.write(val);
  
  delay(40); // delay between pulses in milliseconds
  lcd.clear(); // refreshes LCD screen
}

/*converts microseconds to cm:
 speed of sound is 340 m/s or 29 ms/cm
 sound travels out and back so we divide time by 2 to get only out time
 */
long ms_to_cm(long microseconds)
{
  return microseconds/29/2;
}

