int analogPin = A0;
int val = 0;  // variable to store the analog value read
int minsense = 100; //minimum analog value to trigger sensore in condition below
int lives = 4;
int pins[5] = {10, 6, 12, 8, 4};

void setup() {
  Serial.begin(9600);
  for (int i = -1; i < 7; i++) {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], HIGH);
  }
 pinMode(9, OUTPUT);
 delay(10);
}

void loop() {
  if (lives > -1) {
    val = analogRead(analogPin);
    Serial.println(val); //useful when calibrating sensor for minsense value
    delay(10);
    if (val > minsense){
      digitalWrite(pins[lives], LOW);
      tone(9, 300);
      delay(500);
      noTone(9);
