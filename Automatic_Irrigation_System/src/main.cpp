//to do: conect the humidity sensor to the arduino (3.3v)and read the data from the sensor
//to do: conect the relay to the arduino and turn on the relay when the humidity is below the threshold (first try with a led)
//to do: conect the relay to the arduino and turn off the relay when the humiity is above the threshold (first try with a led)
//map the 1023 as maximum value of the sensor to 100 as the maximum value of the humidity
//to do: start with a small delay, but, at the finished version, upload it to 30 minutes
//to do: include a buzzer as a warning of the possible malfunction of the sensor
//https://www.amazon.es/Fasizi-capacitivo-resistente-corrosión-detección/dp/B09Z29GNYV/ref=sr_1_21?__mk_es_ES=ÅMÅŽÕÑ&crid=1D8EQ0D76IAWS&dib=eyJ2IjoiMSJ9.9Tw_ew1b_nzEHznbUQqiQILIpV2bUIU1oLi_kbfPexzCucR2VYF17Hoyc6EYQ88ruet4t9JQuNTrOcefB69Q-mjnvXq6S0bOyW0Zkn6JyfRzrbRI86uit3Wjf_1pf9nzDymga3dBwUNh6Q7D5ZPiv4HEv9U-7eWuwTDils3SUWQGcdPgtdv7YE1rZVmKCzvfIKiueGlTo-r11fmtnerWI4_Llq4IjkctqbAxCTkJxsg90rJPV0ttFLVDg356ZT1V-xOW7iDOqZCu3WsOewYZbWEwhxShDyItksr-uoC8PsTzIKFYZpLTDSt54kXos3sz40JHsvW9HB8xSFsxMrcEOXUKsi8BYeGvHj8UK0VvkQMyru_mVgmcQGVxk6-hMUm0ca_1eIg-8_waec52_g-qzyMIQ5ebziDa2GMZkjz8fBwakvAxvSzNGnoW2hc5c6QW.3-XnTWflK9218Hc6BgdoESYzEYSPFHHlxrM618PsxOg&dib_tag=se&keywords=sensor+de+humedad+terrestre+arduino+anticorrosiva&qid=1740563243&sprefix=sensor+de+humedad+terrestre+arduino+anticorrosiva%2Caps%2C100&sr=8-21
#include <Arduino.h>
