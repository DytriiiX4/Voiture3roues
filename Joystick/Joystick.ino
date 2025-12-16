int button = 2;
int xAxis = A0;
int yAxis = A1;

void setup() {
  // put your setup ode here, to run once:
  pinMode(button, INPUT_PULLUP);
  pinMode(xAxis, INPUT);
  pinMode(yAxis, INPUT);

  Serial.begin(9600);
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
  delay(250);
}
