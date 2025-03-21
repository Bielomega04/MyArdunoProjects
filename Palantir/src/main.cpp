#include <Arduino.h>
#include <IRremote.h>

#define RED 5   // actualy blue
#define GREEN 6 // actualy green
#define BLUE 9  // actualy red
#define IR_PIN 3

#define KEY_1  0XF30CFF00
#define KEY_2  0XE718FF00
#define KEY_4  0xF708FF00
#define KEY_5  0XE31CFF00
const int DELAY = 10;
const int DELAY2 = 5000;
int v_red = random(0, 255), v_green = random(0, 255), v_blue = random(0, 255);
unsigned long lastCall, waitTime = 2000;
bool modoFijo = false;

IRrecv irrecv(IR_PIN);
decode_results results; 
//----------------------------------------------
void viewRemoteValues();
void testLED();
void neutralColor(int &v_red, int &v_blue, int &v_green);
void changeColor(int &v_red, int &v_green, int &v_blue, int v_red_f, int v_green_f, int v_blue_f);
void colorElf(int &v_red, int &v_green, int &v_blue);
void colorHobbit(int &v_red, int &v_green, int &v_blue);
void colorDwarf(int &v_red, int &v_green, int &v_blue);
void colorMagician(int &v_red, int &v_green, int &v_blue);
//----------------------------------------------
void setup()
{
    Serial.begin(9600);
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);
    irrecv.enableIRIn();
    testLED();
}
void loop()
{
    if (irrecv.decode(&results)) 
    {
        unsigned long codigo = results.value; 
        irrecv.resume(); 

        if (codigo != 0xFFFFFFFF) 
        {                        // Evita repeticiones del mando
            lastCall = millis(); // Reinicia el temporizador
            modoFijo = true;     // Fija el color seleccionado
            Serial.print("Código recibido: ");
            Serial.println(codigo, HEX);

            switch (codigo) 
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
                colorMagician(v_red, v_green, v_blue);
                break;
            default:
                Serial.println("Código desconocido");
                break;
            }
            Serial.println("Fin de la secuencia");
        }
    }
    if (millis() - lastCall > waitTime) 
    {
        if(modoFijo){
            Serial.println("Fin del modo fijo");   
        }
        modoFijo = false; // Vuelve al modo aleatorio
        neutralColor(v_red, v_green, v_blue);
    }
    delay(10);
}

//----------------------------------------------
void colorElf(int &v_red, int &v_green, int &v_blue)
{
    int v_red_f = 0, v_green_f = 255, v_blue_f = 0;
    changeColor(v_red, v_green, v_blue, v_red_f, v_green_f, v_blue_f);
    Serial.println("Elf");
    delay(DELAY2);
}
//----------------------------------------------
void colorHobbit(int &v_red, int &v_green, int &v_blue)
{
    int v_red_f = 255, v_green_f = 255, v_blue_f = 0;
    changeColor(v_red, v_green, v_blue, v_red_f, v_green_f, v_blue_f);
    Serial.println("Hobbit");
    delay(DELAY2);
}
//----------------------------------------------
void colorDwarf(int &v_red, int &v_green, int &v_blue)
{
    int v_red_f = 255, v_green_f = 0, v_blue_f = 0;
    changeColor(v_red, v_green, v_blue, v_red_f, v_green_f, v_blue_f);
    Serial.println("Dwarf");
    delay(DELAY2);
}
//----------------------------------------------
void colorMagician(int &v_red, int &v_green, int &v_blue)
{
    int v_red_f = 64, v_green_f = 224, v_blue_f = 208;
    changeColor(v_red, v_green, v_blue, v_red_f, v_green_f, v_blue_f);
    Serial.println("Magician");
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
    int v_red_f = random(0, 255), v_green_f = random(0, 255), v_blue_f = random(0, 255);
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
    if (v_red_f > v_red)
    {
        for (int i = v_red; i <= v_red_f; i++)
        {
            analogWrite(RED, i);
            delay(DELAY);
        }
    }
    else
    {
        for (int i = v_red; i >= v_red_f; i--)
        {
            analogWrite(RED, i);
            delay(DELAY);
        }
    }
    if (v_green_f > v_green)
    {
        for (int i = v_green; i <= v_green_f; i++)
        {
            analogWrite(GREEN, i);
            delay(DELAY);
        }
    }
    else
    {
        for (int i = v_green; i >= v_green_f; i--)
        {
            analogWrite(GREEN, i);
            delay(DELAY);
        }
    }
    if (v_blue_f > v_blue)
    {
        for (int i = v_blue; i <= v_blue_f; i++)
        {
            analogWrite(BLUE, i);
            delay(DELAY);
        }
    }
    else
    {
        for (int i = v_blue; i >= v_blue_f; i--)
        {
            analogWrite(BLUE, i);
            delay(DELAY);
        }
    }
    v_red = v_red_f;
    v_green = v_green_f;
    v_blue = v_blue_f;
}