#include "unity.h"
#include "Blinking.h"
#include "mock_Action.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_initiateLED(void){ 
  TaskState *ts1 = initiateLED(250);
  
  TEST_ASSERT_EQUAL(ts1->interval,250);
  TEST_ASSERT_EQUAL(ts1->state,RELEASED);
  TEST_ASSERT_EQUAL(ts1->whichLED,LED_OFF);
}

void test_buttonHold_case_pressed_released_to_press(void){
  TaskState *ts1 = initiateLED(250);
  
  getButton_ExpectAndReturn(ts1->whichButton,IS_PRESSED);
  // turnLed_Expect(ts1->whichLED,LED_ON);
  getTime_ExpectAndReturn(100);
  
  buttonHold(ts1);
  
  TEST_ASSERT_EQUAL(ts1->state,PRESSED_ON);
  TEST_ASSERT_EQUAL(ts1->whichLED,LED_ON);
  TEST_ASSERT_EQUAL(ts1->recordedTime,100);
}

void test_buttonHold_press_on_to_press_off(void){
  TaskState *ts1 = initiateLED(250);
  ts1->state = PRESSED_ON;
  ts1->recordedTime = 0;
  
  getTime_ExpectAndReturn(250);
    getButton_ExpectAndReturn(ts1->whichButton,IS_PRESSED);
  // turnLed_Expect(ts1->whichLED,LED_ON);
  getTime_ExpectAndReturn(100);
  
  buttonHold(ts1);
  
  TEST_ASSERT_EQUAL(ts1->state,PRESSED_OFF);
  TEST_ASSERT_EQUAL(ts1->whichLED,LED_ON);
}

void test_buttonHold_press_off_to_press_on(void){
  TaskState *ts1 = initiateLED(250);
  ts1->state = PRESSED_OFF;
  ts1->recordedTime = 0;
  
  getTime_ExpectAndReturn(250);
    getButton_ExpectAndReturn(ts1->whichButton,IS_PRESSED);
  // turnLed_Expect(ts1->whichLED,LED_ON);
  getTime_ExpectAndReturn(100);
  
  buttonHold(ts1);
  
  TEST_ASSERT_EQUAL(ts1->state,PRESSED_ON);
  TEST_ASSERT_EQUAL(ts1->whichLED,LED_OFF);
}

void test_buttonHold_press_on_to_release_on(void){
  TaskState *ts1 = initiateLED(250);
  ts1->state = PRESSED_ON;
  ts1->recordedTime = 0;
  
  getTime_ExpectAndReturn(250);
  getButton_ExpectAndReturn(ts1->whichButton,NOT_PRESSED);
  // turnLed_Expect(ts1->whichLED,LED_ON);
  
  buttonHold(ts1);
  
  TEST_ASSERT_EQUAL(ts1->state,RELEASED_ON);
  TEST_ASSERT_EQUAL(ts1->whichLED,LED_ON);
}

void test_buttonHold_press_off_to_release_off(void){
  TaskState *ts1 = initiateLED(250);
  ts1->state = PRESSED_OFF;
  ts1->recordedTime = 0;
  
  getTime_ExpectAndReturn(250);
  getButton_ExpectAndReturn(ts1->whichButton,NOT_PRESSED);
  // turnLed_Expect(ts1->whichLED,LED_ON);
  
  buttonHold(ts1);
  
  TEST_ASSERT_EQUAL(ts1->state,RELEASED_OFF);
  TEST_ASSERT_EQUAL(ts1->whichLED,LED_OFF);
}

void test_buttonHold_release_on_to_release_off(void){
  TaskState *ts1 = initiateLED(250);
  ts1->state = RELEASED_ON;
  ts1->recordedTime = 0;
  
  getTime_ExpectAndReturn(250);
  getButton_ExpectAndReturn(ts1->whichButton,NOT_PRESSED);
  // turnLed_Expect(ts1->whichLED,LED_ON);
  getTime_ExpectAndReturn(100);
  
  buttonHold(ts1);
  
  TEST_ASSERT_EQUAL(ts1->state,RELEASED_OFF);
  TEST_ASSERT_EQUAL(ts1->whichLED,LED_ON);
}

void test_buttonHold_release_off_to_release_on(void){
  TaskState *ts1 = initiateLED(250);
  ts1->state = RELEASED_OFF;
  ts1->recordedTime = 0;
  
  getTime_ExpectAndReturn(250);
  getButton_ExpectAndReturn(ts1->whichButton,NOT_PRESSED);
  // turnLed_Expect(ts1->whichLED,LED_ON);
  getTime_ExpectAndReturn(100);
  
  buttonHold(ts1);
  
  TEST_ASSERT_EQUAL(ts1->state,RELEASED_ON);
  TEST_ASSERT_EQUAL(ts1->whichLED,LED_OFF);
}

void test_buttonHold_release_on_to_turning_off(void){
  TaskState *ts1 = initiateLED(250);
  ts1->state = RELEASED_ON;
  ts1->recordedTime = 0;
  
  getTime_ExpectAndReturn(250);
  getButton_ExpectAndReturn(ts1->whichButton,IS_PRESSED);
  // turnLed_Expect(ts1->whichLED,LED_ON);
  
  buttonHold(ts1);
  
  TEST_ASSERT_EQUAL(ts1->state,TURNING_OFF);
  TEST_ASSERT_EQUAL(ts1->whichLED,LED_ON);
}

void test_buttonHold_release_off_to_turning_off(void){
  TaskState *ts1 = initiateLED(250);
  ts1->state = RELEASED_OFF;
  ts1->recordedTime = 0;
  
  getTime_ExpectAndReturn(250);
  getButton_ExpectAndReturn(ts1->whichButton,IS_PRESSED);
  // turnLed_Expect(ts1->whichLED,LED_ON);
  
  buttonHold(ts1);
  
  TEST_ASSERT_EQUAL(ts1->state,TURNING_OFF);
  TEST_ASSERT_EQUAL(ts1->whichLED,LED_OFF);
}


void test_buttonHold_turning_off_to_release(void){
  TaskState *ts1 = initiateLED(250);
  ts1->state = TURNING_OFF;
  ts1->recordedTime = 0;
  
  // getTime_ExpectAndReturn(250);
  // getButton_ExpectAndReturn(ts1->whichButton,IS_PRESSED);
  // turnLed_Expect(ts1->whichLED,LED_ON);
  
  buttonHold(ts1);
  
  TEST_ASSERT_EQUAL(ts1->state,RELEASED);
  TEST_ASSERT_EQUAL(ts1->whichLED,LED_OFF);
}