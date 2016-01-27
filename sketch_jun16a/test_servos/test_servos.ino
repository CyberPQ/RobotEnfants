/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/ 

#define SERVO_GAUCHE    44
#define SERVO_DROITE    46
#define SERVO_TETE      42

#define VITESSE_STOP    90
#define VITESSE_LENTE   (VITESSE_STOP+5)
#define VITESSE_RAPIDE  (VITESSE_STOP+80)

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  myservo.attach(SERVO_GAUCHE);  // attaches the servo on pin 9 to the servo object 
  //myservo.attach(SERVO_DROITE);  // attaches the servo on pin 9 to the servo object 
  //myservo.attach(SERVO_TETE);    // attaches the servo on pin 9 to the servo object 
} 
 
void loop() 
{ 
    myservo.write(VITESSE_STOP);
    delay(1000);
    myservo.write(VITESSE_LENTE);
    delay(1000);
    myservo.write(VITESSE_RAPIDE);
    delay(1000);   
} 

