#ifndef __TRIDENTTD_EASYBUTTON_H__
#define __TRIDENTTD_EASYBUTTON_H__

#define DEBOUCE_PERIOD      80
#define LONGPRESSED_PERIOD  1300
#define DOUBLECLICK_PERIOD  500

#include <Arduino.h>

class TridentTD_EasyButton {
public:
  TridentTD_EasyButton( uint8_t button_pin );

  void update();
  bool isPressed()        { return _button.status == ST_PRESSED;     }
  bool isLongPressed()    { return _button.status == ST_LONGPRESSED; }
  bool isDoubleClick()    { return _button.status == ST_DOUBLECLICK; }
private:
  typedef enum {ST_NONE, ST_PRESSED, ST_DOUBLECLICK, ST_LONGPRESSED } bt_status_t;
  typedef enum {BT_STANDBY, BT_PRESSED, BT_RELEASE, BT_IDLE} bt_state_t;
  typedef struct { uint8_t pin; bt_state_t  state; uint32_t timer; bt_status_t status; } button_t;
  
  button_t _button;  
};

#endif
