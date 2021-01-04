#include <Arduino.h>
#include "../lib/ELECHOUSE_CC1101/ELECHOUSE_CC1101.h"

#define size 60
byte buffer[size];

void setup() {
Serial.begin(9600);
ELECHOUSE_cc1101.Init();
ELECHOUSE_cc1101.SetReceive();
}

void loop() {
    if (ELECHOUSE_cc1101.CheckReceiveFlag()){
        int len = ELECHOUSE_cc1101.ReceiveData(buffer);
        for (int i = 0; i < len; ++i) {
            Serial.print((char)buffer[i]);
        }
        Serial.print('\n');
        ELECHOUSE_cc1101.SetReceive();
    }
}