#include <LiquidCrystal.h>

const int l1 = A0;
const int l2 = A1;
const int l3 = A2;

LiquidCrystal lcd(12,11,5,4,3,2);
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

 int val1, val2, val3, aval1, aval2, aval3;
 int min1, min2, min3, max1, max2, max3;
 float t1, t2, t3;
 const float dist = 3.0;
 float veloc;
 
void setup() 
{
  Serial.begin(9600);
  lcd.begin(16,2);

  val1 = analogRead(l1);
  min1 = val1 - 20;
  max1 = val1;

  val2 = analogRead(l2);
  min2 = val2 - 20;
  max2 = val2;
  
  val3 = analogRead(l3);
  min3 = val3 - 20;
  max3 = val3;
}

void loop() 
{
  
  val1 = analogRead(l1);
  if(val1 < min1)
    min1 = val1;
  if(val1 > max1)
    max1 = val1;
  aval1 = map(val1, min1, max1, 0, 100);
  if (aval1 < 85)
    t1 = millis();
  
  val2 = analogRead(l2);
  if(val2 < min2)
    min2 = val2;
  if(val2 > max2)
    max2 = val2;
  aval2 = map(val2, min2, max2, 0, 100);
  if (aval2 < 85)
    t2 = millis();
  
  val3 = analogRead(l3);
  if(val3 < min3)
    min3 = val3;
  if(val3 > max3)
    max3 = val3;
  aval3 = map(val3, min3, max3, 0, 100);
  if (aval3 < 85)
    t3 = millis();

  float delta1 = 1000 * (t2 - t1);
  float delta2 = 1000 * (t3 - t2);
  float speed1 = dist / delta1;
  float speed2 = dist / delta2;
  veloc = (speed1 + speed2) / 2;
  Serial.println(t1);
  Serial.println(t2);
  Serial.println(t3);
  Serial.println();
  lcd.print("Speed ");
  lcd.print(veloc);
  lcd.print(" cm/s");
  delay(50);
  lcd.clear();
 
}
