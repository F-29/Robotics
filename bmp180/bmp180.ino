#include <SFE_BMP180.h>
#include <Wire.h>

SFE_BMP180 pressure;

#define ALTITUDE 1147 // Altitude of Electropeak Co. in meters [khorramabad: 1147]

void setup() {
    Serial.begin(9600);
    if (pressure.begin())
        Serial.println(" BMP180 init success ");
        Serial.println("==========================================================================");
    else
    {
        Serial.println("BMP180 init fail\n\n");
        Serial.println("Check connection and then reset");
        while (1);
    }

}

void loop() {

    char status;
    double T, P, p0, a;

    status = pressure.startTemperature();
    if (status != 0)
    {
        delay(status);
        status = pressure.getTemperature(T);
        if (status != 0)
        {

            Serial.print("temperature: ");
            Serial.print(T, 2);
            Serial.println(" deg C ");

            status = pressure.startPressure(3);
            if (status != 0)
            {
                delay(status);
                status = pressure.getPressure(P, T);
                if (status != 0)
                {
                    Serial.print("absolute pressure: ");
                    Serial.print(P, 2);
                    Serial.print(" hpa = ");
                    Serial.print(P * 100, 2);
                    Serial.print(" pa = ");
                    Serial.print(P * 0.000986923, 2);
                    Serial.print(" atm = ");
                    Serial.print(P * 0.750063755, 2);
                    Serial.print(" mmHg = ");
                    Serial.print(P * 0.750061683, 2);

                    p0 = pressure.sealevel(P, ALTITUDE); // we're at 1147 meters 
                    Serial.print("\nrelative (sea-level) pressure: ");
                    Serial.print(p0, 2);
                    Serial.println(" hpa ");;

                    a = pressure.altitude(P, p0);
                    Serial.print("your altitude: ");
                    Serial.print(a, 0);
                    Serial.println(" meters ");
                }
                else Serial.println("error retrieving pressure measurement\n");
            }
            else Serial.println("error starting pressure measurement\n");
        }
        else Serial.println("error retrieving temperature measurement\n");
    }
    else Serial.println("error starting temperature measurement\n");
    Serial.println("==========================================================================");
    delay(1000);
}
