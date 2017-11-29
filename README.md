# Arduino Projects

Some simple, fun projects I've made with my Arduino. All my code is available for anyone to use and/or copy.

pingProject uses a servo, an ultrasonic distance sensor, an LCD display, and a potentiometer. You can twist the potentiometer to rotate to servo and attached ping sensor, which continuously pings and reports the distance of the closest object to the LCD display. This can be modified easily to direct a little robot, or to scan and locate the most open area around the sensor.

motionsensor uses a photoresistor (light sensor) to rotate a servo if motion is detected over the photoresistor. If you wave your hand over it, the servo will move. 

speedtrap is an incomplete project. I unfortunately took it apart without taking a picture of it, but it has a similar setup as the motionsensor. There are 3 photoresistors in a line on the breadboard, each a set distance from one another. If you wave your hand over them, the arduino calculates the speed you waved your hand at using the time that each one registers a decrease in light. There were a few issues with refreshing the display and solving for the correct velocity.
