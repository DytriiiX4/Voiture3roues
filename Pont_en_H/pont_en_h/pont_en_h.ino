int in1 = 3;
int in2 = 4;
int in3 = 5;
int in4 = 6;

void setup() {
  // put your setup code here, to run once:
  for (int i = 3; i < 7; i++) {
    pinMode(i, OUTPUT);
  }

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //avant
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
}
