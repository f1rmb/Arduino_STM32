#ifndef _ADAFRUIT_GFX_H
#define _ADAFRUIT_GFX_H

#include "Load_fonts.h"

#if ARDUINO >= 100
 #include "Arduino.h"
 #include "Print.h"
#else
 #include "WProgram.h"
#endif


// number representing the maximum angle (e.g. if 100, then if you pass in start=0 and end=50, you get a half circle)
// this can be changed with setArcParams function at runtime
#define DEFAULT_ARC_ANGLE_MAX 360

// rotational offset in degrees defining position of value 0 (-90 will put it at the top of circle)
// this can be changed with setAngleOffset function at runtime
#define DEFAULT_ANGLE_OFFSET -90


#define swap(a, b) { int16_t t = a; a = b; b = t; }

class Adafruit_GFX : public Print {

 public:

  Adafruit_GFX(int16_t w, int16_t h); // Constructor

  // This MUST be defined by the subclass:
  virtual void drawPixel(int16_t x, int16_t y, uint16_t color) = 0;

  // These MAY be overridden by the subclass to provide device-specific
  // optimized code.  Otherwise 'generic' versions are used.
  virtual void
    drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color),
    drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color),
    drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color),
    drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color),
    fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color),
    fillScreen(uint16_t color),
    invertDisplay(boolean i);

  // These exist only with Adafruit_GFX (no subclass overrides)
  void
    drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color),
    drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername,
      uint16_t color),
	ellipse(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color),//new
	drawBezier(int x0, int y0, int x1, int y1, int x2, int y2, uint16_t color),//new
    fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color),
    fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername,
      int16_t delta, uint16_t color),
    drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1,
      int16_t x2, int16_t y2, uint16_t color),
    fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1,
      int16_t x2, int16_t y2, uint16_t color),
    drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h,
      int16_t radius, uint16_t color),
    fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h,
      int16_t radius, uint16_t color),
    drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap,
      int16_t w, int16_t h, uint16_t color),
    drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color,
      uint16_t bg, uint8_t size),
    setCursor(int16_t x, int16_t y),
	getCursor(int16_t *x, int16_t *y),
    setTextColor(uint16_t c),
    setTextColor(uint16_t c, uint16_t bg),
    setTextSize(uint8_t s),
	setTextWrap(boolean w),
    setRotation(uint8_t r);

  uint8_t getTextSize();


  void setArcParams(float arcAngleMax);
  	void setAngleOffset(int16_t angleOffset);


    int16_t drawUnicode(uint16_t uniCode, int16_t x, int16_t y, int16_t size);
    int16_t drawNumber(long long_num,int16_t poX, int16_t poY, int16_t size);
    int16_t drawChar(char c, int16_t x, int16_t y, int16_t size);
    int16_t drawString(char *string, int16_t poX, int16_t poY, int16_t size);
    int16_t drawCentreString(char *string, int16_t dX, int16_t poY, int16_t size);
    int16_t drawRightString(char *string, int16_t dX, int16_t poY, int16_t size);
    int16_t drawFloat(float floatNumber,int16_t decimal,int16_t poX, int16_t poY, int16_t size);

#if ARDUINO >= 100
  virtual size_t write(uint8_t);
#else
  virtual void   write(uint8_t);
#endif

  int16_t
    height(void),
    width(void);

  uint8_t getRotation(void);

	inline __attribute__((always_inline))
		void fillArc(uint16_t x, uint16_t y, uint16_t radius, uint16_t thickness, float start, float end, uint16_t color)
	{
		if (start == 0 && end == _arcAngleMax)
			fillArcOffsetted(x, y, radius, thickness, 0, _arcAngleMax, color);
		else
			fillArcOffsetted(x, y, radius, thickness, start + (_angleOffset / (float)360)*_arcAngleMax, end + (_angleOffset / (float)360)*_arcAngleMax, color);
	}


 protected:
	void fillArcOffsetted(uint16_t cx, uint16_t cy, uint16_t radius, uint16_t thickness, float startAngle, float endAngle, uint16_t color);

	float cosDegrees(float angle)
	{
		//float radians = angle / (float)360 * 2 * PI;
		//Serial << "COS_LOOKUP angle:" << (float)angle << " radians:" << radians << " cos:" << cos(radians) << " return: " << cos(radians) * (double)65535 << endl;
		return cos(angle * DEG_TO_RAD);
	}

	float sinDegrees(float angle)
	{
		//float radians = angle / (float)360 * 2 * PI;
		//Serial << "SIN_LOOKUP angle:" << (float)angle << " radians:" << radians << " sin:" << sin(radians) << " return: " << sin(radians) * (double)65535 << endl;
		return sin(angle * DEG_TO_RAD);
	}

	float _arcAngleMax;
	int16_t _angleOffset;

 protected:
	const int16_t
    WIDTH, HEIGHT;   // This is the 'raw' display w/h - never changes
  int16_t
    _width, _height, // Display w/h as modified by current rotation
    cursor_x, cursor_y;
  uint16_t
    textcolor, textbgcolor;
  uint8_t
    textsize,
    rotation;
  boolean
    wrap; // If set, 'wrap' text at right edge of display

};

#endif // _ADAFRUIT_GFX_H
