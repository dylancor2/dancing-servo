int servo = 0;
int led = 1;
int slid = 28;
int leds [] = {14 ,15, 16, 17, 18, 19, 20, 21, 22, 26};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(servo, OUTPUT);
  for(int i = 0; i < 10; i++){
    pinMode(leds[i], OUTPUT);
  }
  digitalWrite(led, LOW);
}
void loop() {
  for(int i = 0; i < 180; i++){
    digitalWrite(servo, HIGH);
    delayMicroseconds(map(i, 0, 180, 1000, 2000));
    digitalWrite(servo, LOW);

    int powa = analogRead(slid);
    lights(powa);
    Serial.print("power - " );
    Serial.print(map(powa, 0, 1023, 0, 100));
    Serial.println("%");

    delay(map(powa, 0, 1023, 20, 0));
  }
  digitalWrite(led, HIGH);
  for(int i = 0; i < 180; i++){
    digitalWrite(servo, HIGH);
    delayMicroseconds(map(i, 180, 0, 1000, 2000));
    digitalWrite(servo, LOW);

    int powa = analogRead(slid);
    lights(powa);
    delay(map(powa, 0, 1023, 20, 0));
  }
  digitalWrite(led, LOW);
}

void lights(int powa){
  for(int i = 0; i < 10; i++){
    digitalWrite(leds[i], LOW);
  }
  for(int i = 0; i < map(powa, 0, 1023, 0, 10); i++){
    digitalWrite(leds[i], HIGH);
  }
}
