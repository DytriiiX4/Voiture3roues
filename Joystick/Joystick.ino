String sending;

// Broches du joystick
int button = 2;
int xAxis = A0;
int yAxis = A1;

char state = 's';

void setup() {
  // Joystick
  pinMode(button, INPUT_PULLUP);
  pinMode(xAxis, INPUT);
  pinMode(yAxis, INPUT);

  Serial.begin(9600);
  delay(5000);
}

void enableForwardBackward(long xPos, long yPos) {
  long absol = abs(516 - xPos);
  int leftWheelSpeed = (((absol * 100) / 412) + ((yPos * 100) / 825));
  int rightWheelSpeed = (((absol * 100) / 412) + (((1023 - yPos) * 100) / 825));
  sending += '.';
  sending += leftWheelSpeed;
  sending += '.';
  sending += rightWheelSpeed;
}

void enableLeftRight(long yPos) {
  long absol = abs(516 - yPos);
  int bothWheelSpeed = (absol * 100) / 206;
  sending += '.';
  sending += bothWheelSpeed;
}

void loop() {
  long xAxisPos = analogRead(xAxis);
  long yAxisPos = analogRead(yAxis);

  if (xAxisPos < 500) {
    sending += 'a';
    enableForwardBackward(xAxisPos, yAxisPos);
  } else if (xAxisPos > 530) {
    sending += 'r';
    enableForwardBackward(xAxisPos, yAxisPos);
  } else {
    if (yAxisPos < 510) {
      sending += 'g';
      enableLeftRight(yAxisPos);
    } else if (yAxisPos > 530) {
      sending += 'd';
      enableLeftRight(yAxisPos);
    } else {
      sending += 's';
    }
  }
  sending += "\n";
  Serial.print(sending);
  sending = "";
  delay(100);
}