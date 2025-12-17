// Broches du joystick
int button = 2;
int xAxis = A0;
int yAxis = A1;

// Broches du pont en H
int in1 = 3;
int in2 = 4;
int ena = 5;
int enb = 6;
int in3 = 7;
int in4 = 8;
char state = 's';

void stop()  {
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);
  digitalWrite(ena, 0);
  digitalWrite(enb, 0);
}

void setup() {
  // Joystick
  pinMode(button, INPUT_PULLUP);
  pinMode(xAxis, INPUT);
  pinMode(yAxis, INPUT);

  // Pont en H
  for (int i = 3; i < 9; i++) {
    pinMode(i, OUTPUT);
  }

  Serial.begin(9600);

  // Temps d'initialisation
  stop();
  Serial.println("stop");
  delay(5000);
}

void avancer()  {
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);

}

void reculer()  {
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
}

void droite()  {
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
}

void gauche()  {
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}

void enableLeftRight(long yPos)  {
  long absol = abs(516-yPos);
  int bothWheelSpeed = (absol*100)/206;
  Serial.println(bothWheelSpeed);
  Serial.println(bothWheelSpeed);
  analogWrite(ena, bothWheelSpeed);
  analogWrite(enb, bothWheelSpeed);
  Serial.println(" ");
}

void enableForwardBackward(long xPos, long yPos)  {
  long absol = abs(516-xPos);
  int leftWheelSpeed = (((absol*100)/412)+((yPos*100)/825));
  int rightWheelSpeed =  (((absol*100)/412)+(((1023-yPos)*100)/825));
  analogWrite(enb, leftWheelSpeed);
  analogWrite(ena, rightWheelSpeed);
  // Serial.println(leftWheelSpeed);
  // Serial.println(rightWheelSpeed);
  // Serial.println(" ");
}

void loop() {
  int buttonPressed = digitalRead(button);
  long xAxisPos = analogRead(xAxis);
  long yAxisPos = analogRead(yAxis);
  // Serial.println("Here're all the info u need.");
  // Serial.print("Button Status : ");
  // Serial.println(buttonPressed);
  // Serial.print("Axis X Status : ");
  // Serial.println(xAxisPos);
  // Serial.print("Axis Y Status : ");
  // Serial.println(yAxisPos);
  if (xAxisPos < 500) {
    // Serial.println("avancer");
    avancer();
    enableForwardBackward(xAxisPos, yAxisPos);
  }
  else if(xAxisPos > 530) {
    // Serial.println("reculer");
    reculer();
    enableForwardBackward(xAxisPos, yAxisPos);
  }
  else{
    if (yAxisPos < 510){
      // Serial.println("gauche");
      gauche();
      enableLeftRight(yAxisPos);
    }
    else if (yAxisPos > 530) {
      // Serial.println("droite");
      droite();
      enableLeftRight(yAxisPos);
    }
    else  {
      // Serial.println("stop");
      stop();
    }
  }
}
