const int STEP_1_IN = A0;
const int STEP_1_COM = 9;
const int THRESHOLD = 30;  //input pin must drop below this value to trigger
int sensor = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(STEP_1_IN, INPUT_PULLUP);
  pinMode(STEP_1_COM, OUTPUT);
  digitalWrite(STEP_1_COM, LOW);
  delay(500);
  Serial.begin(115200);
  delay(500);
  Serial.println("StairLight Test!");
}

void loop() {
  // put your main code here, to run repeatedly:
  sensor = analogRead(STEP_1_IN);  ///Test sensors: High Max 990-1023 (fluctuates), Low Min 15
  Serial.println(sensor);
  delay(100);
  if(sensor < THRESHOLD) {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else{
    digitalWrite(LED_BUILTIN, LOW);
  }
}
