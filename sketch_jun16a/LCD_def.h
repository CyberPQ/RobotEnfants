int key=-1;
int oldkey=-1;

byte customFlecheGauche[8] = {
    0b00000,
    0b00010,
    0b00110,
    0b01110,
    0b11110,
    0b01110,
    0b00110,
    0b00010
};

byte customFlecheDroite[8] = {
    0b00000,
    0b01000,
    0b01100,
    0b01110,
    0b01111,
    0b01110,
    0b01100,
    0b01000
};

byte customFlecheHaut[8] = {
    0b00000,
    0b00100,
    0b00100,
    0b01110,
    0b01110,
    0b11111,
    0b11111,
    0b00000
};

byte customFlecheBas[8] = {
    0b00000,
    0b11111,
    0b11111,
    0b01110,
    0b01110,
    0b00100,
    0b00100,
    0b00000
};

//------------------------------------------------------------------------------------
// Définition des touches à l'intérieur de l'appli Arduino
// Ces touches sont celles de l'interface clavier du shield LCD SainSmart

#define KEY_NONE    (-1)
#define KEY_RIGHT   0
#define KEY_UP      1
#define KEY_DOWN    2
#define KEY_LEFT    3
#define KEY_SELECT  4

char msgs[5][16] = {"Right Key OK ",
                    "Up Key OK    ",               
                    "Down Key OK  ",
                    "Left Key OK  ",
                    "Select Key OK" };

unsigned int adc_key_val[5] ={50, 200, 400, 600, 800 };
int NUM_KEYS = 5;

//============================================================================
// Lecture de la touche clavier du shield LCD 
//     -1 : pas de touche
//      0 : Droite
//      1 : Haut
//      2 : Bas
//      3 : Gauche
//      4 : Select
//============================================================================
int get_lcd_key()
{
    int k = -1;
    unsigned int input = analogRead(0);    // read the value from the sensor
    for (k = 0; k < NUM_KEYS; k++)
    {
        if (input < adc_key_val[k])
        {
            return k;
        }
    }
    
    if (k >= NUM_KEYS)
        k = -1;     // No valid key pressed
    
    return k; 
}

