#include <NewPing.h>
#include <Servo.h> 
#include <LiquidCrystal.h>
#include "LCD_def.h"
#include "BT_def.h"
#include "ROUES_def.h"

/*
  The circuit:
 * LCD RS pin to digital pin 8
 * LCD Enable pin to digital pin 9
 * LCD D4 pin to digital pin 4
 * LCD D5 pin to digital pin 5
 * LCD D6 pin to digital pin 6
 * LCD D7 pin to digital pin 7
 * KEY pin to analogl pin 0
 * Vcc pin to  +5
 * Trig pin to digital pin 22
 * Echo pin to digital pin 24
 */

#define TRIGGER_PIN   51    //Trig_pin
#define ECHO_PIN      53    //Echo_pin
#define MAX_DISTANCE 500    //en cm

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.


//============================================================================
// Initialisation
//============================================================================
void setup()
{
    // create new custom characters
    lcd.createChar(0, customFlecheGauche);
    lcd.createChar(1, customFlecheDroite);
    lcd.createChar(2, customFlecheHaut);
    lcd.createChar(3, customFlecheBas);
    
    lcd.clear(); 
    lcd.begin(16, 2);
    lcd.setCursor(3, 1); 
    lcd.write(byte(0));
    lcd.write(byte(1));
    lcd.write(byte(2));
    lcd.write(byte(3));
    lcd.setCursor(0,0); 

    servo_g.attach(SERVO_GAUCHE);
    servo_d.attach(SERVO_DROITE);
    //servo_tete.attach(SERVO_TETE);
    roues_stop();
    //servo_tete.write(VITESSE_STOP);
    
    Serial.begin(115200);       // en USB
    Serial2.begin(115200);       // en bluetooth

    Serial.println("Hello");
    Serial2.println("Hello");
}

//============================================================================
// Boucle infinie
//============================================================================
void loop()
{
    unsigned int distance_cm = sonar.ping_cm(); // Send a ping and get the distance in whole centimeters.

    lcd.setCursor(0,0); 
    lcd.print(" Dist : "); 
    lcd.print(distance_cm); 
    lcd.print(" cm  "); 
    
    //Serial.println(distance_cm);    // en USB
    //Serial3.println(distance_cm);   // en bluetooth
    
    key = get_lcd_key();    // get key press, if any (-1 otherwise)
    bt  = get_bt_key();
    
    if (key != oldkey)  // if keypress is detected
    {
        delay(50);    // wait for debounce time
        
        key = get_lcd_key();    // convert into key press
        if (key != oldkey)        
        {     
            oldkey = key;
            if (key >=0)
            {
                lcd.setCursor(0, 1);  //line=2, x=0
                lcd.print(msgs[key]);
            }
        }
    }

    if(bt!=-1)
    {
        lcd.setCursor(15, 1); 
        lcd.write(bt);
    }

    switch(bt)
    {
        //case -1:
        case 's':
            roues_stop(); break;
        case 'f':
            roues_cmd(+RAPIDE,+RAPIDE); break;
        case 'b':
            roues_cmd(-RAPIDE,-RAPIDE); break;
        case 'l':
            roues_cmd(-RAPIDE,+RAPIDE); break;
        case 'r':
            roues_cmd(+RAPIDE,-RAPIDE); break;
        case 'd':
            roues_cmd(+LENT  ,+RAPIDE); break;
        case 'c':
            roues_cmd(+RAPIDE,+LENT  ); break;
        case 'h':
            roues_cmd(-LENT  ,-RAPIDE); break;
        case 'e':
            roues_cmd(-RAPIDE,-LENT  ); break;
        default:
            // rien !
            break;
    }
}





