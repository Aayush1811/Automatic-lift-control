#define en 6
#define in1 5
#define in2 4

#define b1 8
#define b2 9
#define b3 10
#define p A0 
int fl = 0;

#define inputCLK 2
#define inputDT 3

int counter = 0;
int previousstateCLK;                      // strore previous state of clk
int currentstateCLK;

String y = "0";
int pot = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(en,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(b1,INPUT_PULLUP);
  pinMode(b2,INPUT_PULLUP);
  pinMode(b3,INPUT_PULLUP);
  pinMode(p,INPUT);
  pinMode(inputCLK,INPUT);
  pinMode(inputDT,INPUT);

  previousstateCLK = digitalRead(inputCLK);

}

void loop() {
  // put your main code here, to run repeatedly:
  int x1 = digitalRead(b1);
  int x2 = digitalRead(b2);
  int x3 = digitalRead(b3);
  int p1 = analogRead(p);
  int p2 = map(p1,0,1023,0,255);
  Serial.print(x1);
  Serial.print("  ");
  Serial.println(fl);

  currentstateCLK = digitalRead(inputCLK);

if(previousstateCLK != currentstateCLK  )                                // THIS MEANS PULSE OCCURE
{

  if(digitalRead(inputDT) != digitalRead(inputCLK))                // THIS MEANS ROTATE IN CCW
   { 
        Serial.print("h");
     
        counter--;
        Serial.println("CCW");
        Serial.print("COUNTER:");
        Serial.println(counter);
    }
   else
   { 
        Serial.print("h");
        counter++;
        Serial.println("CW");
        Serial.print("COUNTER:");
        Serial.println(counter);
   
   }
  
  

}
previousstateCLK = currentstateCLK ;

  if(x1 == 0)
  {
     fl = 1;
  
    
  }
  if(x2 == 0)
  {
     fl = 2;
  
  }
  if(x3 == 0)
  {
     fl = 3;
  
  }

  if(fl == 1)
  {
    
    if(counter<=42)
    {
       Serial.println("fl=1");
       digitalWrite(in1,0);
       digitalWrite(in2,1);
    }
    
     else if(fl==1 && counter>45)
      {
        digitalWrite(in1,1);
       digitalWrite(in2,0);
        
      }
    else
    {
      if(fl != 2)
      {
      digitalWrite(in1,0);
      digitalWrite(in2,0);
      }
    }
    
  }

  if(fl == 2)
  {
    if(counter<=82)
    {
       Serial.println("fl=2");
       digitalWrite(in1,0);
       digitalWrite(in2,1);
    }
    else
    {
    
      
      
      digitalWrite(in1,0);
      digitalWrite(in2,0);
      
    }
    
  }

  if(fl == 3)
  {
    if(counter >= 0)
    {
        digitalWrite(in1,1);
       digitalWrite(in2,0);
      
    }
    else
    {
       digitalWrite(in1,0);
       digitalWrite(in2,0);
    }
    
  }

  analogWrite(en,p2);
  
 

}
