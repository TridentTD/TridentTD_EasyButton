# TridentTD_EasyButton

ควบคุม ปุ่มกด แบบง่ายๆ สามารถตรวจจับได้ทั้ง   
กดครั้งเดียว กดแบบ double-click และกดแบบ long-pressed  
  
โดย หากกดแบบ double-click หรือ long-pressed  
จะไม่มีการเข้าสู่การกดแบบครั้งเดียวก่อน  

ตัวอย่าง
----

```CPP
#include <TridentTD_EasyButton.h>

TridentTD_EasyButton ButtonA(5);

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
```
