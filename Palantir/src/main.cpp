#include <Arduino.h>
#include <IRremote.h>

#define RED 5   // actualy blue
#define GREEN 6 // actualy green
#define BLUE 9  // actualy red
#define IR_PIN 3

#define KEY_1 0XF30CFF00
#define KEY_2 0XE718FF00
#define KEY_4 0xF708FF00
#define KEY_5 0XE31CFF00
const int DELAY = 25;
const int DELAY2 = 5000;
int v_red = random(0, 255), v_green = random(0, 255), v_blue = random(0, 255);
unsigned long waitTime = 2000;
unsigned long lastCall = 0;
unsigned long time;
unsigned long key_pressed = 0;

IRrecv irrecv(IR_PIN);
decode_results results;
//----------------------------------------------
void viewRemoteValues();
void testLED();
void neutralColor(int &v_red, int &v_blue, int &v_green);
void randomNeutralColor(int &v_red, int &v_blue, int &v_green);
void changeColor(int &v_red, int &v_green, int &v_blue, int v_red_f, int v_green_f, int v_blue_f);
void changeColor(int &initialColor, int finalColor, int PIN);
void colorElf(int &v_red, int &v_green, int &v_blue);
void colorHobbit(int &v_red, int &v_green, int &v_blue);
void colorDwarf(int &v_red, int &v_green, int &v_blue);
void colorHuman(int &v_red, int &v_green, int &v_blue);
void readIRRemote();
//----------------------------------------------
void setup()
{
    Serial.begin(9600);
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);
    irrecv.enableIRIn();
    testLED();
    time = millis();
}

void loop()
{
    time = millis();
    if (time % waitTime == 0)
    {
        neutralColor(v_red, v_green, v_blue);
        //randomNeutralColor(v_red, v_green, v_blue);
    }
    else
    {
        readIRRemote();
    }
}

//----------------------------------------------
void randomNeutralColor(int &v_red, int &v_green, int &v_blue)
{
    int v_red_f = random(0, 255), v_green_f = random(0, 255), v_blue_f = random(0, 255);
    changeColor(v_red, v_green, v_blue, v_red_f, v_green_f, v_blue_f);
}
//----------------------------------------------
void colorElf(int &v_red, int &v_green, int &v_blue)
{
    int v_red_f = 0, v_green_f = 255, v_blue_f = 0; // green
    changeColor(v_red, v_green, v_blue, v_red_f, v_green_f, v_blue_f);
    delay(DELAY2);
}
//----------------------------------------------
void colorHobbit(int &v_red, int &v_green, int &v_blue)
{
    int v_red_f = 255, v_green_f = 100, v_blue_f = 0; // yellow
    changeColor(v_red, v_green, v_blue, v_red_f, v_green_f, v_blue_f);
    delay(DELAY2);
}
//----------------------------------------------
void colorDwarf(int &v_red, int &v_green, int &v_blue)
{
    int v_red_f = 255, v_green_f = 0, v_blue_f = 0; // red
    changeColor(v_red, v_green, v_blue, v_red_f, v_green_f, v_blue_f);
    delay(DELAY2);
}
//----------------------------------------------
void colorHuman(int &v_red, int &v_green, int &v_blue)
{
    int v_red_f = 25, v_green_f = 49, v_blue_f = 120; // blue
    changeColor(v_red, v_green, v_blue, v_red_f, v_green_f, v_blue_f);
    delay(DELAY2);
}
//----------------------------------------------
void viewRemoteValues()
{
    if (IrReceiver.decode())
    {
        Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); // Print the received code
        IrReceiver.resume();                                          // Receive the next value
    }
    delay(100);
}
//----------------------------------------------
void neutralColor(int &v_red, int &v_blue, int &v_green)
{
    int v_red_f, v_green_f, v_blue_f, color_num;

    color_num = random(1, 6);
    switch (color_num)
    {
    case 1: // light cian
        v_red_f = 0;
        v_green_f = 255;
        v_blue_f = 255;
        Serial.println("Cian");
        break;

    case 2: // magenta
        v_red_f = 255;
        v_green_f = 0;
        v_blue_f = 255;
        Serial.println("magenta");
        break;

    case 3: // pink
        v_red_f = 255;
        v_green_f = 153;
        v_blue_f = 204;
        Serial.println("pink");
        break;

    case 4: // dark violet
        v_red_f = 128;
        v_green_f = 0;
        v_blue_f = 128;
        Serial.println("dark violet");
        break;

    case 5: // white
        v_red_f = 255;
        v_green_f = 255;
        v_blue_f = 255;
        Serial.println("white");
        break;

    case 6: // olive green
        v_red_f = 128;
        v_blue_f = 128;
        v_red_f = 0;
        Serial.println("olive green");
        break;
    }
    changeColor(v_red, v_green, v_blue, v_red_f, v_green_f, v_blue_f);
}
//----------------------------------------------
void testLED()
{
    for (int i = 0; i <= 255; i++)
    {
        analogWrite(RED, i);
        delay(1);
    }
    for (int i = 255; i >= 0; i--)
    {
        analogWrite(RED, i);
        delay(1);
    }
    for (int i = 0; i <= 255; i++)
    {
        analogWrite(GREEN, i);
        delay(1);
    }
    for (int i = 255; i >= 0; i--)
    {
        analogWrite(GREEN, i);
        delay(1);
    }
    for (int i = 0; i <= 255; i++)
    {
        analogWrite(BLUE, i);
        delay(1);
    }
    for (int i = 255; i >= 0; i--)
    {
        analogWrite(BLUE, i);
        delay(1);
    }
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
}
//----------------------------------------------
void changeColor(int &v_red, int &v_green, int &v_blue, int v_red_f, int v_green_f, int v_blue_f)
{
    changeColor(v_red, v_red_f, RED);
    changeColor(v_blue, v_blue_f, BLUE);
    changeColor(v_green, v_green_f, GREEN);
}
//----------------------------------------------
void readIRRemote()
{
    if (irrecv.decode())
    {
        key_pressed = irrecv.decodedIRData.decodedRawData;
        switch (key_pressed)
        {
        case KEY_1:
            colorElf(v_red, v_green, v_blue);
            break;
        case KEY_2:
            colorHobbit(v_red, v_green, v_blue);
            break;
        case KEY_4:
            colorDwarf(v_red, v_green, v_blue);
            break;
        case KEY_5:
            colorHuman(v_red, v_green, v_blue);
            break;
        default:
            viewRemoteValues();
            break;
        }
        irrecv.resume();
        key_pressed = 0;
    }
}
//----------------------------------------------
void changeColor(int &initialColor, int finalColor, int PIN)
{
    if (initialColor < finalColor)
    {
        for (int i = initialColor; i <= finalColor; i++)
        {
            analogWrite(PIN, i);
            delay(DELAY);
        }
    }
    else
    {
        for (int i = initialColor; i >= finalColor; i--)
        {
            analogWrite(PIN, i);
            delay(DELAY);
        }
    }
    initialColor = finalColor;
}
