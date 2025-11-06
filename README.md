# 🚦 Arduino Traffic Light + 7-Segment Display

Project Name: Traffic Light with 7-Segment Countdown Display
Description:
A simple Arduino project that simulates a traffic light system using three LEDs (Red, Yellow, Green) and a 1-digit 7-segment display to show a countdown timer.
Each light stays on for a fixed period, and the display counts down accordingly.

Main Features:

🟢 Green light ON for 5 seconds → display counts from 5 → 0

🟡 Yellow light ON for 2 seconds → display counts from 2 → 0

🔴 Red light ON for 5 seconds → display counts from 5 → 0

Learning Purpose:

Understand how to control a 7-segment display (a–g pins)

Practice timing control with multiple LEDs

Great beginner Arduino project to learn programming logic

---

## 🎥 Demo Video
👉 Watch on TikTok: [@thanhduy.it](https://www.tiktok.com/@thanhduy.it)

---

## ⚙️ Components Required
| Component | Quantity | Notes |
|------------|-----------|-------|
| Arduino UNO | 1 | Main controller |
| LED (Red, Yellow, Green) | 3 | 220Ω resistor each |
| 7-Segment Display (1 Digit) | 1 | Common Cathode type |
| Breadboard + Wires | - | For connections |

---

## 🧩 Wiring Diagram

| Arduino Pin | Connection | Description |
|--------------|-------------|-------------|
| 10 | Red LED | Through 220Ω resistor |
| 11 | Yellow LED | Through 220Ω resistor |
| 12 | Green LED | Through 220Ω resistor |
| 2–8 | Segments a–g | Connect directly |
| GND | 7-Segment common | Common cathode |

---

## 💡 Arduino Code

```cpp
// =====================================================
// 🚦 Arduino Traffic Light + 7-Segment Display
// 💡 Mạch đèn giao thông với LED 7 đoạn đếm ngược
// =====================================================

// ------------------------------
// 🇻🇳 Chân điều khiển các đoạn của LED 7 đoạn (a–g)
// 🇬🇧 7-Segment display control pins (a–g)
// ------------------------------
int segA = 2;
int segB = 3;
int segC = 4;
int segD = 5;
int segE = 6;
int segF = 7;
int segG = 8;

// ------------------------------
// 🇻🇳 Chân điều khiển đèn giao thông
// 🇬🇧 Traffic light LEDs (Red, Yellow, Green)
// ------------------------------
int ledRed = 10;
int ledYellow = 11;
int ledGreen = 12;

// ------------------------------
// 🇻🇳 Bảng hiển thị số cho LED 7 đoạn (Cathode chung)
// 🇬🇧 7-segment display patterns (Common Cathode)
// ------------------------------
byte digits[10][7] = {
  {1,1,1,1,1,1,0}, // 0 = a,b,c,d,e,f on, g off
  {0,1,1,0,0,0,0}, // 1 = b,c on
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}  // 9
};

// ------------------------------
// 🇻🇳 Hàm hiển thị số lên LED 7 đoạn
// 🇬🇧 Display a number (0–9) on 7-segment
// ------------------------------
void displayDigit(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(2 + i, digits[num][i]);
  }
}

// ------------------------------
// 🇻🇳 Thiết lập các chân xuất (OUTPUT)
// 🇬🇧 Setup I/O pins
// ------------------------------
void setup() {
  for (int i = 2; i <= 8; i++) pinMode(i, OUTPUT); // Segments a–g
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
}

// ------------------------------
// 🇻🇳 Chương trình chính (vòng lặp vô hạn)
// 🇬🇧 Main loop – runs repeatedly
// ------------------------------
void loop() {

  // =====================================================
  // 1️⃣ Đèn Xanh / Green Light – 5 seconds
  // =====================================================
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledRed, LOW);
  for (int i = 5; i >= 0; i--) {
    displayDigit(i);
    delay(1000); // 1 second delay
  }

  // =====================================================
  // 2️⃣ Đèn Vàng / Yellow Light – 2 seconds
  // =====================================================
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledYellow, HIGH);
  digitalWrite(ledRed, LOW);
  for (int i = 2; i >= 0; i--) {
    displayDigit(i);
    delay(1000);
  }

  // =====================================================
  // 3️⃣ Đèn Đỏ / Red Light – 5 seconds
  // =====================================================
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledRed, HIGH);
  for (int i = 5; i >= 0; i--) {
    displayDigit(i);
    delay(1000);
  }
}

