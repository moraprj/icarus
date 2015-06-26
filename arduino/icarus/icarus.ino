#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
#include <Adafruit_BMP085_U.h>
#include <Adafruit_Simple_AHRS.h>
#include <SPI.h>
#include <SD.h>

// Create sensor instances.
Adafruit_LSM303_Accel_Unified accel(30301);
Adafruit_LSM303_Mag_Unified   mag(30302);
Adafruit_BMP085_Unified       bmp(18001);

// Create simple AHRS algorithm using the above sensors.
Adafruit_Simple_AHRS          ahrs(&accel, &mag);

// Update this with the correct SLP for accurate altitude measurements
float seaLevelPressure = SENSORS_PRESSURE_SEALEVELHPA;

// Chip Select SD Card
const int chipSelect = 4;

void setup()
{
  Serial.begin(115200);

  // Initialize the sensors.
  accel.begin();
  mag.begin();
  bmp.begin();

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
}

void loop(void)
{
  String data_sensor = "";
  char dato[20];
  sensors_vec_t   orientation;

  // Use the simple AHRS function to get the current orientation.
  if (ahrs.getOrientation(&orientation))
  {
    /* 'orientation' should have valid .roll and .pitch fields */
    data_sensor += String("R ") + String(orientation.roll) + String("\t\t");
    
    data_sensor += String("P ") + String(orientation.pitch) + String("\t\t");
    
    data_sensor += String("H ") + String(orientation.heading) + String("\t\t");
    
  }

  // Calculate the altitude using the barometric pressure sensor
  sensors_event_t bmp_event;
  bmp.getEvent(&bmp_event);
  if (bmp_event.pressure)
  {
    /* Get ambient temperature in C */
    float temperature;
    bmp.getTemperature(&temperature);
    /* Convert atmospheric pressure, SLP and temp to altitude */
    data_sensor += String("A ") + String(bmp.pressureToAltitude(seaLevelPressure, bmp_event.pressure, temperature)) + String("\t");
    
    /* Display the temperature */
    data_sensor += String("T ") + String(temperature);
  }

  Serial.println(data_sensor);

  // if the file is available, write to it:
  File dataFile = SD.open("datalog.txt", FILE_WRITE);
  if (dataFile) {
    dataFile.println(data_sensor);
    dataFile.close();
  } else {
    Serial.println("error SD Card");
  }

  delay(100);
}