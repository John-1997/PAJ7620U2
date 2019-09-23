#include <DFRobot_PAJ7620U2.h>
 
DFRobot_PAJ7620U2 paj;

void setup()
{
  Serial.begin(115200);
  delay(300);
  while(paj.begin() != 0)
  {
    //judge if the system is fine
    Serial.println("The system is not fine,please check again");
    delay(500);
  }
  Serial.println("Fully completed");//This meaning the system is ready to work.
  paj.setGestureHighRate(false);//set the mode as HighRate
}

void loop()
{
  DFRobot_PAJ7620U2::eGesture_t gesture = paj.getGesture();
  if(gesture != paj.eGestureNone )
  {
    //judge if a gesture is recognize
    String description  = paj.gestureDescription(gesture);//Convert the gesture number into string description
    Serial.print("gesture description  = ");Serial.println(description);
  }
}
