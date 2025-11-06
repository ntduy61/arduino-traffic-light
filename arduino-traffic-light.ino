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