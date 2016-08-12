#include <AuthClient.h>
#include <MicroGear.h>
#include <MQTTClient.h>
#include <SHA1.h>
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <EEPROM.h>

const char* ssid     = "NARD_IOT";
const char* password = "00000000";

#define APPID       "NarinSmartHome"
#define KEY         "86Kub3Rqd1aDQJY"
#define SECRET      "wdkQ7WzQO00ZZYBal4SrfAQuo"
#define ALIAS       "robotcar"


#define motorspeed    500
#define l_trim        1.00
#define r_trim        1.00

WiFiClient client;
AuthClient *authclient;
MicroGear microgear(client);

void onMsghandler(char *topic, uint8_t* msg, unsigned int msglen) 
{
  Serial.print("Incoming message --> ");
  Serial.print(topic);
  Serial.print(" : ");
  char strState[msglen];
  
  for (int i = 0; i < msglen; i++) 
  {
    strState[i] = (char)msg[i];
    Serial.print((char)msg[i]);
  }
  Serial.println();

  String stateStr = String(strState).substring(0, msglen);
  
    if (stateStr == "F") 
    {   
      analogWrite(D1, motorspeed*l_trim);
      analogWrite(D2, motorspeed*r_trim);
      digitalWrite(D3, HIGH);
      digitalWrite(D4, HIGH); 
      delay(250);
      analogWrite(D1, 0);
      analogWrite(D2, 0);
    }
    if (stateStr == "B")
    {
      analogWrite(D1, motorspeed*l_trim);
      analogWrite(D2, motorspeed*r_trim);
      digitalWrite(D3, LOW);
      digitalWrite(D4, LOW); 
      delay(250);
      analogWrite(D1, 0);
      analogWrite(D2, 0);
    }
    if (stateStr == "SL") 
    {
      analogWrite(D1, 0);
      analogWrite(D2, motorspeed*r_trim);
      digitalWrite(D3, LOW);
      digitalWrite(D4, HIGH);  
      delay(250);
      analogWrite(D1, 0);
      analogWrite(D2, 0);
    }
    if (stateStr == "SR")
    {
      analogWrite(D1, motorspeed*l_trim);
      analogWrite(D2, 0);
      digitalWrite(D3, HIGH);
      digitalWrite(D4, LOW); 
      delay(250);
      analogWrite(D1, 0);
      analogWrite(D2, 0);
    }
    if (stateStr == "L")
    {
      analogWrite(D1, motorspeed*l_trim);
      analogWrite(D2, motorspeed*r_trim);
      digitalWrite(D3, LOW);
      digitalWrite(D4, HIGH);  
      delay(250);
      analogWrite(D1, 0);
      analogWrite(D2, 0);
    }
    if (stateStr == "R")
    {
      analogWrite(D1, motorspeed*l_trim);
      analogWrite(D2, motorspeed*r_trim);
      digitalWrite(D3, HIGH);
      digitalWrite(D4, LOW);  
      delay(250);
      analogWrite(D1, 0);
      analogWrite(D2, 0);
    }
    if(stateStr == "ST")
    {
      analogWrite(D1, 0);
      analogWrite(D2, 0);
      digitalWrite(D3, LOW);
      digitalWrite(D4, LOW);  
    }
}

void onConnected(char *attribute, uint8_t* msg, unsigned int msglen) 
{
  Serial.println("Connected to NETPIE...");
}

void setup() 
{
  pinMode(D1, OUTPUT); // D1 PWM MOTOR_LEFT
  pinMode(D2, OUTPUT); // D2 PWM MOTOR_RIGHT
  pinMode(D3, OUTPUT); // D3 DIR MOTOR_LEFT
  pinMode(D4, OUTPUT); // D4 DIR MOTOR_RIGHT
  //analogWriteFreq(50);
  
  Serial.begin(115200);
  Serial.println("Starting...");

  if (WiFi.begin(ssid, password)) 
  {
    while (WiFi.status() != WL_CONNECTED) 
    {
      delay(500);
      Serial.print(".");
    }
  }
  microgear.on(MESSAGE,onMsghandler);
  microgear.on(CONNECTED,onConnected);
  microgear.init(KEY,SECRET,ALIAS);
  microgear.connect(APPID);
}

void loop() 
{
  if (microgear.connected()) 
  {
    microgear.loop();
  } 
  else 
  {
    Serial.println("Connection Lost, Reconnect...");
    microgear.connect(APPID);
  }
}
