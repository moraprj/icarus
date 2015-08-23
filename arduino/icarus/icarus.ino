#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
#include <Adafruit_BMP085_U.h>
#include <Adafruit_Simple_AHRS.h>
#include <SPI.h>

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

// Variables Geiger
int geiger_input = 2;
long count = 0;
long countPerMinute = 0;
long timePreviousMeassure = 0;
float pressure;

void setup()
{
  Serial.begin(115200);

  // Initialize the sensors.
  accel.begin();
  mag.begin();
  bmp.begin();

  // Initialize Geiger
  pinMode(geiger_input, INPUT);
  digitalWrite(geiger_input,HIGH);
  attachInterrupt(0,countPulse,FALLING);
}

void loop(void)
{
  String data_sensor = "D,";
  char dato[20];
  sensors_vec_t   orientation;

  // Use the simple AHRS function to get the current orientation.
  if (ahrs.getOrientation(&orientation))
  {
    /* 'orientation' should have valid .roll and .pitch fields */
    data_sensor += String(orientation.roll) + String(",");
    
    data_sensor += String(orientation.pitch) + String(",");
    
    data_sensor += String(orientation.heading) + String(",");
    
  }

  // Calculate the altitude using the barometric pressure sensor
  sensors_event_t bmp_event;
  bmp.getEvent(&bmp_event);
  if (bmp_event.pressure)
  {
    float temperature;
    bmp.getTemperature(&temperature);
    
    /* Get Pressure in kPa */
    bmp.getPressure(&pressure);
    data_sensor += String(pressure) + String(",");
    
    /* Convert atmospheric pressure, SLP and temp to altitude */
    data_sensor += String(bmp.pressureToAltitude(seaLevelPressure, bmp_event.pressure, temperature)) + String(",");
    
    /* Display the temperature */
    data_sensor += String(temperature);
  }

  Serial.println(data_sensor);

  delay(100);

  if (millis()-timePreviousMeassure > 10000){
    countPerMinute = 6*count;
    timePreviousMeassure = millis();
    char buffer[20];
    //Serial.print("#S|LOGTEST|[");
    String count_data = String("G, ") + String(pressure) + String(",") + String(countPerMinute);
    Serial.println(count_data);
    //Serial.println(itoa((countPerMinute), buffer, 10));
    //Serial.println("]#");
    count = 0;
  }
}


void countPulse(){
  detachInterrupt(0);
  count++;
  while(digitalRead(2)==0){
  }
  attachInterrupt(0,countPulse,FALLING);
}
