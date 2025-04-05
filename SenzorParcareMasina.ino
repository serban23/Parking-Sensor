
#include <Ultrasonic.h>
Ultrasonic ultrasonic(6,5);// 6 trigger ,5 echo

// Configurare pinii pentru buzzer si LED RGB
const int buzz = 7;
const int ledR = 9; // Pin LED rosu (PWM)
const int ledG = 10; // Pin LED verde (PWM)
const int ledB = 11; // Pin LED albastru (PWM)

void setup() {
    pinMode(buzz, OUTPUT);
    pinMode(ledR, OUTPUT);
    pinMode(ledG, OUTPUT);
    pinMode(ledB, OUTPUT);
}

void loop() {
    int dist = ultrasonic.read(CM);

    // filtrare zgomot: ignoram masuratorile peste 100cm
    if (dist > 100 || dist <= 0) {
        noTone(buzz);
        analogWrite(ledR, 0);
        analogWrite(ledG, 0);
        analogWrite(ledB, 255); // albastru 
        return;
    }

    // controlul beep-urilor 
    int pitch = map(dist, 1, 100, 2000, 500); // pitch mai mare cu apropierea
    tone(buzz, pitch); // frecventa variabila pentru beep
    delay(dist*1 0); 
    noTone(buzz);
    delay(dist*10); 

    if (dist < 20) {
        analogWrite(ledR, 255); // rosu
        analogWrite(ledG, 0);
        analogWrite(ledB, 0);
    } else if (dist < 50) {
        analogWrite(ledR, 255);
        analogWrite(ledG, 165); // galben
        analogWrite(ledB, 0);
    } else if (dist < 100) {
        analogWrite(ledR, 0);
        analogWrite(ledG, 255); // verde
        analogWrite(ledB, 0);
    } else {
        analogWrite(ledR, 0);
        analogWrite(ledG, 0);
        analogWrite(ledB, 255); // albastru
    }
}
