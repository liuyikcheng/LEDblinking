#ifndef Blinking_H
#define Blinking_H
#include "Action.h"

#define IS_PRESSED 1
#define NOT_PRESSED 0
#define LED_ON 1
#define LED_OFF 0

typedef enum{
  RELEASED,
  PRESSED_ON,
  PRESSED_OFF,
  RELEASED_ON,
  RELEASED_OFF,
  TURNING_OFF
}FsmState;

typedef struct{
  FsmState state;
  unsigned int recordedTime;
  int interval;
  int whichLED;
  int whichButton;
}TaskState;

void buttonHold(TaskState *ts);
TaskState *initiateLED(int interval);

#endif // Blinking_H
