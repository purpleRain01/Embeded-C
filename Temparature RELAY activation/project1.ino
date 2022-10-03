
#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
#define trigPin 10
#define echoPin 13
int irsr=2;
int relay=8;
float duration,distance;

Adafruit_SSD1306 display(OLED_RESET);
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
void setup() 
{  
  mlx.begin();  
  Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  //setup function for setting all sensors into measurement mode
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode (irsr, INPUT);
  pinMode (relay, OUTPUT); 
}
void test()
 {
   display.clearDisplay();
   display.setTextColor(WHITE);
   display.setTextSize(2);
   display.setCursor(10,0);
   display.println("UNDER TEST");              //test fn for always keeping head section in
   display.display();                          //oled module showing UNDER TEST
   display.setTextSize(2);
   display.setCursor(0,16);
 }
void sr04()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);                        //Activating the HC-SR04 and finding the distance
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0343;
 Serial.println(distance);
  } 
void oled()                           //this function is automation for displaying text 
{                                     //which shows the people to put their hands over the sensor
   test();
   display.setTextSize(2);
    display.setCursor(0,16);
   display.println("This is a");
    display.display();
   delay(1000);
   test();
    display.println("Temparature");
    display.display(); 
    delay(1000);
    test();
     display.println("Controlled");
      display.display();
     delay(1000);
      test();
     display.println("Relay control");
      display.display();
     delay(2000);
     test();
     display.println("please put");
      display.display();
     delay(1000);
     test();
     display.println("your hands");
      display.display();
     delay(1000);
     test();
     display.println("on sensor");
      display.display();
     delay(1000);
     test();
}
void loop()
{
 sr04();
 if(distance>=40&&distance<70)//reading ultrasonic sensor and checking 
   {       //weather a person infront of the machine between a distance of 40cm and 70cm
    
    
    oled();    //displaying the instructions for a user
     int ir=digitalRead (irsr);
      if(ir==1)         //reading for hands over the sensor
       {
        test();
         display.println("please hold");  //instruction showing to hold a second over the sensor to read temperature
         float avg=0,temp;
         int pass=0;
        while(ir!=0)
         {
          temp=mlx.readObjectTempC();
          avg=avg+temp;
          pass++;
          display.println(pass*20);   //finding average temparautre of the body
          display.println("%");     //displaying the completion in %
          }
          avg=avg/pass;
          test();
          display.println("Temperature:");   //displaying temperature
          display.println(avg);
          delay(3000);
          if(avg>=38)         //checking readed body temperature with avearge body temperature
           {
            test();display.println("please visit");
            delay(2000);
            test();display.println("a doctor");
            delay(2000);
           }
           else if(avg<38)
            {
              test();
              display.println("WELCOME");
              digitalWrite(relay,HIGH);
              delay(1000);
               digitalWrite(relay,HIGH);  //activating relay if obtained temparature is below 38C
               delay(1000);
            }
           
       }
        
   }
}
