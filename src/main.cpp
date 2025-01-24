#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#define I2C_SDA 21
#define I2C_SCL 22
int ButtonPin = 35;
int ButtonPin1 = 33;
int ButtonPin2 = 2;
int ButtonPin3 = 34;

int P2Pin = 39;
int ledBrightness = 0;
const int thresholdLow = 100;  // ช่วงค่าต่ำสุด
const int thresholdHigh = 3995;

int P3Pin = 12;
int P1Pin = 36;

// ตัวแปรสำหรับเก็บสถานะของปุ่ม
bool button1State = false; // สถานะของปุ่มกดตัวที่ 1
bool button2State = false; // สถานะของปุ่มกดตัวที่ 2



int LedPin[] = {23, 19, 18, 5, 17, 16, 4, 0,}; 

int ledPin0 = 23;
int ledPin1 = 19;
int ledPin2 = 18;
int ledPin3 = 5;
int ledPin4 = 17;
int ledPin5 = 16;
int ledPin6 = 4;
int ledPin7 = 0;

LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup(){

pinMode(ledPin2, OUTPUT); // ตั้ง LED เป็น output

pinMode(ButtonPin2, INPUT_PULLUP); // ตั้งปุ่มกดตัวที่ 1 เป็น input พร้อมเปิด pull-up resistor
pinMode(ButtonPin3, INPUT_PULLUP);// ตั้งปุ่มกดตัวที่ 2 เป็น input พร้อมเปิด pull-up resistor
pinMode(ledPin0, OUTPUT);  // ตั้ง LED เป็น output
pinMode(ledPin3, OUTPUT);  // ตั้ง LED เป็น output

    for (int i = 0; i < 8; i++) {
    pinMode(LedPin[i], OUTPUT);
  }
  pinMode(ButtonPin, INPUT_PULLUP);
  pinMode(ButtonPin1, INPUT_PULLUP);
 lcd.init(I2C_SDA, I2C_SCL); // initialize the lcd to use user defined I2C pins
 lcd.backlight();
 lcd.setCursor(0,0);
 lcd.print("Menu: 0");
 delay(500);
Serial.begin(9600);
}


void loop(){
  static int menu = 0;  // ตัวแปรเก็บเมนูที่เลือก
  int switchState = digitalRead(ButtonPin); 
  int switchState1 = digitalRead(ButtonPin1);
  

  int potValue = analogRead(P2Pin);
  int potValue1 = analogRead(P3Pin);
  int potValue2 = analogRead(P1Pin);
  ledBrightness = map(potValue, 0, 4095, 0, 255);
  potValue = analogRead(P2Pin);
  potValue1 = analogRead(P3Pin);
  potValue2 = analogRead(P1Pin);
  
  
    
    if (switchState == HIGH) {
    delay(300);  // ให้เวลา Debouncing ให้สวิตช์มีเวลาหยุดสักนิด

    // เปลี่ยนเมนูที่เลือก
    menu = (menu % 6) + 1;  // สลับเมนูจาก 1-3
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Menu: ");
    lcd.print(menu);  // แสดงเมนูที่เลือก
    delay(500);  // ให้เวลาสำหรับแสดงผลบนจอ LCD
    }

    else if (switchState1 == HIGH)
    {
    delay(300);  // ให้เวลา Debouncing ให้สวิตช์มีเวลาหยุดสักนิด
    menu = (menu % 6) + 1;  // สลับเมนูจาก 1-3
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Menu: ");
    lcd.print(menu);  // แสดงเมนูที่เลือก
    delay(500);  // ให้เวลาสำหรับแสดงผลบนจอ LCD
    }
    
    bool button1State = digitalRead(ButtonPin2) == LOW; // LOW = ปุ่มถูกกด
    bool button2State = digitalRead(ButtonPin3) == LOW;

    
    // ใช้ switch-case เพื่อจัดการการเลือกเมนู
    switch (menu) {
      case 1:
    digitalWrite(ledPin5, HIGH);
    delay(200);
    digitalWrite(ledPin5, LOW);
    delay(200);

    }
    switch (menu) {
      case 2:
    if (ButtonPin1)
    {
      digitalWrite(ledPin4, HIGH);  // ใส่ if ก่อนและ อันนี้แก้ให้หลอดไฟติดสลับแล้ว
    digitalWrite(ledPin6, LOW);
    delay(500);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin6, HIGH);
    delay(500);
    }
    else(menu ,3);
    {
    digitalWrite(ledPin6, LOW);
    }
    
    }

    switch (menu) {
      case 3:
    if (potValue <= thresholdLow || potValue >= thresholdHigh) {
    ledBrightness = 0; // LED ดับ
  } 
  else {
    // แปลงค่า 0-4095 ให้เป็นช่วง 0-255 สำหรับควบคุม PWM
    ledBrightness = map(potValue, thresholdLow, thresholdHigh, 0, 255);
  }

   analogWrite(ledPin2, ledBrightness);
    delay(100);  
    
    }

    switch (menu) {
      case 4:
    if (potValue1 >= 2120)
    {
    digitalWrite(ledPin3, HIGH);
    delay(10);
  }
  else (potValue1 < 2120); //แก้ไข เมื่อน้อยกว่า1.8v ให้หลอดled ดับ
    {
      digitalWrite(ledPin3, LOW);
    delay(10);
    }
  
  }
  switch (menu) {
      case 5:
    if (button1State && button2State) 
    {
    digitalWrite(ledPin0, LOW);
    digitalWrite(ledPin3, LOW);
    delay(50);    
  } 
  else 
  {
    digitalWrite(ledPin0, LOW);  // แก้ ติดดับสลับกัน
    digitalWrite(ledPin3, HIGH); 
    delay(500);                 
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin0, HIGH);  
    delay(500);                 
  }
 }
 
 switch (menu) {
      case 6:
    if (potValue2 > 256)
    {
    digitalWrite(ledPin5, HIGH);
    delay(10);
  }
  else if (potValue2 < 256)
  {
    digitalWrite(ledPin5, LOW);
    delay(10);
  }
  
 
 }
}