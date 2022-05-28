# PS4_Control_ESP32
- Description: MCU(Esp32 in this case) that connects to a PS4 Controller. The Controller turnon/turnoff LEDs when some buttons(Cross, Circle, Square) are pressed and the Left Analog Sticker dims another LED.

- Connections:
	
  PS4 Control(Bluetooth)   ->     ESP32(WROOM MODULE)
  
  VCC    				           -> 	  Powered by USB 
  
  LED Output(3V3 Logic)    -> 	  GPIO 13,GPIO 12,GPIO 27
  
  LED Output(PWM) 	       -> 	  GPIO 26

- To be able to use the library, you must pair the control with other device (cell phone for example), write down the MAC address of the device and replace it in the code.
- Another alternative is to force a MAC address using the SixAxisPairer application and repeat it in the code.

- Dependencies:
     - Installing ESP32 board in Arduino IDE   : https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/
     - Arduino library to manage Telegram Bots : https://github.com/aed3/PS4-esp32
     - SixAxisPairer : https://github.com/user-none/sixaxispairer
