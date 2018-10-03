#ifndef Ping_h
#define Ping_h

#include <Arduino.h>
#include <Servo.h>

class Ping
{
	public:
		Ping(){}

		struct point
		{
		  float X;
		  float Y;
		};

		void setPins(int t_pin, int e_pin, int servo_pin);
		void setServo(int pos);
		float scan();
		Ping::point* sweep(int degrees);

	private:
		Servo _servo;
		int _trig_pin;
		int _echo_pin;
		int _servo_pos;
		
		//typedef point* _scan_map;
};

#endif