
int redLEDPin=10; //Declare redLEDPin an int, and set to pin 9 
int yellowLEDPin=9; //Declare yellowLEDPin an int, and set to pin 10 
int on =250; 
int off =250; 


int numRedBlinks;
int numYellowBlinks;

String dates []={"January","February","March","April","May","June","July","August","September","October","November","December"};
String month;
void setup() 
{
 Serial.begin(9600);

  pinMode(redLEDPin, OUTPUT);  // Tell Arduino that redLEDPin is an output pin
  pinMode(yellowLEDPin, OUTPUT);  //Tell Arduino that yellowLEDPin is an output pin
 

}

void loop() 
{
  numRedBlinks=0;
  numYellowBlinks=0;
  Serial.println("What is your Birth Month?");

  while(Serial.available()==0)
  {
    //Wait for the user to type
  }

  month=Serial.readString();
  month.trim();

 

  for(int i=0;i<12;i++)
  {
    if(month == dates[i])
    {
      numRedBlinks=(i+1);
    }

  }
if(numRedBlinks!=0)
{
  Serial.println("\n - The red LED is blinking");
  
  for(int i=0; i<numRedBlinks;i++)
  {
   Serial.print("   #");
   Serial.println(i+1);
     digitalWrite(redLEDPin,HIGH);
     delay(on);
     digitalWrite(redLEDPin,LOW);
     delay(off);  
  }
 }
 else
 {
  Serial.println("sorry I didn't get that. Please enter a valid month EX: August");
 }
  

  Serial.println("\nWhat day is your birthday?");

  while(Serial.available()==0)
  {
    //Wait for the user to type
  }

  numYellowBlinks=Serial.parseInt();

  if(numYellowBlinks!=0 && numRedBlinks!=0)
  {
    Serial.println("\n - The Yellow LED is blinking");
   for(int i=0; i<numYellowBlinks;i++)
  {
   Serial.print("   #");
   Serial.println(i+1);
     digitalWrite(yellowLEDPin,HIGH);
     delay(on);
     digitalWrite(yellowLEDPin,LOW);
     delay(off);  
  }}

  Serial.println("\nHappy Holidays! You are very special and I love you.");
  delay(200000);
  


}
