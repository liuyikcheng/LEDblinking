#include "Blinking.h"

//PA0 as buttonA
//PB4 as buttonB

void buttonHold(TaskState *ts){
  switch(ts->state){
    case RELEASED:
        if(getButton(ts->whichButton) == IS_PRESSED){
          // turnLed(ts->whichLED, LED_ON);
          ts->whichLED = LED_ON;
          ts->recordedTime = getTime();
          ts->state = PRESSED_ON;
        }
        else
          ts->state = RELEASED;
        break;
        
    case PRESSED_ON:
        // turnLed(ts->whichLED, LED_ON);
        ts->whichLED = LED_ON;
        if(getTime()-(ts->recordedTime) == ts->interval){
          if(getButton(ts->whichButton) == IS_PRESSED){
            ts->recordedTime = getTime();
            ts->state = PRESSED_OFF;
          }
          else
            ts->state = RELEASED_ON;
        }
        break;
        
    case PRESSED_OFF:
        // turnLed(ts->whichLED, LED_OFF);
        ts->whichLED = LED_OFF;
        if(getTime()-(ts->recordedTime) == ts->interval){
          if(getButton(ts->whichButton) == IS_PRESSED){
            ts->recordedTime = getTime();
            ts->state = PRESSED_ON;
          }
          else
            ts->state = RELEASED_OFF;
        }
        break;
        
    case RELEASED_ON:
        // turnLed(ts->whichLED, LED_ON);
        ts->whichLED = LED_ON;
        if(getTime()-(ts->recordedTime) == ts->interval){
          if(getButton(ts->whichButton) == NOT_PRESSED){
            ts->recordedTime = getTime();
            ts->state = RELEASED_OFF;
          }
          else
            ts->state = TURNING_OFF;
        }
        break;
        
    case RELEASED_OFF:
        // turnLed(ts->whichLED, LED_OFF);
        ts->whichLED = LED_OFF;
        if(getTime()-(ts->recordedTime) == ts->interval){
          if(getButton(ts->whichButton) == NOT_PRESSED){
            ts->recordedTime = getTime();
            ts->state = RELEASED_ON;
          }
          else
            ts->state = TURNING_OFF;
        }
        break;
    
    case TURNING_OFF:
        // turnLed(ts->whichLED, LED_OFF);
        ts->whichLED = LED_OFF;
        ts->state = RELEASED;
        break;
        
  }
}

TaskState *initiateLED(int interval){
  TaskState *ts = malloc(sizeof(TaskState));
  ts->state = RELEASED;
  ts->whichLED = LED_OFF;
  ts->interval = interval;
  return ts;
}

