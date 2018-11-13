#include <TridentTD_EasyButton.h>

TridentTD_EasyButton ButtonA(5);  // กำหนดขา pin

void setup() {
  Serial.begin(115200);
}

void loop() {
  ButtonA.update();
  if( ButtonA.isPressed() ){
    Serial.println( " Button A is Pressed");
  }
  if( ButtonA.isLongPressed()){
    Serial.println( " Button A is LongPressed");    
  }
  if( ButtonA.isDoubleClick()){
    Serial.println( " Button A is Double-Click");    
  }
}

