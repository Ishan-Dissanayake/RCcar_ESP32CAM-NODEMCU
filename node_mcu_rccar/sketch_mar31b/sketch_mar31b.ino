
// Pin assignments for NodeMCU
const int RPWM_Output1 = D6;  // GPIO pin connected to RPWM_Output1
const int LPWM_Output1 = D5;  // GPIO pin connected to LPWM_Output1
const int RPWM_Output2 = D3;  // GPIO pin connected to RPWM_Output2
const int LPWM_Output2 = D4;  // GPIO pin connected to LPWM_Output2



void setup() {
  Serial.begin(115200);  // Set the baud rate to match ESP32-CAM
  pinMode(LPWM_Output1, OUTPUT);
  pinMode(RPWM_Output1, OUTPUT);
  pinMode(LPWM_Output2, OUTPUT);
  pinMode(RPWM_Output2, OUTPUT);
 
}

void loop() {
 if (Serial.available()) {
    String receivedData = Serial.readStringUntil('\n');
    // Check if the received message starts with "Gotvalueas"
    if (receivedData.startsWith("Gotvalueas")) {
        // Extract the number part from the message
        String numberString = receivedData.substring(10); // Extract substring starting from the 10th character
        int value = numberString.toInt(); // Convert the substring to an integer
     
      // Print the received value
      Serial.print("Received value: ");
      Serial.println(value);
      if (value == 1) {
        forward();
        delay(30);
      }else if(value == 4){
       
        backward();
        delay(30);
      }else if(value == 3){
        left();
        delay(30);
      }else if(value == 2){
        right();
        delay(30);
      }else {
        stop();
        delay(30);
      }
    }
  }
}


void stop() {
  analogWrite(RPWM_Output1, 0);
  analogWrite(LPWM_Output1, 0);
  analogWrite(RPWM_Output2, 0);
  analogWrite(LPWM_Output2, 0);
  delay(30);
}

void forward() {
  analogWrite(RPWM_Output1, 0);
  analogWrite(LPWM_Output1, 155);
  analogWrite(RPWM_Output2, 0);
  analogWrite(LPWM_Output2, 155);
  delay(30);
}

void backward() {
 analogWrite(RPWM_Output1, 155);
  analogWrite(LPWM_Output1, 0);
  analogWrite(RPWM_Output2, 0);
  analogWrite(LPWM_Output2, 0);
  delay(30);
}
void right() {
  analogWrite(RPWM_Output1, 0);
  analogWrite(LPWM_Output1, 155);
  analogWrite(RPWM_Output2, 155);
  analogWrite(LPWM_Output2, 0);
  delay(30);
}

void left() {
  analogWrite(RPWM_Output1, 155);
  analogWrite(LPWM_Output1, 0);
  analogWrite(RPWM_Output2, 0);
  analogWrite(LPWM_Output2, 155);
  delay(30);
}

