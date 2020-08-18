/*
*   Transmitter Code
*
*   ARDUINO UNO PINOUT :
*   CE   : 7
*   CSN  : 8
*   SCK  : 13
*   MOSI : 11
*   MISO : 12
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";
int i = 0;
const char text[32];
String txt = "";

void setup() {
    Serial.begin(9600);
    radio.begin();
    radio.openWritingPipe(address);
    radio.setPALevel(RF24_PA_MIN);
    radio.stopListening();
}

void loop() {
    txt = "";
    txt += "Receive : ";
    txt += i;
    txt.toCharArray(text, 32);

    radio.write(&text, sizeof(text));
    Serial.print("Send : ");
    Serial.println(i);
    i++;
    delay(1000);
}