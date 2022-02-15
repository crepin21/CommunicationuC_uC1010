/*
  Titre      : Communication_2uC
  Auteur     : Crepin Vardin Fouelefack
  Date       : 11/02/2022
  Description: Controle de l'intensite d'une led placee sur le uC1010 grace a un potentiometre sur le uC1000
  Version    : 0.0.1
*/

#include <Arduino.h>
#include "WIFI_NINA_Connector.h"
#include "MQTTConnector.h"
#include <Wire.h>


const int DIGITAL2_LED          = 2;     // Broche pour la led

int Intensite = 0;
void receiveEvent(int bytes);

void setup() {
  //Serial.begin(9600);
  pinMode(DIGITAL2_LED, OUTPUT);
  // Start the I2C Bus as Slave on address 9
  Wire.begin(9); 
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
}
void receiveEvent(int bytes){
  Intensite = Wire.read();    // read one character from the I2C
}

void loop() {
  
  analogWrite(DIGITAL2_LED, Intensite);

  }

  /*appendPayload("CapteurRotation", sensorValue);  //Ajout de la valeur de la position du Capteur de rotation au message MQTT
    appendPayload("PosServoMoteur", pos);  //Ajout de la valeur de la position du servomoteur au message MQTT

    sendPayload();                                   //Envoie du message via le protocole MQTT

   */

