//to do: conect the humidity sensor to the arduino (3.3v)and read the data from the sensor
//to do: conect the relay to the arduino and turn on the relay when the humidity is below the threshold (first try with a led)
//to do: conect the relay to the arduino and turn off the relay when the humiity is above the threshold (first try with a led)
//map the 1023 as maximum value of the sensor to 100 as the maximum value of the humidity
//to do: start with a small delay, but, at the finished version, upload it to 30 minutes
//to do: include a buzzer as a warning of the possible malfunction of the sensor
//to do: program an external temperature and humidity sensor to mesure the temperature and humidity of the plants when the external temperature is higher than 30ºC (for example)
//https://es.aliexpress.com/item/1005005202930632.html?spm=a2g0o.productlist.main.1.2290w97Hw97H9w&algo_pvid=ed075e5d-4831-4b1a-9862-c96309d9f1a3&algo_exp_id=ed075e5d-4831-4b1a-9862-c96309d9f1a3-0&pdp_ext_f=%7B"order"%3A"833"%2C"eval"%3A"1"%7D&pdp_npi=4%40dis%21EUR%210.92%210.92%21%21%210.98%210.98%21%402103917f17418589372296721e5fef%2112000032137327855%21sea%21ES%
#include <Arduino.h>
#define HumiditySensor A0
#define IrrigationRelay 13
#define Buzzer 12
#define HumidityThreshold 50

void seup(){
    Serial.begin(9600);
    pinMode(HumiditySensor, INPUT);
    pinMode(IrrigationRelay, OUTPUT);
    pinMode(Buzzer, OUTPUT);
}