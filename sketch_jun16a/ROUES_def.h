#define SERVO_GAUCHE    44
#define SERVO_DROITE    46
#define SERVO_TETE      42

#define VITESSE_STOP    90
#define VITESSE_LENTE   (VITESSE_STOP+5)    // à ajuster
#define VITESSE_RAPIDE  (VITESSE_STOP+80)   // à ajuster

#define RAPIDE  (VITESSE_RAPIDE-VITESSE_STOP)
#define LENT    (VITESSE_LENTE -VITESSE_STOP)

Servo servo_g, servo_d, servo_tete;

void roues_stop(void)
{
    servo_g.write(VITESSE_STOP);
    servo_d.write(VITESSE_STOP);
}

void roues_cmd(int vitesse_gauche,int vitesse_droite)
{
    servo_g.write(VITESSE_STOP-vitesse_gauche); //servo gauche dans l'autre sens
    servo_d.write(VITESSE_STOP+vitesse_droite);
}

