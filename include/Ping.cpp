#include <Arduino.h>
#include <Servo.h>
#include <math.h>

#include "Ping.h"

#define PI 3.141592654

void Ping::setPins(int trig_pin, int echo_pin, int servo_pin)
{
	_trig_pin = trig_pin;
	_echo_pin = echo_pin;
	pinMode(_trig_pin, OUTPUT);
	pinMode(_echo_pin, INPUT);
	_servo.attach(servo_pin);

	_servo.write(90);
	_servo_pos = 90;
}

void Ping::setServo(int pos)
{
	_servo_pos = pos;
	_servo.write(_servo_pos);
}

float Ping::scan()
{
  long duration, cm, inches;
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(_trig_pin, LOW);
  delayMicroseconds(5);
  digitalWrite(_trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trig_pin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(_echo_pin, INPUT);
  duration = pulseIn(_echo_pin, HIGH);
 
  // convert the time into a distance
  //cm = (duration/2) / 29.1;
  inches = (duration/2) / 74; 
  
  return inches;
}

Ping::point* Ping::sweep(int d)
{

	//Make a check that the degree input is correct

	///////////////////////////////////

	//Set servo to start of sweep, use a steping method
	//add this method to set servo and use it instead
	while (_servo_pos != 90 - d/2)
	{
		_servo_pos --;
		_servo.write(_servo_pos);
		delay(15);
	}

	////////////////////////////////////
	Ping::point * m = new Ping::point[d];

	int angle = 0 - d/2;
	_servo_pos = 90 - d/2;


	for (int i = 0; i < d; i ++)
	{
		_servo_pos = _servo_pos + 1;
		_servo.write(_servo_pos);
		delay(15);

		float dist = Ping::scan();
		angle ++;
		m[i].X=dist * cos(angle * PI / 180);
		m[i].Y=dist * sin(angle * PI / 180);
	}
	delay(50);

	///////////////////////////////////

	//set servo pos back to 90
	while (_servo_pos != 90 )
	{
		_servo_pos --;
		_servo.write(_servo_pos);
		delay(20);
	}
	return m;
	
} 
