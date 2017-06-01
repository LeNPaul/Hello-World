#include <Bridge.h>
#include <BridgeClient.h>
#include <BridgeServer.h>
#include <BridgeUdp.h>
#include <Console.h>
#include <FileIO.h>
#include <HttpClient.h>
#include <Mailbox.h>
#include <Process.h>
#include <YunClient.h>
#include <YunServer.h>

#include <Servo.h>
#define servo_pin 8
#define default_angle 100
#define angle_on 10
#define angle_off 170
#define input_on 1
#define input_off 2
Servo myservo;  // create servo object to control a servo

int val=0;    // for mapping angles
int read_val=0;
int  i=0;

void setup()
{ Serial.begin(9600);
  myservo.attach(servo_pin);  // attaches the servo on pin 9 to the servo object
  
  //test
  for(i=0;i<180;i=i+10){
    myservo.write(i);                  // sets the servo position according to the scaled value 
    delay(1000);
    Serial.println(i);
  }

  
}

void loop() 
{ 
  //read bluetooth data 1- On 2 - Off
  if (Serial.available()){
    read_val = Serial.read();
    
    //if not on the off
    if(read_val != input_on){
      read_val = input_off; 
    }
  }

  //if input read on
  if(read_val = 1){
    val = map(angle_on, 0, 1023, 0, 180);  
    myservo.write(val);
    read_val = input_off;
  }

  //iif input read off
  if(read_val = input_off){
    val = map(angle_off, 0, 1023, 0, 180);  
    read_val = input_off;
  }
    
    
  
  delay(15);                           // waits for the servo to get there 
} 

