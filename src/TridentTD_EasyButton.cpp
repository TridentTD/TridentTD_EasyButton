#include "TridentTD_EasyButton.h"

#ifndef PRESSED
#define PRESSED     LOW
#endif

TridentTD_EasyButton::TridentTD_EasyButton(uint8_t button_pin)  {
  pinMode( button_pin, INPUT_PULLUP);

  _button.pin = button_pin;
  _button.timer = millis();
  _button.state = BT_STANDBY;
  _button.status = ST_NONE;
}

void TridentTD_EasyButton::update(){
  _button.status = ST_NONE;

  uint32_t delta = millis() - _button.timer;
  switch (_button.state) {
    case BT_STANDBY:
      if ( delta >= DEBOUCE_PERIOD) {
        if ( digitalRead(_button.pin) == PRESSED )
          _button.state = BT_PRESSED;
        _button.timer = millis();
      }
      break;
    case BT_PRESSED:
      if ( delta >= DEBOUCE_PERIOD) {
        if ( digitalRead(_button.pin) == PRESSED ) {
          if ( delta >= LONGPRESSED_PERIOD ) {
            _button.status = ST_LONGPRESSED;
            _button.state = BT_IDLE;
            _button.timer = millis();
            return;
          }
        } else {
          _button.state = BT_RELEASE;
          _button.timer = millis();
          return;
        }
      }
      break;
    case BT_RELEASE:
      if ( delta >= DEBOUCE_PERIOD) {
        if ( delta <= DOUBLECLICK_PERIOD) {
          if ( digitalRead(_button.pin) == PRESSED ) {
            _button.status = ST_DOUBLECLICK;
            _button.state = BT_IDLE;
            _button.timer = millis();
            return;
          }
        } else {
          _button.status = ST_PRESSED;
          _button.state = BT_IDLE;
          _button.timer = millis();
          return;
        }
      }
      break;
    case BT_IDLE:
      if ( delta >= DEBOUCE_PERIOD) {
        if ( digitalRead( _button.pin ) != PRESSED)
          _button.state = BT_STANDBY;
        _button.timer = millis();
      }
      break;
  }
}

