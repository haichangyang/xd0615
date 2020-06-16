int i;
void setup()
{
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  
}

void loop()
{
  for(i=0;i<8;i=i+2)
  {
  digitalWrite(i, HIGH);
  digitalWrite(i+1, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(i,LOW);
  digitalWrite(i+1,LOW);
  delay(500); // Wait for 1000 millisecond(s)
  }
}
