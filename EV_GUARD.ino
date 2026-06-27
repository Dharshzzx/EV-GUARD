/*************************************************************
                EV GUARD V2
         ESP32 + Blynk IoT + DHT11
*************************************************************/

#define BLYNK_TEMPLATE_ID "TMPL3ZNDO1rxy"
#define BLYNK_TEMPLATE_NAME "EV GUARD"
#define BLYNK_AUTH_TOKEN "BS5ORnxtzjQS1ZSc7mGcxXx5ekzTvMQv"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

char ssid[] = "DHARSH";
char pass[] = "22222222";

#define GREEN_LED 16
#define YELLOW_LED 17
#define RED1 18
#define RED2 19
#define RELAY 25
#define BUZZER 23

#define POT_PIN 34
#define DHT_PIN 27
#define ZMPT_PIN 35

#define DHTTYPE DHT11

DHT dht(DHT_PIN, DHTTYPE);

BlynkTimer timer;

float voltage = 0;
float current = 0;
float temperature = 0;
float power = 0;

int potValue = 0;
int level = 0;

void sendData()
{
  potValue = analogRead(POT_PIN);
  level = map(potValue,0,4095,0,100);

  temperature = dht.readTemperature();

  if(isnan(temperature))
  {
    temperature = 0;
  }

  voltage = map(analogRead(ZMPT_PIN),0,4095,180,240);

  current = map(level,0,100,0,25);

  power = voltage * current;

  Blynk.virtualWrite(V0,voltage);
  Blynk.virtualWrite(V1,current);
  Blynk.virtualWrite(V2,temperature);
  Blynk.virtualWrite(V3,power);
  if(level <= 20)
  {
    digitalWrite(GREEN_LED,HIGH);
    digitalWrite(YELLOW_LED,LOW);
    digitalWrite(RED1,LOW);
    digitalWrite(RED2,LOW);
    digitalWrite(RELAY,LOW);
    digitalWrite(BUZZER,LOW);

    Blynk.virtualWrite(V4,"System Ready");
    Blynk.virtualWrite(V5,0);
    Blynk.virtualWrite(V6,1);
    Blynk.virtualWrite(V7,0);
    Blynk.virtualWrite(V8,0);
    Blynk.virtualWrite(V9,0);
  }

  else if(level > 20 && level <= 50)
  {
    digitalWrite(GREEN_LED,HIGH);
    digitalWrite(YELLOW_LED,HIGH);
    digitalWrite(RED1,LOW);
    digitalWrite(RED2,LOW);
    digitalWrite(RELAY,HIGH);
    digitalWrite(BUZZER,LOW);

    Blynk.virtualWrite(V4,"Charging");
    Blynk.virtualWrite(V5,1);
    Blynk.virtualWrite(V6,1);
    Blynk.virtualWrite(V7,1);
    Blynk.virtualWrite(V8,0);
    Blynk.virtualWrite(V9,0);
  }

  else if(level > 50 && level <= 80)
  {
    digitalWrite(GREEN_LED,HIGH);
    digitalWrite(YELLOW_LED,LOW);
    digitalWrite(RED1,HIGH);
    digitalWrite(RED2,LOW);
    digitalWrite(RELAY,LOW);

    digitalWrite(BUZZER,HIGH);
    delay(200);
    digitalWrite(BUZZER,LOW);
    delay(200);
    digitalWrite(BUZZER,HIGH);
    delay(200);
    digitalWrite(BUZZER,LOW);

    Blynk.virtualWrite(V4,"Charging Complete");
    Blynk.virtualWrite(V5,0);
    Blynk.virtualWrite(V6,1);
    Blynk.virtualWrite(V7,0);
    Blynk.virtualWrite(V8,1);
    Blynk.virtualWrite(V9,0);
  }

  else
  {
    digitalWrite(GREEN_LED,LOW);
    digitalWrite(YELLOW_LED,LOW);
    digitalWrite(RED1,HIGH);
    digitalWrite(RED2,HIGH);
    digitalWrite(RELAY,LOW);
    digitalWrite(BUZZER,HIGH);

    Blynk.virtualWrite(V4,"Fault Detected");
    Blynk.virtualWrite(V5,0);
    Blynk.virtualWrite(V6,0);
    Blynk.virtualWrite(V7,0);
    Blynk.virtualWrite(V8,0);
    Blynk.virtualWrite(V9,1);
  }
}
void setup()
{
  Serial.begin(115200);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED1, OUTPUT);
  pinMode(RED2, OUTPUT);
  pinMode(RELAY, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED1, LOW);
  digitalWrite(RED2, LOW);
  digitalWrite(RELAY, LOW);
  digitalWrite(BUZZER, LOW);

  dht.begin();

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  timer.setInterval(1000L, sendData);
}

void loop()
{
  Blynk.run();
  timer.run();
}