//Test device : Control onboard led
//This code is used with LibreInterface to showcase
//How to control an arduino using websocket.
//http://github.com/madnerdorg/test
const String usb_name = "test:42000";

//Serial string buffer
String readString;
String state = "OFF";
// Serial

//Check received message
void serialCheck() {
  //Message to initialize websocket
  if (readString == "/info") {
    Serial.println(usb_name);
  }

  //Get current status
  if (readString == "/status"){
    Serial.println(state);
  }

  //Change onboard led state
  if (readString == "ON") {
      digitalWrite(13, 1);
      state = "ON";
      Serial.println(state);
    }
    if (readString == "OFF") {
      digitalWrite(13, 0);
      state = "OFF";
      Serial.println(state);
  }
}

//Convert characters sent by serial to string
void serialManager() {
  //Get Serial as a string
  while (Serial.available()) {
    delay(3); // Wait for data

    //Convert to String
    if (Serial.available() > 0) {
      char c = Serial.read();
      readString += c;
    }
  }
}

void setup() {
  //Setup Serial
  Serial.begin(115200);
}

void loop() {
  serialManager();

  //If string received
  if (readString.length() > 0) {
    serialCheck();
  }

  //We clean the serial buffer
  readString = "";
}
