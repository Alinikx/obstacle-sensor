//Sensore ad ultrasuoni utilizzato con arduino nano per rilevare la presenza di ostacoli

int ledPin1 = A3;      // Pin per il led rosso
int ledPin2 = A0;      // Pin per il led verde
int val = 0;  // variabile per conservare il valore letto
int trigPin = 2; //Trig
int echoPin = 3; //Echo
long duration, cm, inches;

void setup() {
  Serial.begin(9600);           //  setup serial
    pinMode(ledPin1, OUTPUT);   // dichiarazione di ledPin1 come OUTPUT
    pinMode(ledPin2, OUTPUT);   // dichiarazione di ledPin2 come OUTPUT
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop() {
 digitalWrite(trigPin, LOW);
 delayMicroseconds(5);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 pinMode(echoPin, INPUT);
 duration = pulseIn(echoPin, HIGH);
 cm = (duration/2) / 29.1;

 val = cm * 10;
 Serial.print(cm);
  Serial.println(" cm ");          // debug value


  if (cm > 150) { // ad una distanza maggiore di 150 cm non viene rilevato alcun ostacolo
  digitalWrite(ledPin2, HIGH);
}
else { // ad una distanza minore di 150 cm vengono rilevati gli ostacoli
    digitalWrite(ledPin2, LOW);
        // turn the ledPin on
  digitalWrite(ledPin1, HIGH);
  // stop the program for <sensorValue> milliseconds:
  delay(val);
  // turn the ledPin off:
  digitalWrite(ledPin1, LOW);
    // stop the program for for <sensorValue> milliseconds:
  delay(val);
  }
}
