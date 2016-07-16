void setup() 
{
  // กำหนดขาควบคุมมอเตอร์ต่างๆ ให้เป็นโหมด OUTPUT
  
  pinMode(D1, OUTPUT); // D1 PWM MOTOR_LEFT
  pinMode(D2, OUTPUT); // D2 PWM MOTOR_RIGHT
  pinMode(D3, OUTPUT); // D3 DIR MOTOR_LEFT
  pinMode(D4, OUTPUT); // D4 DIR MOTOR_RIGHT
  
  delay(5000);  // รอเวลาตั้งตัว 5 วิ
}

void loop() 
{
  // คำสั่งสำหรับให้รถเคลื่อนที่ไปข้างหน้า
  
  analogWrite(D1, 1024);   // กำหนดความเร็วมอเตอร์ A (ล้อข้างซ้าย) เท่ากับ 100%
  analogWrite(D2, 1024);   // กำหนดความเร็วมอเตอร์ B (ล้อข้างขวา) เท่ากับ 100%
  digitalWrite(D3, HIGH);  // กำหนดทิศทาง ให้มอเตอร์ A หมุนเดินหน้า
  digitalWrite(D4, HIGH);  // กำหนดทิศทาง ให้มอเตอร์ B หมุนเดินหน้า
}
