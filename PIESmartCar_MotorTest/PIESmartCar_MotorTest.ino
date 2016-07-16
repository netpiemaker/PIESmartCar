void setup() 
{
  analogWriteFreq(50); // ปรับความถี่สัญญาณ PWM เป็น 50Hz
  
  // กำหนดขาควบคุมมอเตอร์ต่างๆ ให้เป็นโหมด OUTPUT
  pinMode(D1, OUTPUT); // D1 PWM MOTOR_LEFT
  pinMode(D2, OUTPUT); // D2 PWM MOTOR_RIGHT
  pinMode(D3, OUTPUT); // D3 DIR MOTOR_LEFT
  pinMode(D4, OUTPUT); // D4 DIR MOTOR_RIGHT
  
  delay(5000);  // รอเวลาตั้งตัว 5 วินาที
  
  analogWrite(D1, 512);   // กำหนดความเร็วมอเตอร์ A (ล้อข้างซ้าย) เท่ากับ 50%
  analogWrite(D2, 512);   // กำหนดความเร็วมอเตอร์ B (ล้อข้างขวา) เท่ากับ 50%
  digitalWrite(D3, HIGH);  // กำหนดทิศทาง ให้มอเตอร์ A หมุนเดินหน้า
  digitalWrite(D4, HIGH);  // กำหนดทิศทาง ให้มอเตอร์ B หมุนเดินหน้า

  delay(5000); // เดินหน้าไปเป็นเวลา 5 วินาที
  
  analogWrite(D1, 0);   // กำหนดความเร็วมอเตอร์ A (ล้อข้างซ้าย) เท่ากับ 0% (หยุดรถ)
  analogWrite(D2, 0);   // กำหนดความเร็วมอเตอร์ B (ล้อข้างขวา) เท่ากับ 0% (หยุดรถ)
}

void loop() 
{
}
