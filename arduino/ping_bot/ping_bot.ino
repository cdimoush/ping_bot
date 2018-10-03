
#include <Drive.h>
#include <Ping.h>

#define left_servo_pin 4
#define right_servo_pin 3
#define ping_servo_pin 2

#define trig_pin 5    //Trig - orange Jumper
#define echo_pin 6    //Echo - red Jumper

Drive bot_drive;
Ping ping;


int degree = 100;

typedef Ping::point* scan_map;
void setup() 
{
  
  bot_drive.setPins(left_servo_pin, right_servo_pin);
  ping.setPins(trig_pin, echo_pin, ping_servo_pin);
  Serial.begin(9600);
  Serial.println("Ping Bot is operational");
}

void loop() 
{
 scan_map new_map(degree);
 new_map = ping.sweep(degree);
 for(int i = 0; i < degree; i++)
 {
  if (i == 0)
  {
    Serial.print(0);
    Serial.print("\t");
    int time = millis();
  }
  else if (new_map[i].X < 12)
  {
    Serial.print(new_map[i].X);
    Serial.print("\t");
    int time = millis();
    Serial.println(time /1000) ;
  }
  else
  {
    Serial.print(12);
    Serial.print("\t");
    int time = millis();
    Serial.println(time /1000) ;
  }
 }
 delay(2000);
}



