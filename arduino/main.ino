#include "DHT.h"
#include "WiFi.h"
#include "ThingSpeak.h"

#define LedBoardPin 2
#define LedLivingPin_1 27
#define LedLivingPin_2 26
#define LedLivingPin_TOP 25

#define LedBedroomPin_1 5
#define LedBedroomPin_2 18
#define LedBedroomPin_TOP 19

#define LedKitchenPin 21
#define LedBathroomPin 22
#define ledFencePin 23
#define DHTPIN 4
#define MQ2 39
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
int sendDelay = 6000;
const char *writeAPIKEY1 = "LH7K1MEFCPZSWTG6";
const char *writeAPIKEY2 = "SAO78WRQE8QGIO2H";
const char *ssid = "Film";
const char *password = "21012546";
unsigned long myChannelNumber1 = 1845410;
unsigned long myChannelNumber2 = 1848263;
WiFiClient client;
int partyMode = 0;
int partyMode2 = 0;

void Wifi_init()
{
    WiFi.begin(ssid, password);
    Serial.println("Connecting to WiFi..");
    while (WiFi.status() != WL_CONNECTED)
    {
        connecting();
    }
    Standby();
    Serial.println("Connected to the WiFi network");
}

// the setup function runs once when you press reset or power the board
void setup()
{
    // LED On board
    pinMode(LedBoardPin, OUTPUT);
    // Liveing Room
    // โคมไฟห้องนั่งเล่น
    pinMode(LedLivingPin_1, OUTPUT);
    pinMode(LedLivingPin_2, OUTPUT);
    // TopLed
    pinMode(LedLivingPin_TOP, OUTPUT);
    // Bedroom
    // โคมไฟหัวเตียง
    pinMode(LedBedroomPin_1, OUTPUT);
    pinMode(LedBedroomPin_2, OUTPUT);
    // TopLed
    pinMode(LedBedroomPin_TOP, OUTPUT);
    // Kitchen
    pinMode(LedKitchenPin, OUTPUT);
    // Bathroom
    pinMode(LedBathroomPin, OUTPUT);
    // Fence
    pinMode(ledFencePin, OUTPUT);
    // DHT11
    pinMode(MQ2, INPUT);
    Serial.begin(115200);
    ThingSpeak.begin(client);
    dht.begin();
    Wifi_init();
}

void loop()
{
    for (int i = 0; i < 10; i++)
    {
        delay(sendDelay);
        Serial.println("Reading data to ThingSpeak...");
        Client_read1();
        Client_read2();
    }
    Client_send1();
    Cliend_send2();
}

void Client_send1()
{
    ThingSpeak.setField(1, digitalRead(LedKitchenPin));
    ThingSpeak.setField(2, digitalRead(LedBathroomPin));
    ThingSpeak.setField(3, digitalRead(LedBedroomPin_TOP));
    ThingSpeak.setField(4, digitalRead(LedBedroomPin_1));
    ThingSpeak.setField(5, digitalRead(LedBedroomPin_2));
    ThingSpeak.setField(6, digitalRead(LedLivingPin_TOP));
    ThingSpeak.setField(7, digitalRead(LedLivingPin_1));
    ThingSpeak.setField(8, digitalRead(LedLivingPin_2));
    int x = ThingSpeak.writeFields(myChannelNumber1, writeAPIKEY1);
    if (x == 200)
    {
        Serial.println("#1 Channel update successful.");
    }
    else
    {
        Serial.println("#1 Problem updating channel. HTTP error code " + String(x));
    }
}

void Cliend_send2()
{
    ThingSpeak.setField(1, digitalRead(ledFencePin));
    ThingSpeak.setField(2, dht.readTemperature());
    ThingSpeak.setField(3, dht.readHumidity());
    ThingSpeak.setField(4, map(analogRead(MQ2), 0, 1023, 0, 100));
    ThingSpeak.setField(5, partyMode);
    ThingSpeak.setField(6, partyMode2);

    int x = ThingSpeak.writeFields(myChannelNumber2, writeAPIKEY2);
    if (x == 200)
    {
        Serial.println("#2 Channel update successful.");
    }
    else
    {
        Serial.println("#2 Problem updating channel. HTTP error code " + String(x));
    }
}

void Client_read1()
{
    int statusCode = ThingSpeak.readMultipleFields(myChannelNumber1, writeAPIKEY1);
    Serial.println("Status code Channal #1 : " + String(statusCode));
    Serial.println("Field 1: " + String(ThingSpeak.getFieldAsInt(1)));
    Serial.println("Field 2: " + String(ThingSpeak.getFieldAsInt(2)));
    Serial.println("Field 3: " + String(ThingSpeak.getFieldAsInt(3)));
    Serial.println("Field 4: " + String(ThingSpeak.getFieldAsInt(4)));
    Serial.println("Field 5: " + String(ThingSpeak.getFieldAsInt(5)));
    Serial.println("Field 6: " + String(ThingSpeak.getFieldAsInt(6)));
    Serial.println("Field 7: " + String(ThingSpeak.getFieldAsInt(7)));
    Serial.println("Field 8: " + String(ThingSpeak.getFieldAsInt(8)));
    Serial.println("======================================================");
    if (statusCode == 200)
    {

        if (int(ThingSpeak.getFieldAsInt(1)) == 0)
        {
            digitalWrite(LedKitchenPin, LOW);
        }
        else
        {
            digitalWrite(LedKitchenPin, HIGH);
        }

        if (int(ThingSpeak.getFieldAsInt(2)) == 0)
        {
            digitalWrite(LedBathroomPin, LOW);
        }
        else
        {
            digitalWrite(LedBathroomPin, HIGH);
        }

        if (int(ThingSpeak.getFieldAsInt(3)) == 0)
        {
            digitalWrite(LedBedroomPin_TOP, LOW);
        }
        else
        {
            digitalWrite(LedBedroomPin_TOP, HIGH);
        }

        if (int(ThingSpeak.getFieldAsInt(4)) == 0)
        {
            digitalWrite(LedBedroomPin_1, LOW);
        }
        else
        {
            digitalWrite(LedBedroomPin_1, HIGH);
        }

        if (int(ThingSpeak.getFieldAsInt(5)) == 0)
        {
            digitalWrite(LedBedroomPin_2, LOW);
        }
        else
        {
            digitalWrite(LedBedroomPin_2, HIGH);
        }

        if (int(ThingSpeak.getFieldAsInt(6)) == 0)
        {
            digitalWrite(LedLivingPin_TOP, LOW);
        }
        else
        {
            digitalWrite(LedLivingPin_TOP, HIGH);
        }
        if (int(ThingSpeak.getFieldAsInt(7)) == 0)
        {
            digitalWrite(LedLivingPin_1, LOW);
        }
        else
        {
            digitalWrite(LedLivingPin_1, HIGH);
        }

        if (int(ThingSpeak.getFieldAsInt(8)) == 0)
        {
            digitalWrite(LedLivingPin_2, LOW);
        }
        else
        {
            digitalWrite(LedLivingPin_2, HIGH);
        }
    }
}

void Client_read2()
{
    int statusCode = ThingSpeak.readMultipleFields(myChannelNumber2, writeAPIKEY2);
    Serial.println("Status code Channal #2: " + String(statusCode));
    if (statusCode == 200)
    {
        Serial.println("Field 1: " + String(ThingSpeak.getFieldAsInt(1)));
        Serial.println("Temperature: " + String(ThingSpeak.getFieldAsFloat(2)) + " C");
        Serial.println("Humidity: " + String(ThingSpeak.getFieldAsFloat(3)) + " %");
        Serial.println("Smoke: " + String(ThingSpeak.getFieldAsFloat(4)) + " %");
        Serial.println("Party Mode: " + String(ThingSpeak.getFieldAsInt(5)));
        Serial.println("Party Mode 2: " + String(ThingSpeak.getFieldAsInt(6)));
        Serial.println("======================================================");
        if (int(ThingSpeak.getFieldAsInt(1)) == 0)
        {
            digitalWrite(ledFencePin, LOW);
        }
        else
        {
            digitalWrite(ledFencePin, HIGH);
        }
        if (int(ThingSpeak.getFieldAsInt(5)) == 0)
        {
            partyMode = 0;
        }
        else
        {
            partyMode = 1;
            partyTime();
        }
        if (int(ThingSpeak.getFieldAsInt(6)) == 0)
        {
            partyMode2 = 0;
        }
        else
        {
            partyMode2 = 1;
            partyTime2();
        }
    }
}

void Standby()
{
    for (int i = 0; i < 2; i++)
    {
        digitalWrite(LedLivingPin_1, HIGH);
        digitalWrite(LedLivingPin_2, HIGH);
        digitalWrite(LedLivingPin_TOP, HIGH);
        digitalWrite(LedBedroomPin_1, HIGH);
        digitalWrite(LedBedroomPin_2, HIGH);
        digitalWrite(LedBedroomPin_TOP, HIGH);
        digitalWrite(LedKitchenPin, HIGH);
        digitalWrite(LedBathroomPin, HIGH);
        digitalWrite(ledFencePin, HIGH);
        delay(250);
        digitalWrite(LedLivingPin_1, LOW);
        digitalWrite(LedLivingPin_2, LOW);
        digitalWrite(LedLivingPin_TOP, LOW);
        digitalWrite(LedBedroomPin_1, LOW);
        digitalWrite(LedBedroomPin_2, LOW);
        digitalWrite(LedBedroomPin_TOP, LOW);
        digitalWrite(LedKitchenPin, LOW);
        digitalWrite(LedBathroomPin, LOW);
        digitalWrite(ledFencePin, LOW);
        delay(250);
    }
}

void connecting()
{
    digitalWrite(LedLivingPin_1, HIGH);
    delay(50);
    digitalWrite(LedLivingPin_1, LOW);
    delay(50);
    digitalWrite(LedLivingPin_2, HIGH);
    delay(50);
    digitalWrite(LedLivingPin_2, LOW);
    delay(50);
    digitalWrite(LedLivingPin_TOP, HIGH);
    delay(50);
    digitalWrite(LedLivingPin_TOP, LOW);
    delay(50);
    digitalWrite(LedBedroomPin_1, HIGH);
    delay(50);
    digitalWrite(LedBedroomPin_1, LOW);
    delay(50);
    digitalWrite(LedBedroomPin_2, HIGH);
    delay(50);
    digitalWrite(LedBedroomPin_2, LOW);
    delay(50);
    digitalWrite(LedBedroomPin_TOP, HIGH);
    delay(50);
    digitalWrite(LedBedroomPin_TOP, LOW);
    delay(50);
    digitalWrite(LedKitchenPin, HIGH);
    delay(50);
    digitalWrite(LedKitchenPin, LOW);
    delay(50);
    digitalWrite(LedBathroomPin, HIGH);
    delay(50);
    digitalWrite(LedBathroomPin, LOW);
    delay(50);
    digitalWrite(ledFencePin, HIGH);
    delay(50);
    digitalWrite(ledFencePin, LOW);
    delay(50);
}

void partyTime()
{
    if (partyMode == 1)
    {
        for (int i = 0; i < 20; i++)
        {
            digitalWrite(LedLivingPin_1, HIGH);
            digitalWrite(LedLivingPin_2, HIGH);
            digitalWrite(LedLivingPin_TOP, HIGH);
            digitalWrite(LedBedroomPin_1, HIGH);
            digitalWrite(LedBedroomPin_2, HIGH);
            digitalWrite(LedBedroomPin_TOP, HIGH);
            digitalWrite(LedKitchenPin, HIGH);
            digitalWrite(LedBathroomPin, HIGH);
            digitalWrite(ledFencePin, HIGH);
            delay(250);
            digitalWrite(LedLivingPin_1, LOW);
            digitalWrite(LedLivingPin_2, LOW);
            digitalWrite(LedLivingPin_TOP, LOW);
            digitalWrite(LedBedroomPin_1, LOW);
            digitalWrite(LedBedroomPin_2, LOW);
            digitalWrite(LedBedroomPin_TOP, LOW);
            digitalWrite(LedKitchenPin, LOW);
            digitalWrite(LedBathroomPin, LOW);
            digitalWrite(ledFencePin, LOW);
            delay(250);
        }
        Client_read2();
    }
}

void partyTime2()
{
    if (partyMode2 == 1)
    {
        for (int i = 0; i < 20; i++)
        {
            digitalWrite(LedLivingPin_1, HIGH);
            delay(50);
            digitalWrite(LedLivingPin_1, LOW);
            delay(50);
            digitalWrite(LedLivingPin_2, HIGH);
            delay(50);
            digitalWrite(LedLivingPin_2, LOW);
            delay(50);
            digitalWrite(LedLivingPin_TOP, HIGH);
            delay(50);
            digitalWrite(LedLivingPin_TOP, LOW);
            delay(50);
            digitalWrite(LedBedroomPin_1, HIGH);
            delay(50);
            digitalWrite(LedBedroomPin_1, LOW);
            delay(50);
            digitalWrite(LedBedroomPin_2, HIGH);
            delay(50);
            digitalWrite(LedBedroomPin_2, LOW);
            delay(50);
            digitalWrite(LedBedroomPin_TOP, HIGH);
            delay(50);
            digitalWrite(LedBedroomPin_TOP, LOW);
            delay(50);
            digitalWrite(LedKitchenPin, HIGH);
            delay(50);
            digitalWrite(LedKitchenPin, LOW);
            delay(50);
            digitalWrite(LedBathroomPin, HIGH);
            delay(50);
            digitalWrite(LedBathroomPin, LOW);
            delay(50);
            digitalWrite(ledFencePin, HIGH);
            delay(50);
            digitalWrite(ledFencePin, LOW);
            delay(50);
        }
        Client_read2();
    }
}