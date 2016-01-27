int bt=-1;

//------------------------------------------------------------------------------------
// Définition des touches en provenance de l'appli 
// Android "Arduino BT Joystick Free" version 3.0.5, de Felipe Porge
// https://play.google.com/store/apps/details?id=com.heightdev.arduinobtjoysticklite

#define BT1_NONE    '0'
#define BT1_RIGHT   '4'
#define BT1_UP      '1'
#define BT1_DOWN    '2'
#define BT1_LEFT    '3'
#define BT1_SELECT  '5'
#define BT1_START   '6'
#define BT1_TRIANG  '7'
#define BT1_SQUARE  '8'
#define BT1_X       '9'
#define BT1_BALL    'A'

//------------------------------------------------------------------------------------
// Définintion des touches en provenance de l'appli
// Android "Arduino Controlled Robot" de Silver Coder
// remarque : il existe aussi les touches ['0'..'9'] et '-'
// https://play.google.com/store/apps/details?id=pl.mobilerobots.vacuumcleanerrobot

#define BT2_GO      'g'
#define BT2_FORWARD 'f'
#define BT2_BACK    'b'      /*                         */
#define BT2_RIGHT   'r'      /*         d  f  c         */
#define BT2_LEFT    'l'      /*          \ | /          */
#define BT2_TOP_R   'c'      /*       l - g/s - r       */
#define BT2_TOP_L   'd'      /*          / | \          */
#define BT2_BOT_R   'e'      /*         h  b  e         */
#define BT2_BOT_L   'h'      /*                         */
#define BT2_STOP    's'
#define BT2_X       'x'

//------------------------------------------------------------------------------------
// Définintion des touches en provenance de l'appli
// Android "BT Bot Control" de PixelMason
// remarque : il existe aussi les touches ['0'..'8']
// remarque : en mode avancé; on recoit le jostick en "sX=75,Y=-55e" et les commande en "sC=1e"
// Remarque : Cette applic peut également afficher l'image d'une caméra IP
// Remarque : Affiche aussi les données en proveance du robot ">15|73%|25° C|item4|item5<"
// https://play.google.com/store/apps/details?id=appinventor.ai_picoware.BTBotControlLite

#define BT3_FORWARD 'U'
#define BT3_BACK    'D'
#define BT3_RIGHT   'R'
#define BT3_LEFT    'L'
#define BT3_STOP    'S'

//------------------------------------------------------------------------------------
// Définintion des touches en provenance de l'appli
// Android "Bluetooth Robot Remote Control" de Hobbyprojects.com
// https://play.google.com/store/apps/details?id=appinventor.ai_hobbyprojects_com.BluetoothRoboControl

#define BT4_UP      'A'
#define BT5_DOWN    'B'
#define BT5_LEFT    'C'
#define BT5_RIGHT   'D'
#define BT5_STOP    'E'
#define BT5_P360    'F'     // +360°
#define BT5_M360    'G'     // -360°

//============================================================================
// Lecture des ordre en provenance du bluetooth
//     -1 : pas de touche
//      0 : Droite
//      1 : Haut
//      2 : Bas
//      3 : Gauche
//      4 : Select
//============================================================================
int get_bt_key()
{
    int k = -1;
    int incomingByte = -1;   // for incoming serial data
    
    if (Serial2.available() > 0)
    {
        // read the incoming byte:
        incomingByte = Serial2.read();

        // conversion du code télécommande android en numéro de touche
        // pour l'appli Android "Arduino BT Joystick Free" version 3.0.5
        /*
        switch(incomingByte)
        {
            case BT1_NONE   : k=KEY_NONE; break;
            case BT1_RIGHT  : k=KEY_RIGHT; break;
            case BT1_UP     : k=KEY_UP; break;
            case BT1_DOWN   : k=KEY_DOWN; break;
            case BT1_LEFT   : k=KEY_LEFT; break;
            case BT1_SELECT : k=KEY_SELECT; break;
            default        : k=KEY_NONE; break;
        }
        */
        k = incomingByte;
        
        // pour debug sur port série
        /*
        Serial.print("BT received: 0x");
        Serial.print(incomingByte, HEX);    // en hexa
        Serial.print(" = ");
        Serial.print(incomingByte, DEC);    // en decimal
        Serial.print("d = '");
        */
        Serial.write(incomingByte);         // en ascii
        /*
        Serial.print("' --> touche ");
        Serial.println(k);
        */
    }

    return k;
}

