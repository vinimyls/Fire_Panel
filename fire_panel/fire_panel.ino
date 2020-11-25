#include "Nextion.h"
#define relay 12
#define smoke_detector 7
/************************ Nextion components ****************/
//page 0
NexPage page0             = NexPage(0, 0, "page0");

//page 1
NexButton btnReset       = NexButton(1, 2, "btnReset");
NexPage page1             = NexPage(1, 0, "page1");

// page 2
NexPage page2             = NexPage(2, 0, "page2");

// This array contains the objects there are touch interactive
NexTouch *nex_listen_list[] =
{
  &btnReset,
  NULL
};

/*****************    Variables     ****************/
bool reset = false;
long previousMillis = 0;
const int maxTime = 10000;
int fire = 0;
/***************************************************/

void setup()
{
  Serial.begin(9600);
  nexInit();                                          //serial nextion inicialize
  btnReset.attachPop(btnResetPopCallback, &btnReset); //callback for release events from nextion buttons
  pinMode(relay, OUTPUT);
  pinMode(smoke_detector, INPUT);
  digitalWrite(relay, HIGH);
}

void loop() {
  nexLoop(nex_listen_list);
  fire = digitalRead(smoke_detector);
  if (fire && !reset)
  {
    page1.show();
  }
  delay(500);
  if (reset)
  {
    if (millis() - previousMillis >= maxTime)
    {
      page0.show();
      reset = false;
      digitalWrite(relay, HIGH);
      fire = 0;
    }
  }
}

/***********  CALLBACKS   ********/
void btnResetPopCallback(void *ptr)
{
  page2.show();
  reset = true;
  digitalWrite(relay, LOW);
  previousMillis = millis();
}
