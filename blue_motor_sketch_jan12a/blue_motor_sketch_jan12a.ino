#include<Servo.h>
Servo Myservo;
int pos;
void setup()
{
Myservo.attach(3);
}

void loop()
{
  
  
for(pos=0;pos<=270;pos++){
Myservo.write(pos);
delay(15);
}
  delay(1000);
  
  for(pos=270;pos>=0;pos--){
Myservo.write(pos);
delay(15);
}
  delay(1000);
  
}
