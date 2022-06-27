#include<SoftwareSerial.h>
#include <Stepper.h>
// Define number of steps per rotation:
const int stepsPerRevolution = 2048;

#define Rx 5
#define Tx 6

int cb = 2;
int is_closed = 0;
int max_open = 0;
int steps_down = 0;
int steps_up = 0;
int current_time = 0;
int first_time = 0;
volatile byte state = LOW;
int led = 4;

SoftwareSerial mySerial(Rx,Tx);
// Wiring:
// Pin 8 to IN1 on the ULN2003 driver
// Pin 9 to IN2 on the ULN2003 driver
// Pin 10 to IN3 on the ULN2003 driver
// Pin 11 to IN4 on the ULN2003 driver

// Create stepper object called 'myStepper', note the pin order:
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  myStepper.setSpeed(15); 
  Serial.begin(9600);
  mySerial.begin(9600);
  // put your setup code here, to run once:
  pinMode(cb, INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}


void loop() {
  if(mySerial.available())
  {
    char get_res = char(mySerial.read());
    if (get_res == 'o')
    {
     is_closed = 1;
     if (max_open == 0)
     {
      for(steps_up = 0; steps_up <= 2048; steps_up++)
       {         
         myStepper.step(-17); // cuộn ngc chiều kim đồng hồ, với góc quay gấp 17 lần bth
         max_open = 1;
        if (char(mySerial.read()) == 'c')
        {
          for (int i = 0; i <= steps_up; i++)
          {
             myStepper.step(17);
          }
          max_open = 0;
          is_closed = 0;   
          state = 0;
          break;
        }
       } 
     }
  }
    if (get_res == 'c' &&  is_closed == 1)
     {
     is_closed = 0;   
     max_open = 0;
     for(steps_down = 0; steps_down <= 2048; steps_down++)
     {      
        myStepper.step(17); // cuộn chiều kim đồng hồ 
        if (char(mySerial.read()) == 'o')
        {
          for (int i = 0; i <= steps_down; i++)
          {
             myStepper.step(-17);
          }
          max_open = 1;
          is_closed = 1;   
          state = 1;
          break;
        }
     } 
  }
    if(get_res == 'l')
    {
      digitalWrite(led,HIGH);
    }
    if(get_res == 'k')
    {
      digitalWrite(led,LOW);
    }
  }
  else
  {
    if(digitalRead(cb) == HIGH)
    {
      is_closed = 1;
       if (max_open == 0)
       {
         mySerial.print("o");
        for(steps_up = 0; steps_up <= 2048; steps_up++)
         {         
           myStepper.step(-17); // cuộn nguoc chiều kim đồng hồ, với góc quay gấp 17 lần bth
           max_open = 1;
          if (digitalRead(cb) == HIGH)
          {
            mySerial.print("c");
            for (int i = 0; i <= steps_up; i++)
           {
               myStepper.step(17);
            }
            max_open = 0;
            is_closed = 0;   
            state = 0;
            break;
          }
         } 
       }
    }
  
    if (digitalRead(cb) == HIGH && is_closed == 1) // không có âm thanh và cửa chưa được đóng
    {
      
       mySerial.print("c");
       is_closed = 0;   
       max_open = 0;
     
       for(steps_down = 0; steps_down <= 2048; steps_down++)
       {      
          myStepper.step(17); // cuộn chiều kim đồng hồ 
          if (digitalRead(cb) == HIGH)
          {
           mySerial.print("o");
            for (int i = 0; i <= steps_down; i++)
            {
               myStepper.step(-17);
            }
           max_open = 1;
           is_closed = 1;   
           state = 1;
           break;
          }
      } 
    }
  }
}
