


static unsigned int minval= 30;
static unsigned int maxval=34;

String pkt1="";
String pkt2="";


String data_buff="";
int val;
int tempPin = A1;
int ref= 7;

void setup()
{
Serial.begin(9600);
pinMode(7, OUTPUT);
}
void loop()
{
val = analogRead(tempPin);
float mv = ( val/1024.0)*5000; 
float cel = mv/10;
float farh = (cel*9)/5 + 32;

Serial.print("TEMPRATURE = ");
Serial.print(cel);
Serial.print("*C");
Serial.println();
delay(3000);
if(Serial.available()>0)
{
  while(Serial.read()>0)
  {
  data_buff=Serial.readString();
pkt1=data_buff.substring(0,2);
pkt2=data_buff.substring(2,4);
minval=pkt1.toInt();
maxval=pkt2.toInt();
  Serial.print("bt data:");
  Serial.println(data_buff);
  Serial.println(minval);
  Serial.println(maxval);
  }
}
//if 16  2 32  off
if((cel>=minval)&& (cel<=maxval))
{
  
 
 digitalWrite(7 , HIGH); 
  
  }
  
  else
  {
    //relay off
 digitalWrite(7, LOW); 
 
     
    }

}
