#ifndef Drive_h
#define Drive_h

#include <Arduino.h>
#include <Servo.h>

class Drive
{
	public:
		Drive(){} //servo pins cannot be defined in init function
		void setPins(int l_pin, int r_pin);
		void forward();
		void backward();
		void left();
		void right();
		void rest();
	private:
		Servo _servo_left;
		Servo _servo_right;
};

#endif