//Both of these libraries can be found in the NEOGPS library
#include <GPSport.h>
#include <NMEAGPS.h>

//Includes the AltSoftSerial library so that an additional Serial port can be emulated using digital pins 8 and 9
#include <AltSoftSerial.h>

//Creates an AltSoftSerial Object known as mySerial on pins 8 and 9
//Pin 8 is the rx
//Pin 9 is the tx
AltSoftSerial mySerial(8,9);

//These variables are used to store the current and past longintude, latitude and Altitude
float Log;
float Lat;
float Altitude;

NMEAGPS gps; // This parses the GPS characters
gps_fix fix; //This structure holds the GPS data

void setup() {
  //This command starts the softserial port GPSSerial at a baudrate of 9600
  GPSSerial.begin(9600);
  //This command starts the hardware serial at a baudrate of 57600
  Serial.begin(57600);
}

void loop() {
  //While there is GPS data available
  while(gps.available(GPSSerial))
  {
    //Reads the data from the GPS
    fix = gps.read();
    
    //If the received data appears to be valid GPS coordinates
    if(fix.valid.location)
    {
      //Stores the recorded GPS coordinates in the corresponding variables
      Log = fix.longitude();
      Lat = fix.latitude();
      Altitude = fix.altitude();

      //Prints the GPS data to the Serial Terminal
      Serial.print("Longitude: ");
      Serial.println(Log);
      Serial.print("Latitude: ");
      Serial.println(Lat);
      Serial.print("Altitude: ");
      Serial.println(Altitude);
    }
  }

}
