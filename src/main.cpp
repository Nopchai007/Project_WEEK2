#include <Arduino.h>

// กำหนดขา GPIO สำหรับแยกไฟจราจร 1
int red1 = 23;    // ไฟแดงแยกที่ 1
int yellow1 = 19; // ไฟเหลืองแยกที่ 1
int green1 = 18;  // ไฟเขียวแยกที่ 1

// กำหนดขา GPIO สำหรับแยกไฟจราจร 2
int red2 = 17;   // ไฟแดงแยกที่ 2
int yellow2 = 16;// ไฟเหลืองแยกที่ 2
int green2 = 4; // ไฟเขียวแยกที่ 2
int dum = 0; 
int led5 = 5;
// กำหนดขา GPIO สำหรับปุ่ม
int buttonPin = 15; // ปุ่มสำหรับสลับโหมดไฟกระพริบ
bool blinkingMode = false; // ตัวแปรสำหรับเก็บสถานะโหมดไฟกระพริบ
int buttonState = 0; // ตัวแปรสำหรับเก็บสถานะของปุ่ม

void setup() {  
  // ตั้งค่าให้ GPIO เป็น OUTPUT สำหรับไฟ
  pinMode(red1, OUTPUT);
  pinMode(yellow1, OUTPUT);
  pinMode(green1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(yellow2, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(dum, OUTPUT);
  pinMode(led5, OUTPUT);
  
  // ตั้งค่าให้ GPIO เป็น INPUT สำหรับปุ่ม
  pinMode(buttonPin, INPUT_PULLUP);

  // เริ่มต้นการเชื่อมต่อ Serial Monitor
  Serial.begin(115200);
  Serial.println("System Started");
}

void loop() {
  // อ่านสถานะของปุ่ม
  buttonState = digitalRead(buttonPin);
  
  // ถ้ากดปุ่ม (ปุ่มจะเป็น LOW เมื่อกด) สลับโหมดไฟกระพริบ
  if (buttonState == HIGH) {
    blinkingMode = !blinkingMode;  // สลับสถานะโหมด
    delay(200); // หน่วงเวลาหลังการกดปุ่ม เพื่อป้องกันการกดซ้ำ
    if (blinkingMode) {
      Serial.println("Blinking mode activated");
    } else {
      Serial.println("Blinking mode deactivated");
    }
  }

  // ถ้าอยู่ในโหมดไฟกระพริบ
  if (blinkingMode) {
    // กระพริบไฟแดงและไฟเขียวทั้งสองแยก
    digitalWrite(red1, HIGH);
    digitalWrite(green1, HIGH);
    digitalWrite(yellow1, HIGH);
    digitalWrite(red2, HIGH);
    digitalWrite(green2, HIGH);
    digitalWrite(yellow2, HIGH);
    digitalWrite(dum, HIGH);
    digitalWrite(led5, HIGH);
    delay(500); // หน่วงเวลา 500 มิลลิวินาที (ไฟกระพริบ)
    digitalWrite(red1, LOW);
    digitalWrite(green1, LOW);
    digitalWrite(yellow1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(green2, LOW);
    digitalWrite(yellow2, LOW);
    digitalWrite(dum, LOW);
    digitalWrite(led5, LOW);
    delay(500); // หน่วงเวลา 500 มิลลิวินาที (ไฟกระพริบ)
  } 
  else {  
    // การทำงานของไฟจราจรปกติ
    // แยกที่ 1 - ไฟเขียว, แยกที่ 2 - ไฟแดง
    digitalWrite(green1, HIGH);  // เปิดไฟเขียวแยกที่ 1
    digitalWrite(red1, LOW);     // ปิดไฟแดงแยกที่ 1
    digitalWrite(yellow1, LOW);  // ปิดไฟเหลืองแยกที่ 1
    digitalWrite(red2, HIGH);    // เปิดไฟแดงแยกที่ 2
    digitalWrite(yellow2, LOW);  // ปิดไฟเหลืองแยกที่ 2
    digitalWrite(green2, LOW);   // ปิดไฟเขียวแยกที่ 2
    Serial.println("Normal mode: Green 1, Red 2");
    delay(5000); // ไฟเขียวแยกที่ 1 เปิดเป็นเวลา 5 วินาที

    // แยกที่ 1 - ไฟเหลือง, แยกที่ 2 - ไฟแดง
    digitalWrite(green1, LOW);  // เปิดไฟเขียวแยกที่ 1
    digitalWrite(red1, LOW);     // ปิดไฟแดงแยกที่ 1
    digitalWrite(yellow1, HIGH);  // ปิดไฟเหลืองแยกที่ 1
    digitalWrite(red2, HIGH);    // เปิดไฟแดงแยกที่ 2
    digitalWrite(yellow2, LOW);  // ปิดไฟเหลืองแยกที่ 2
    digitalWrite(green2, LOW);   // ปิดไฟเขียวแยกที่ 2
    Serial.println("Normal mode: Yellow 1");
    delay(2000); // ไฟเหลืองแยกที่ 1 เปิดเป็นเวลา 2 วินาที

    // แยกที่ 1 - ไฟแดง, แยกที่ 2 - ไฟเขียว
    digitalWrite(yellow1, LOW);  // ปิดไฟเหลืองแยกที่ 1
    digitalWrite(red1, HIGH);    // เปิดไฟแดงแยกที่ 1
    digitalWrite(green1, LOW);   // ปิดไฟเขียวแยกที่ 1
    digitalWrite(red2, LOW);     // ปิดไฟแดงแยกที่ 2
    digitalWrite(yellow2, LOW);  // ปิดไฟเหลืองแยกที่ 2
    digitalWrite(green2, HIGH);  // เปิดไฟเขียวแยกที่ 2
    Serial.println("Normal mode: Green 2, Red 1");
    delay(5000); // ไฟเขียวแยกที่ 2 เปิดเป็นเวลา 5 วินาที

    // แยกที่ 1 - ไฟแดง, แยกที่ 2 - ไฟเหลือง
    digitalWrite(green1, LOW);  // เปิดไฟเขียวแยกที่ 1
    digitalWrite(red1, HIGH);     // ปิดไฟแดงแยกที่ 1
    digitalWrite(yellow1, LOW);  // ปิดไฟเหลืองแยกที่ 1
    digitalWrite(red2, LOW);    // เปิดไฟแดงแยกที่ 2
    digitalWrite(yellow2, HIGH);  // ปิดไฟเหลืองแยกที่ 2
    digitalWrite(green2, LOW);   // ปิดไฟเขียวแยกที่ 2
    Serial.println("Normal mode: Yellow 2");
    delay(2000); // ไฟเหลืองแยกที่ 2 เปิดเป็นเวลา 2 วินาที
  }
}