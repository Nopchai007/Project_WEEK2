#include <Arduino.h>
int L1 = 23;
int L2 = 19;
int L3 = 18;
int L4 = 5;
int L5 = 17;
int L6 = 16;
int L7 = 4;
int L8 = 0;
int potPin = 36;
void setup(){
    pinMode (L1,OUTPUT);
    pinMode (L2,OUTPUT);
    pinMode (L3,OUTPUT);
    pinMode (L4,OUTPUT);
    pinMode (L5,OUTPUT);
    pinMode (L6,OUTPUT);
    pinMode (L7,OUTPUT);
    pinMode (L8,OUTPUT);
}
void loop(){
    int potValue = analogRead(potPin); 
    int range = map(potValue, 0, 4095, 0, 4000); 
    digitalWrite (L1,LOW);
    digitalWrite (L2,LOW);
    digitalWrite (L3,LOW);
    digitalWrite (L4,LOW);
    digitalWrite (L5,LOW);
    digitalWrite (L6,LOW);
    digitalWrite (L7,LOW);
    digitalWrite (L8,LOW);
    if (range >= 0 && range < 500) 
    {
        digitalWrite(L1, HIGH);
    }
    else if (range >= 501 && range < 1000) 
    {
        digitalWrite(L2, HIGH);
    }
    else if (range >= 1001 && range < 1500) 
    {
        digitalWrite(L3, HIGH);
    }
    else if (range >= 1501 && range < 2000) 
    {
        digitalWrite(L4, HIGH);
    }
    else if (range >= 2001 && range < 2500) 
    {
        digitalWrite(L5, HIGH);
    }
    else if (range >= 2501 && range < 3000) 
    {
        digitalWrite(L6, HIGH);
    }
    else if (range >= 3001 && range < 3500) 
    {
        digitalWrite(L7, HIGH);
    }
    else if (range >= 3501 && range <= 4000) 
    {
        digitalWrite(L8, HIGH);
    }

    delay(10); 
}