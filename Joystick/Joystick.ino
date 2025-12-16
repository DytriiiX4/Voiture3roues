// Broches du joystick
int button = 2;
int xAxis = A0;
int yAxis = A1;

// Broches du pont en H
int in1 = 3;
int in2 = 4;
int in3 = 5;
int in4 = 6;
char state = 's';

void stop()  {
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);
}

void setup() {
  // Joystick
  pinMode(button, INPUT_PULLUP);
  pinMode(xAxis, INPUT);
  pinMode(yAxis, INPUT);

  // Pont en H
  for (int i = 3; i < 7; i++) {
    pinMode(i, OUTPUT);
  }

  Serial.begin(9600);

  // Temps d'initialisation
  stop();
  Serial.println("stop");
  delay(5000);
}

void avancer()  {
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);

}

void reculer()  {
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
}

void droite()  {
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}

void gauche()  {
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
}

void loop() {
  int buttonPressed = digitalRead(button);
  int xAxisPos = analogRead(xAxis);
  int yAxisPos = analogRead(yAxis);
  Serial.println("Here're all the info u need.");
  Serial.print("Button Status : ");
  Serial.println(buttonPressed);
  Serial.print("Axis X Status : ");
  Serial.println(xAxisPos);
  Serial.print("Axis Y Status : ");
  Serial.println(yAxisPos);
  if (xAxisPos < 500) {
    Serial.println("avancer");
    avancer();
  }
  else if(xAxisPos > 530) {
    Serial.println("reculer");
    reculer();
  }
  else{
    if (yAxisPos < 510){
      Serial.println("gauche");
      gauche();
    }
    else if (yAxisPos > 530) {
      Serial.println("droite");
      droite();
    }
    else  {
      Serial.println("stop");
      stop();
    }
  }
  delay(10000);
}
