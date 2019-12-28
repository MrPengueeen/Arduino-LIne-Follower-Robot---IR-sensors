int Right_p = 2;
int Right_n = 3;
int Left_p = 4;
int Left_n = 5;
//int enable1 = 5;
//int enable2 = 6;
int sen2 = 0;
int sen3 = 0;
int sen5 = 0;
int sen6 = 0;
int sen7 = 0;
int sen9 = 0;
int sen10 = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(Left_p, OUTPUT);
  pinMode(Left_n, OUTPUT);
  pinMode(Right_p, OUTPUT);
  pinMode(Right_n, OUTPUT);
 // pinMode(enable1, OUTPUT);
 // pinMode(enable2, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A6, INPUT);

}
void forward() {
//  analogWrite(enable1, 255);
  //analogWrite(enable2, 255);
  digitalWrite(Left_p, HIGH);
  digitalWrite(Left_n, LOW);  
  digitalWrite(Right_n, HIGH);
  digitalWrite(Right_p, LOW);
}

void right() {
//  analogWrite(enable1, 255);
  //analogWrite(enable2, 255);
  digitalWrite(Left_p, HIGH);
  digitalWrite(Left_n, LOW);  
  digitalWrite(Right_n, LOW);
  digitalWrite(Right_p, HIGH);
}
void left() {
 // analogWrite(enable1, 255);
  //analogWrite(enable2, 255);
  digitalWrite(Left_p, LOW);
  digitalWrite(Left_n, HIGH);  
  digitalWrite(Right_n, HIGH);
  digitalWrite(Right_p, LOW);
}

void loop()

{

  sen2 = digitalRead(A0);
  sen3 = analogRead(A1);
  sen5 = analogRead(A2);
  sen6 = analogRead(A3);
  sen7 = analogRead(A4);
  sen9 = analogRead(A5);
  sen10 = digitalRead(A6);
  if (sen3 > 250)
    sen3 = 1;            
  else
    sen3 = 0;
  if (sen5 > 250)
    sen5 = 1;
  else
    sen5 = 0;
  if (sen6 > 250)
    sen6 = 1;
  else
    sen6 = 0;
  if (sen7 > 250)
    sen7 = 1;
  else
    sen7 = 0;
  if (sen9 > 250)
    sen9 = 1;
  else
    sen9 = 0;
  Serial.println(sen2);
  Serial.println(sen3);
  Serial.println(sen5);
  Serial.println(sen6);
  Serial.println(sen7);
  Serial.println(sen9);
  Serial.println(sen10);
  Serial.println();


  if (sen2 == 0 && sen5 == 1 && sen6 == 1 && sen7 == 1 && sen10 == 0)
  {
      forward();
      delay(50);
  }
  else if (sen2 == 0 && sen5 == 1 && sen6 == 1 && sen7 == 0 && sen10 == 0)
  {
      forward();
      delay(50);
  }
 else if (sen2 == 0 && sen5 == 0 && sen6 == 1 && sen7 == 1 && sen10 == 0)
  {
      forward();
      delay(50);
  }
//  analogWrite(enable1, 0);
//  analogWrite(enable2, 0);
//1st loop right
  if (sen2 == 0 && sen3 == 0 && sen5 == 0 && sen6 == 0 && sen10 == 1 && sen9 == 1)
  {
      right();
      delay(50);
  }
  else if (sen2 == 0 && sen3 == 0 && sen5 == 0 && sen10 == 1 && sen9 == 1)
  {
      right();
      delay(50);
  }
//ist loop left
  if (sen2 == 0 && sen3 == 0 &&  sen7 == 0 && sen10 == 0 && sen9 == 0)
  {
      left();
      delay(50);
  }
  else if (sen2 == 1 && sen3 == 0 && sen5 == 0  && sen10 == 0 && sen9 == 0)
  {
      left();
      delay(50);
  }  
}
