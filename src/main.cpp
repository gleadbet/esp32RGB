#if __has_include(<Arduino.h>)
#include <Arduino.h>
#else
#include <stdint.h>

// Allow host-side parsing/builds when the Arduino framework is unavailable.
static void delay(uint32_t) {}
#endif

#if __has_include(<Adafruit_NeoPixel.h>)
#include <Adafruit_NeoPixel.h>
#else

// Fallback declarations allow the project to compile until the library is added.
#define NEO_GRBW 0
#define NEO_KHZ800 0

class Adafruit_NeoPixel {
public:
	Adafruit_NeoPixel(uint16_t, uint8_t, uint8_t) {}
	void begin() {}
	void setBrightness(uint8_t) {}
	void setPixelColor(uint16_t, uint32_t) {}
	void show() {}
	uint32_t Color(uint8_t red, uint8_t green, uint8_t blue) {
		return (uint32_t(red) << 16) | (uint32_t(green) << 8) | blue;
	}
};
#endif

Adafruit_NeoPixel LED_RGB(1, 48, NEO_GRBW + NEO_KHZ800);

void setup() {
	LED_RGB.begin();
	LED_RGB.setBrightness(150);
}

void loop() {
	LED_RGB.setPixelColor(0, LED_RGB.Color(255, 8, 0));
	LED_RGB.show();
	delay(2000);

	LED_RGB.setPixelColor(0, LED_RGB.Color(0, 255, 0));
	LED_RGB.show();
	delay(2000);

	LED_RGB.setPixelColor(0, LED_RGB.Color(0, 0, 255));
	LED_RGB.show();
	delay(2000);

LED_RGB.Color(32, 0, 255);  // blue with a violet tint
	LED_RGB.show();
	delay(2000);
}