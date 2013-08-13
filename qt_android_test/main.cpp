/*
 *  qt-android demo for pcDuino
 *
 *  Copyright (C) 2013 Liaods <dongsheng.liao@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or (at
 *  your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
 */
#include <Arduino.h>

static int led_pin = 18;
static int button_pin = 8;
static int adc_val[6];
static int value;

void setup(void)
{
    pinMode(led_pin, OUTPUT);
    pinMode(button_pin, INPUT_PULLUP);
    Serial.begin(115200);
}

void loop(void)
{
    Serial.print("\n======================================================================\n");
    Serial.print("pcDuino Demo for qt-android v0.1\n");
    Serial.print("Serial test: Hello, pcDuino\n");
    Serial.print("pinMode/digitalWrite test: blinking TX LED\n");
    digitalWrite(led_pin, HIGH);
    Serial.print("digitalRead test: pin level of GPIO");
    Serial.print(button_pin, DEC);
    value = digitalRead(button_pin);
    Serial.println(value? ":HIGH":":LOW");

    Serial.print("analogRead test:");
    analogWrite(5, 0);
    analogWrite(6, 0);
    for( int i = 0; i<6; ++i)
    {
        adc_val[i] = analogRead(i);

        Serial.print(" A");
        Serial.print(i, DEC);
        Serial.print("(");
        Serial.print(adc_val[i], DEC);
        Serial.print(") ");
    }
    delay(1000);
    Serial.print("\nanalogWrite test: PWM5(520 Hz, 50% cycle) PWM6(781 Hz, 25% cycle)\n");
    analogWrite(5, pwmfreq_set(5, 520)/2);
    analogWrite(6, pwmfreq_set(6, 781)/4);
    Serial.print("======================================================================\n");
    digitalWrite(led_pin, LOW);
    delay(1000);
}

int main(void)
{
    init();
    setup();

    for (;;) {
        loop();
        if (serialEventRun) serialEventRun();
    }

    return 0;
}
