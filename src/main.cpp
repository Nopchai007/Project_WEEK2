// Library version:1.1.5
// Example of picking custom I2C pins on ESP32

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#define I2C_SDA 21
#define I2C_SCL 22
#define BUTTON_PIN_1 15 // GPIO D15
#define LED_PIN_1 23    // GPIO D23
#define LED_PIN_2 19    // GPIO D19
#define LED_PIN_3 18    // GPIO D18
#define LED_PIN_4 5     // GPIO D5
#define LED_PIN_5 17    // GPIO D17
#define LED_PIN_6 16    // GPIO D16
#define LED_PIN_7 4     // GPIO D4
#define LED_PIN_8 0     // GPIO D0
int menu = 0;
int currentMode = 0; // โหมดปัจจุบัน (0-7)
bool buttonState = false; // สถานะของปุ่ม
bool lastButtonState = false;

LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
    // กำหนด GPIO ให้เป็น Input พร้อม PULLUP
    pinMode(BUTTON_PIN_1, INPUT_PULLUP);
    pinMode(LED_PIN_1, OUTPUT);
    pinMode(LED_PIN_2, OUTPUT);
    pinMode(LED_PIN_3, OUTPUT);
    pinMode(LED_PIN_4, OUTPUT);
    pinMode(LED_PIN_5, OUTPUT);
    pinMode(LED_PIN_6, OUTPUT);
    pinMode(LED_PIN_7, OUTPUT);
    pinMode(LED_PIN_8, OUTPUT);
    digitalWrite(LED_PIN_1, LOW);
        digitalWrite(LED_PIN_2, LOW);
        digitalWrite(LED_PIN_3, LOW);
        digitalWrite(LED_PIN_4, LOW);
        digitalWrite(LED_PIN_5, LOW);
        digitalWrite(LED_PIN_6, LOW);
        digitalWrite(LED_PIN_7, LOW);
        digitalWrite(LED_PIN_8, LOW);

    // เริ่มต้นการเชื่อมต่อ Serial เพื่อแสดงผล
    Serial.begin(115200);
}

void loop()
{
    buttonState = digitalRead(BUTTON_PIN_1) == LOW;

    if (buttonState && !lastButtonState) {
    currentMode++; // เพิ่มโหมด
    if (currentMode > 7) {
      currentMode = 0; // วนกลับไปที่โหมด 0 เมื่อเกิน 7
    }
    updateLEDs(); // อัปเดตสถานะ LED ตามโหมดปัจจุบัน
  }

  lastButtonState = buttonState; // อัปเดตสถานะปุ่มก่อนหน้า
}

    void updateLEDs() {
  // ปิด LED ทั้งหมดก่อน
  for (int i = 0; i < 8; i++) {
    digitalWrite(LED_PIN_1, LOW);
        digitalWrite(LED_PIN_2, LOW);
        digitalWrite(LED_PIN_3, LOW);
        digitalWrite(LED_PIN_4, LOW);
        digitalWrite(LED_PIN_5, LOW);
        digitalWrite(LED_PIN_6, LOW);
        digitalWrite(LED_PIN_7, LOW);
        digitalWrite(LED_PIN_8, LOW);
  }

  // โหมดต่าง ๆ
  switch (currentMode) {
    case 0:
      for (int i = 0; i < 8; i++) {
        digitalWrite(LED_PIN_1, HIGH);
        digitalWrite(LED_PIN_2, HIGH);
        digitalWrite(LED_PIN_3, HIGH);
        digitalWrite(LED_PIN_4, HIGH);
        digitalWrite(LED_PIN_5, HIGH);
        digitalWrite(LED_PIN_6, HIGH);
        digitalWrite(LED_PIN_7, HIGH);
        digitalWrite(LED_PIN_8, HIGH);
      }
      break;

    case 1:
      for (int i = 7; i >= 0; i--) {
        digitalWrite(LED_PIN_2, HIGH);
        digitalWrite(LED_PIN_4, HIGH);
        digitalWrite(LED_PIN_6, HIGH);
        digitalWrite(LED_PIN_8, HIGH);
        digitalWrite(LED_PIN_1, LOW);
        digitalWrite(LED_PIN_3, LOW);
        digitalWrite(LED_PIN_5, LOW);
        digitalWrite(LED_PIN_7, LOW);
        delay(500);
        digitalWrite(LED_PIN_2, LOW);
        digitalWrite(LED_PIN_4, LOW);
        digitalWrite(LED_PIN_6, LOW);
        digitalWrite(LED_PIN_8, LOW);
        digitalWrite(LED_PIN_1, HIGH);
        digitalWrite(LED_PIN_3, HIGH);
        digitalWrite(LED_PIN_5, HIGH);
        digitalWrite(LED_PIN_7, HIGH);
        delay(500);
      }
      break;

    case 2:
      // หลอดติดดับสลับกัน (คู่คี่)
      for (int i = 0; i < 8; i += 2) {
        digitalWrite(LED_PIN_1, HIGH);
    digitalWrite(LED_PIN_8,LOW);
   delay(500);
   digitalWrite(LED_PIN_1, LOW);
   digitalWrite(LED_PIN_2, HIGH);
delay(500);
digitalWrite(LED_PIN_1, LOW);
   digitalWrite(LED_PIN_2,LOW);
   digitalWrite(LED_PIN_3,HIGH);
delay(500);
digitalWrite(LED_PIN_1, LOW);
   digitalWrite(LED_PIN_2,LOW);
   digitalWrite(LED_PIN_3,LOW);
   digitalWrite(LED_PIN_4,HIGH);
delay(500);
digitalWrite(LED_PIN_1, LOW);
   digitalWrite(LED_PIN_2,LOW);
   digitalWrite(LED_PIN_3,LOW);
   digitalWrite(LED_PIN_4,LOW);
   digitalWrite(LED_PIN_5,HIGH);
delay(500);
           digitalWrite(LED_PIN_1, LOW);
   digitalWrite(LED_PIN_2,LOW);
   digitalWrite(LED_PIN_3,LOW);
   digitalWrite(LED_PIN_4,LOW);
   digitalWrite(LED_PIN_5,LOW);
   digitalWrite(LED_PIN_6,HIGH);
delay(500);
 digitalWrite(LED_PIN_1, LOW);
   digitalWrite(LED_PIN_2,LOW);
   digitalWrite(LED_PIN_3,LOW);
   digitalWrite(LED_PIN_4,LOW);
   digitalWrite(LED_PIN_5,LOW);
   digitalWrite(LED_PIN_6,LOW);
   digitalWrite(LED_PIN_7,HIGH);
delay(500);
 digitalWrite(LED_PIN_1, LOW);
   digitalWrite(LED_PIN_2,LOW);
   digitalWrite(LED_PIN_3,LOW);
   digitalWrite(LED_PIN_4,LOW);
   digitalWrite(LED_PIN_5,LOW);
   digitalWrite(LED_PIN_6,LOW);
   digitalWrite(LED_PIN_7,LOW);
   digitalWrite(LED_PIN_8,HIGH);
delay(500);
      break;

    case 3:
      // หลอดทุกหลอดติดพร้อมกัน
      for (int i = 0; i < 8; i++) {

      }
      break;

    case 4:
      // หลอดทุกหลอดดับ
      for (int i = 0; i < 8; i++) {
      }
      break;

    case 5:
      // หลอดกระพริบพร้อมกัน
      for (int i = 0; i < 8; i++) {
        
      }
      delay(500);
      for (int i = 0; i < 8; i++) {
       
      }
      delay(500);
      break;

    case 6:
      // หลอดติดแบบวิ่งไปกลับ
      for (int i = 0; i < 8; i++) {
       
      }
      for (int i = 7; i >= 0; i--) {
       
      }
      break;

    case 7:
      // หลอดติดทีละสองหลอด
      for (int i = 0; i < 8; i += 2) {
       
      }
      break;
  }
}