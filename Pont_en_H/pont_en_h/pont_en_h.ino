char infos;

int index = 0;

String speed1str;
String speed2str;

char state;
int speed1;
int speed2;

int in1 = 3;
int in2 = 4;
int ena = 5;
int enb = 6;
int in3 = 7;
int in4 = 8;

void stop() {
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);
  digitalWrite(ena, 0);
  digitalWrite(enb, 0);
}

void setup() {
  // put your setup code here, to run once:
  for (int i = 3; i < 9; i++) {
    pinMode(i, OUTPUT);
  }

  stop();
  Serial.begin(9600);
  delay(5000);
}

void avancer() {
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}

void reculer() {
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
}

void droite() {
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
}

void gauche() {
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}

void enableLeftRight(int bothWheelSpeed) {
  analogWrite(ena, bothWheelSpeed);
  analogWrite(enb, bothWheelSpeed);
}

void enableForwardBackward(int leftWheelSpeed, int rightWheelSpeed) {
  analogWrite(enb, leftWheelSpeed);
  analogWrite(ena, rightWheelSpeed);
}

void loop() {
  // put your main code here, to run repeatedly:
  index = 0;
  while (infos != '\n') {
    if (Serial.available())  {
      infos = Serial.read();
      Serial.print(infos);
      
      if (infos == '.') {
        index++;
      }
        else if (infos == '\n')  {
          index = 0;
          Serial.print(state);
          Serial.print(speed1str);
          Serial.print(speed2str);
        }
      else{
        if (index == 0) {
          state = infos;
        }
        else if (index == 1)  {
          speed1str += infos;
        }
        else {
          speed2str += infos;
        }
      }
    }
  }

  infos = '\0';
  speed1 = speed1str.toInt();
  speed2 = speed2str.toInt();

  if (state == 'a') {
    avancer();
    enableForwardBackward(speed1, speed2);
  }
  else if (state == 'r')  {
    reculer();
    enableForwardBackward(speed1, speed2);
  }
  else if (state == 'g')  {
    gauche();
    enableLeftRight(speed1);
  }
  else if (state == 'd')  {
    droite();
    enableLeftRight(speed1);
  }
  else {  stop();  }

  speed1str = "";
  speed2str = "";
}