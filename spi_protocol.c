// Jonathan Mitchell
// Team Stark Industries
// SPI Data Transfer to turn on PA on the Infineon BGT24MTR12
// The circuit
// * On the Infineon
// * MOSI = pin 20
// * CLK = pin 19
// * ChipSelect = pin 18
// * MISO — where you receive from slave
// On the Arduino
// * ChipSelect or Slave Select = digital pin 10 (CS or SS pin)
// * MOSI = digital pin 11 (MOSI pin)
// * CLK = digital pin 13 (SCK pin)
// B — connect this to ground
#include <SPI.h>
const int slaveSelectPin = 10;
void setup() {
pinMode (slaveSelectPin, OUTPUT); //configure pin to behave as output pin
//initialize SPI
SPI.setClockDivider(SPI_CLOCK_DIV2); //clock set to 8Mhz
SPI.begin(); //Initializes the SPI bus by setting SCK, MOSI, and SS to outputs, pulling SCK and MOSI low, and SS high
SPI.setBitOrder(MSBFIRST);
}
void loop()
{
digitalWrite(10,LOW); //low means 0V
//transfers one byte over SPI bus, sending and receiving
//this part sends in the first half of the bits to the register, bits 15–8
SPI.transfer(0b00100000);
//this part sends in the second half of the bits to the register as low, bits 7–0 
SPI.transfer(0b00000111); 
//clear the register, send 0’s through:

digitalWrite(10,HIGH);
}