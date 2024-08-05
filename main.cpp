#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);
double test_val = 0;
double t=0;
bool first_time=true;
void setup() {  

}

void loop() {

int testVal=0;
double overTime=0,start_Time1=0,previousTime0=0,previousTime=0, previousTime2=0;
bool On_OK=true;

char ch = ' ';
if(Serial.available())
{
  ch=Serial.read();
}

  while (ch=='1')
  { 
        overTime=millis();
  
        if(first_time==true)
        {
          Serial.print(test_val);
          Serial.println("\tON");
          first_time=false;
        }
        else
        {
            if((On_OK==true)&&(overTime-previousTime)>20000)
            {
              Serial.print(test_val++);
              Serial.println("\tOFF");
              previousTime=overTime;
              On_OK=false;
            }
            else if((On_OK==false)&&(overTime-previousTime)>5000)
            {
              Serial.print(test_val);
              Serial.println("\tON");
              previousTime=overTime;
              On_OK=true;
            }
            else
            {
              if(Serial.available())
              {
                ch=Serial.read();
              }
              if(ch=='2')
                break;
              
              else
              {
                  continue;
              }
            }
        }

        
  }
}

