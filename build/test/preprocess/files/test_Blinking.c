#include "mock_Action.h"
#include "Blinking.h"
#include "unity.h"


void setUp(void)

{

}



void tearDown(void)

{

}



void test_initiateLED(void){

  TaskState *ts1 = initiateLED(250);



  UnityAssertEqualNumber((_U_SINT)((ts1->interval)), (_U_SINT)((250)), (((void *)0)), (_U_UINT)16, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((ts1->state)), (_U_SINT)((RELEASED)), (((void *)0)), (_U_UINT)17, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((ts1->whichLED)), (_U_SINT)((0)), (((void *)0)), (_U_UINT)18, UNITY_DISPLAY_STYLE_INT);

}



void test_buttonHold_case_pressed_released_to_press(void){

  TaskState *ts1 = initiateLED(250);



  getButton_CMockExpectAndReturn(24, ts1->whichButton, 1);



  getTime_CMockExpectAndReturn(26, 100);



  buttonHold(ts1);



  UnityAssertEqualNumber((_U_SINT)((ts1->state)), (_U_SINT)((PRESSED_ON)), (((void *)0)), (_U_UINT)30, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((ts1->whichLED)), (_U_SINT)((1)), (((void *)0)), (_U_UINT)31, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((ts1->recordedTime)), (_U_SINT)((100)), (((void *)0)), (_U_UINT)32, UNITY_DISPLAY_STYLE_INT);

}



void test_buttonHold_press_on_to_press_off(void){

  TaskState *ts1 = initiateLED(250);

  ts1->state = PRESSED_ON;

  ts1->recordedTime = 0;



  getTime_CMockExpectAndReturn(40, 250);

    getButton_CMockExpectAndReturn(41, ts1->whichButton, 1);



  getTime_CMockExpectAndReturn(43, 100);



  buttonHold(ts1);



  UnityAssertEqualNumber((_U_SINT)((ts1->state)), (_U_SINT)((PRESSED_OFF)), (((void *)0)), (_U_UINT)47, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((ts1->whichLED)), (_U_SINT)((1)), (((void *)0)), (_U_UINT)48, UNITY_DISPLAY_STYLE_INT);

}



void test_buttonHold_press_off_to_press_on(void){

  TaskState *ts1 = initiateLED(250);

  ts1->state = PRESSED_OFF;

  ts1->recordedTime = 0;



  getTime_CMockExpectAndReturn(56, 250);

    getButton_CMockExpectAndReturn(57, ts1->whichButton, 1);



  getTime_CMockExpectAndReturn(59, 100);



  buttonHold(ts1);



  UnityAssertEqualNumber((_U_SINT)((ts1->state)), (_U_SINT)((PRESSED_ON)), (((void *)0)), (_U_UINT)63, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((ts1->whichLED)), (_U_SINT)((0)), (((void *)0)), (_U_UINT)64, UNITY_DISPLAY_STYLE_INT);

}



void test_buttonHold_press_on_to_release_on(void){

  TaskState *ts1 = initiateLED(250);

  ts1->state = PRESSED_ON;

  ts1->recordedTime = 0;



  getTime_CMockExpectAndReturn(72, 250);

  getButton_CMockExpectAndReturn(73, ts1->whichButton, 0);





  buttonHold(ts1);



  UnityAssertEqualNumber((_U_SINT)((ts1->state)), (_U_SINT)((RELEASED_ON)), (((void *)0)), (_U_UINT)78, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((ts1->whichLED)), (_U_SINT)((1)), (((void *)0)), (_U_UINT)79, UNITY_DISPLAY_STYLE_INT);

}



void test_buttonHold_press_off_to_release_off(void){

  TaskState *ts1 = initiateLED(250);

  ts1->state = PRESSED_OFF;

  ts1->recordedTime = 0;



  getTime_CMockExpectAndReturn(87, 250);

  getButton_CMockExpectAndReturn(88, ts1->whichButton, 0);





  buttonHold(ts1);



  UnityAssertEqualNumber((_U_SINT)((ts1->state)), (_U_SINT)((RELEASED_OFF)), (((void *)0)), (_U_UINT)93, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((ts1->whichLED)), (_U_SINT)((0)), (((void *)0)), (_U_UINT)94, UNITY_DISPLAY_STYLE_INT);

}



void test_buttonHold_release_on_to_release_off(void){

  TaskState *ts1 = initiateLED(250);

  ts1->state = RELEASED_ON;

  ts1->recordedTime = 0;



  getTime_CMockExpectAndReturn(102, 250);

  getButton_CMockExpectAndReturn(103, ts1->whichButton, 0);



  getTime_CMockExpectAndReturn(105, 100);



  buttonHold(ts1);



  UnityAssertEqualNumber((_U_SINT)((ts1->state)), (_U_SINT)((RELEASED_OFF)), (((void *)0)), (_U_UINT)109, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((ts1->whichLED)), (_U_SINT)((1)), (((void *)0)), (_U_UINT)110, UNITY_DISPLAY_STYLE_INT);

}



void test_buttonHold_release_off_to_release_on(void){

  TaskState *ts1 = initiateLED(250);

  ts1->state = RELEASED_OFF;

  ts1->recordedTime = 0;



  getTime_CMockExpectAndReturn(118, 250);

  getButton_CMockExpectAndReturn(119, ts1->whichButton, 0);



  getTime_CMockExpectAndReturn(121, 100);



  buttonHold(ts1);



  UnityAssertEqualNumber((_U_SINT)((ts1->state)), (_U_SINT)((RELEASED_ON)), (((void *)0)), (_U_UINT)125, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((ts1->whichLED)), (_U_SINT)((0)), (((void *)0)), (_U_UINT)126, UNITY_DISPLAY_STYLE_INT);

}



void test_buttonHold_release_on_to_turning_off(void){

  TaskState *ts1 = initiateLED(250);

  ts1->state = RELEASED_ON;

  ts1->recordedTime = 0;



  getTime_CMockExpectAndReturn(134, 250);

  getButton_CMockExpectAndReturn(135, ts1->whichButton, 1);





  buttonHold(ts1);



  UnityAssertEqualNumber((_U_SINT)((ts1->state)), (_U_SINT)((TURNING_OFF)), (((void *)0)), (_U_UINT)140, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((ts1->whichLED)), (_U_SINT)((1)), (((void *)0)), (_U_UINT)141, UNITY_DISPLAY_STYLE_INT);

}



void test_buttonHold_release_off_to_turning_off(void){

  TaskState *ts1 = initiateLED(250);

  ts1->state = RELEASED_OFF;

  ts1->recordedTime = 0;



  getTime_CMockExpectAndReturn(149, 250);

  getButton_CMockExpectAndReturn(150, ts1->whichButton, 1);





  buttonHold(ts1);



  UnityAssertEqualNumber((_U_SINT)((ts1->state)), (_U_SINT)((TURNING_OFF)), (((void *)0)), (_U_UINT)155, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((ts1->whichLED)), (_U_SINT)((0)), (((void *)0)), (_U_UINT)156, UNITY_DISPLAY_STYLE_INT);

}





void test_buttonHold_turning_off_to_release(void){

  TaskState *ts1 = initiateLED(250);

  ts1->state = TURNING_OFF;

  ts1->recordedTime = 0;











  buttonHold(ts1);



  UnityAssertEqualNumber((_U_SINT)((ts1->state)), (_U_SINT)((RELEASED)), (((void *)0)), (_U_UINT)171, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((ts1->whichLED)), (_U_SINT)((0)), (((void *)0)), (_U_UINT)172, UNITY_DISPLAY_STYLE_INT);

}
