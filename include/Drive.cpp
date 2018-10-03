#include <Arduino.h>
#include "Drive.h"

#include <Servo.h>

void Drive::setPins(int l_pin, int r_pin)
{
	//This function needs to be called in setup()
	_servo_left.attach(l_pin);
	_servo_right.attach(r_pin);

	Drive::rest();
}

void Drive::forward()
{
	_servo_left.write(95);
	_servo_right.write(85);
}
void Drive::backward()
{
	_servo_left.write(85);
	_servo_right.write(95);
}
void Drive::left()
{
	_servo_left.write(85);
	_servo_right.write(85);
}
void Drive::right()
{
	_servo_left.write(95);
	_servo_right.write(95);
}
void Drive::rest()
{
	_servo_left.write(90);
	_servo_right.write(90);
}