• #include "BluetoothSerial.h" 
•  
• BluetoothSerial SerialBT; 
•   موتور سمت چپ  // 
•
• #define IN1 18 
• #define IN2 19 
•   موتور سمت راست  // 
•
• #define IN3 16 
• #define IN4 17 
•   L298N فعال سازی // 
•
• #define ENA 23 
• #define ENB 22 
•  
• void stopCar() { 
•   digitalWrite(IN1, LOW); 
•   digitalWrite(IN2, LOW); 
•   digitalWrite(IN3, LOW); 
•   digitalWrite(IN4, LOW); 
• } 
•  
• void forwardCar() { 
•   digitalWrite(IN1, HIGH); 
•   digitalWrite(IN2, LOW); 
•  
•   digitalWrite(IN3, HIGH); 
•   digitalWrite(IN4, LOW); 
• } 
•  
• void backwardCar() { 
•   digitalWrite(IN1, LOW); 
•   digitalWrite(IN2, HIGH); 
•  
•   digitalWrite(IN3, LOW); 
•   digitalWrite(IN4, HIGH); 
• } 
•  
• void leftCar() { 
•   digitalWrite(IN1, LOW); 
•   digitalWrite(IN2, HIGH); 
•  
•   digitalWrite(IN3, HIGH); 
•   digitalWrite(IN4, LOW); 
• } 
•  
• void rightCar() { 
•   digitalWrite(IN1, HIGH); 
•   digitalWrite(IN2, LOW); 
•  
•   digitalWrite(IN3, LOW); 
•   digitalWrite(IN4, HIGH); 
• } 
•  
• void setup() { 
•   Serial.begin(115200); 
•  
•   pinMode(IN1, OUTPUT); 
•   pinMode(IN2, OUTPUT); 
•   pinMode(IN3, OUTPUT); 
•   pinMode(IN4, OUTPUT); 
•  
•   pinMode(ENA, OUTPUT); 
•   pinMode(ENB, OUTPUT); 
•   فعال کردن درایور موتور  //   
•
•   digitalWrite(ENA, HIGH); 
•   digitalWrite(ENB, HIGH); 
•  
•   stopCar(); 
•  
•   SerialBT.begin("ESP32_CAR"); 
•   Serial.println("Bluetooth Ready"); 
• } 
•  
• void loop() { 
•   if (SerialBT.available()) { 
•     char cmd = SerialBT.read(); 
•  
•     Serial.println(cmd); 
•  
•     switch (cmd) { 
•       case 'F': 
•         forwardCar(); 
•         break; 
•  
•       case 'B': 
•         backwardCar(); 
•         break; 
•  
•       case 'L': 
•        rightCar(); 
•         break; 
•  
•       case 'R': 
•        leftCar(); 
•         break; 
•  
•       case 'S': 
•         stopCar(); 
•         break; 
•     } 
•   } 
• } 
