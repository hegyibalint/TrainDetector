#include <debouncer.h>
#include <arduino.h>

td::Debouncer debouncer;

void setup() {
    Serial.begin(115200);
    while (Serial.available());
    Serial.println("Initialized");

    analogReference(INTERNAL);
}

void loop() {
    while (true) {
        int sample = analogRead(0);
        bool quantitized = sample > 1000;
        td::EdgeDirection dir = debouncer.addSample(quantitized);
        delay(1);
    }
}