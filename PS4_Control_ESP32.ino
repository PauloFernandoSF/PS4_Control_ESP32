/*
 Name:		    PS4_Control_ESP32.ino
 Created:	    27/05/2022
 Author:	    Paulo Fernando <pfsf07@gmail.com>
 Description: MCU(Esp32 in this case) that connects with a PS4 Controller. The Controller turnon/turnoff LEDs when some buttons are pressed and the Left Analog Sticker dims another LED.
 Connections:
	PS4 Control(Bluetooth)   ->     ESP32(WROOM MODULE)
	VCC    				           -> 	  Powered by USB 
	LED Output(3V3 Logic)    -> 	  GPIO 13,GPIO 12,GPIO 27
  LED Output(PWM) 	       -> 	  GPIO 26 
*/
//PS4 Control Library
#include <PS4Controller.h>
//LEDs that are turned on/off 
#define led_13 13
#define led_12 12
#define led_27 27
//LED that is dimmered
#define led_26 26

void setup(){
  //Serial port to debug
  Serial.begin(115200);
  //LEDs controlled by Buttons 
  pinMode(led_13, OUTPUT);
  pinMode(led_12, OUTPUT);
  pinMode(led_27, OUTPUT);
  //PWM config:Channel, Frequency, Resolution
  ledcSetup(0, 5000, 8);
  //PWM output pin
  ledcAttachPin(led_26, 0);
  //PS4 Config- MAC ADRESS
  PS4.begin("c0:8c:71:66:96:7c");
  Serial.println("Ready.");
}

void loop(){
  //Check connection between ESP32 and PS4 Controller  
  if(PS4.isConnected()){
    //Change LED state, when "Square" button is pressed
    if(PS4.Square()){
      delay(50);
      //Serial.println("Square Button");
      digitalWrite(led_12, !digitalRead(led_12));
      digitalWrite(led_13, HIGH);
    }
    //Change LED state, when "Cross" button is pressed
    if(PS4.Cross()){
      delay(50);
      //Serial.println("Cross Button");
      digitalWrite(led_13, !digitalRead(led_13));
      digitalWrite(led_12, HIGH);
    }
    //Change LED state, when "Circle" button is pressed
    if(PS4.Circle()){
      delay(50);
      //Serial.println("Circle Button");
      digitalWrite(led_27, !digitalRead(led_27));
    }
    //LED Dimmer
    if(PS4.LStickY()){
      delay(50);
      //Serial.println("Left Stick y at %d\n", 2*PS4.LStickY());
      //Analog Stick varies between -127 to 127 and PWM output varies between 0 to 256
      if(PS4.LStickY() > 0)
        //When Left Stick has a positive value this value is passed to PWM output
        ledcWrite(0, 2*PS4.LStickY());
      if(PS4.LStickY() < 0)
        //When Left Stick has a negative value, zero is passed to PWM output
        ledcWrite(0,0); 
    }
  }
}