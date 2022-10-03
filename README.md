Microcontroller
Arduino Uno

used sensors
1.Adafruit_MLX90614 temperature sensor
2.0.96" OLED I2C display module
3.HC-SR04 ultrasonic distance sensor
4.IR proximity sensor

uses
controlling Automatic doors in Theaters,Shopping malls,Lift,escalators etc..that is whereever a RELAY module can control any AC equipment we can add this feature tto
so we can monitor the person who is asking for accessing the equipment. this system itself can provide access to them by checking their temperature in covid pandemic
situations.

working
when a person comes in between a distance of 40cm and 70 cm infronth of this system,HC SR04 reports a person to arduino.the arduino commands to the OLED display-
to show off the istructions for the person.according to the instructions whenever the person put his/ger hands over the sensor MLX90614 first IR proximity
sensor reports its state to 1 to arduino then arduino continuosly starts reading the temperature through MLX90614 and takes the average.so after getting the average-
body temperature arduino decides with if condition for giving persmission to the user.
