// Include the Arduino Stepper.h library:
#include <Stepper.h>

// Define number of steps per rotation:
const int stepsPerRevolution = 2048;
//cambien
int pincb = 2;
int red_pin = 5;
int green_pin = 6;
int is_closed = 0;
int max_open = 0;
int steps_down = 0;
int steps_up = 0;
int current_time = 0;
int first_time = 0;
volatile byte state = LOW;
// Wiring:
// Pin 8 to IN1 on the ULN2003 driver
// Pin 9 to IN2 on the ULN2003 driver
// Pin 10 to IN3 on the ULN2003 driver
// Pin 11 to IN4 on the ULN2003 driver

// Create stepper object called 'myStepper', note the pin order:
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void setAlert(String options)
{
  if(options == "down")
  {
    digitalWrite(red_pin,LOW);
    digitalWrite(green_pin,HIGH);
  }
  if (options == "up")
  {
    digitalWrite(red_pin,HIGH);
    digitalWrite(green_pin,LOW);
  }
}

void setup() {
  myStepper.setSpeed(15); 
  pinMode(pincb, INPUT_PULLUP);
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  // Begin Serial communication at a baud rate of 9600:
  Serial.begin(9600); 
  setAlert("down");
  attachInterrupt(digitalPinToInterrupt(pincb), scroll, HIGH);
}

void scroll()
{
  first_time = millis();
  if (first_time - current_time > 50)
  { 
     state = !state;
     Serial.println(state);
  }
  current_time = first_time;
}

void loop() {
 if(state == 1) // có âm thanh
  {
     is_closed = 1;
     if (max_open == 0)
     {
      for(steps_up = 0; steps_up <= 2048; steps_up++)
       {         
         myStepper.step(1); // cuộn cùng chiều kim đồng hồ, với góc quay gấp 1.5 lần bth
         max_open = 1;
        if (digitalRead(pincb) == HIGH)
        {
        
          for (int i = 0; i <= steps_up; i++)
          {
             myStepper.step(-1);
          }
          Serial.println("da keo xuong lai");
          max_open = 0;
          is_closed = 0;   
          state = 0;
          break;
        }
       } 
     }
  }
 
  if (state == 0 && is_closed == 1) // không có âm thanh và cửa chưa được đóng
  {
   
     is_closed = 0;   
     max_open = 0;
     
     for(steps_down = 0; steps_down <= 2048; steps_down++)
     {      
        myStepper.step(-1); // cuộn ngược chiều kim đồng hồ 
        if (digitalRead(pincb) == HIGH)
        {
         
          for (int i = 0; i <= steps_down; i++)
          {
             myStepper.step(1);
          }
          Serial.println("da keo len lai");
          max_open = 1;
          is_closed = 1;   
          state = 1;
          break;
        }
     } 
  }
}
