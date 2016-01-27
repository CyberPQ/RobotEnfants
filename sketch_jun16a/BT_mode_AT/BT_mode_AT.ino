void setup() {
      
    Serial.begin(38400);       // en USB
    Serial3.begin(38400);       // en bluetooth em mode AT

    Serial.println(" ");
    Serial.println("AT mode : Démarer le module avec le BP appuyé, et relacher après 5s.");
    Serial.println("Remember to to set Both NL & CR in the serial monitor.");
 
    Serial.println("Enter AT commands");
    Serial.println("");
 
    Serial.print("BT STATE = ");
    Serial3.println("AT+STATE" );

    // AT+NAME=MegaBot
    // AT+UART=115200,0,0
    
}

void loop() {

    // listen for communication from the BT module and then write it to the serial monitor
    if ( Serial3.available() )
    {
        Serial.write( Serial3.read() );  
    }
 
    // send user input to the BT module
    if ( Serial.available() )
    {
        Serial3.write( Serial.read() );  
    }

}
