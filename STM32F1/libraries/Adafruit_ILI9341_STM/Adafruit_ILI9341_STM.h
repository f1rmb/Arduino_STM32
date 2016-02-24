/*
 See rights and use declaration in License.h
 This library has been modified for the Maple Mini
 */

#ifndef _ADAFRUIT_ILI9341H_
#define _ADAFRUIT_ILI9341H_

#include "Arduino.h"
#include "Print.h"
#include <Adafruit_GFX_AS.h>
#include <avr/pgmspace.h>

#define ILI9341_TFTWIDTH  240
#define ILI9341_TFTHEIGHT 320

#define ILI9341_NOP     0x00
#define ILI9341_SWRESET 0x01
#define ILI9341_RDDID   0x04
#define ILI9341_RDDST   0x09

#define ILI9341_SLPIN   0x10
#define ILI9341_SLPOUT  0x11
#define ILI9341_PTLON   0x12
#define ILI9341_NORON   0x13

#define ILI9341_RDMODE  0x0A
#define ILI9341_RDMADCTL  0x0B
#define ILI9341_RDPIXFMT  0x0C
#define ILI9341_RDIMGFMT  0x0A
#define ILI9341_RDSELFDIAG  0x0F

#define ILI9341_INVOFF  0x20
#define ILI9341_INVON   0x21
#define ILI9341_GAMMASET 0x26
#define ILI9341_DISPOFF 0x28
#define ILI9341_DISPON  0x29

#define ILI9341_CASET   0x2A
#define ILI9341_PASET   0x2B
#define ILI9341_RAMWR   0x2C
#define ILI9341_RAMRD   0x2E

#define ILI9341_PTLAR   0x30
#define ILI9341_MADCTL  0x36
#define ILI9341_PIXFMT  0x3A

#define ILI9341_FRMCTR1 0xB1
#define ILI9341_FRMCTR2 0xB2
#define ILI9341_FRMCTR3 0xB3
#define ILI9341_INVCTR  0xB4
#define ILI9341_DFUNCTR 0xB6

#define ILI9341_PWCTR1  0xC0
#define ILI9341_PWCTR2  0xC1
#define ILI9341_PWCTR3  0xC2
#define ILI9341_PWCTR4  0xC3
#define ILI9341_PWCTR5  0xC4
#define ILI9341_VMCTR1  0xC5
#define ILI9341_VMCTR2  0xC7

#define ILI9341_RDID1   0xDA
#define ILI9341_RDID2   0xDB
#define ILI9341_RDID3   0xDC
#define ILI9341_RDID4   0xDD

#define ILI9341_GMCTRP1 0xE0
#define ILI9341_GMCTRN1 0xE1
/*
 #define ILI9341_PWCTR6  0xFC
 */

#define ILI9341_VSCRSADD 0x37
#define ILI9341_VSCRDEF  0x33

#define ILI9341_MADCTL_MY  0x80
#define ILI9341_MADCTL_MX  0x40
#define ILI9341_MADCTL_MV  0x20
#define ILI9341_MADCTL_ML  0x10
#define ILI9341_MADCTL_RGB 0x00
#define ILI9341_MADCTL_BGR 0x08
#define ILI9341_MADCTL_MH  0x04

// Color definitions
#if 1
#define ILI9341_COLOR_ALICEBLUE 	0xF7DF
#define ILI9341_COLOR_ANTIQUEWHITE 	0xFF5A
#define ILI9341_COLOR_AQUA 			0x07FF
#define ILI9341_COLOR_AQUAMARINE 	0x7FFA
#define ILI9341_COLOR_AZURE 		0xF7FF
#define ILI9341_COLOR_BEIGE 		0xF7BB
#define ILI9341_COLOR_BISQUE 		0xFF38
#define ILI9341_COLOR_BLACK 		0x0000
#define ILI9341_COLOR_BLANCHEDALMOND 	0xFF59
#define ILI9341_COLOR_BLUE 			0x001F
#define ILI9341_COLOR_BLUEVIOLET 	0x895C
#define ILI9341_COLOR_BROWN 		0xA145
#define ILI9341_COLOR_BURLYWOOD 	0xDDD0
#define ILI9341_COLOR_CADETBLUE 	0x5CF4
#define ILI9341_COLOR_CHARTREUSE 	0x7FE0
#define ILI9341_COLOR_CHOCOLATE 	0xD343
#define ILI9341_COLOR_CORAL 		0xFBEA
#define ILI9341_COLOR_CORNFLOWERBLUE 	0x64BD
#define ILI9341_COLOR_CORNSILK 		0xFFDB
#define ILI9341_COLOR_CRIMSON 		0xD8A7
#define ILI9341_COLOR_CYAN 			0x07FF
#define ILI9341_COLOR_DARKBLUE 		0x0011
#define ILI9341_COLOR_DARKCYAN 		0x0451
#define ILI9341_COLOR_DARKGOLDENROD 0xBC21
#define ILI9341_COLOR_DARKGRAY2 	0xAD55
#define ILI9341_COLOR_DARKGREEN 	0x0320
#define ILI9341_COLOR_DARKKHAKI 	0xBDAD
#define ILI9341_COLOR_DARKMAGENTA 	0x8811
#define ILI9341_COLOR_DARKOLIVEGREEN 	0x5345
#define ILI9341_COLOR_DARKORANGE 	0xFC60
#define ILI9341_COLOR_DARKORCHID 	0x9999
#define ILI9341_COLOR_DARKRED 		0x8800
#define ILI9341_COLOR_DARKSALMON 	0xECAF
#define ILI9341_COLOR_DARKSEAGREEN 	0x8DF1
#define ILI9341_COLOR_DARKSLATEBLUE 0x49F1
#define ILI9341_COLOR_DARKSLATEGRAY 0x2A69
#define ILI9341_COLOR_DARKTURQUOISE 0x067A
#define ILI9341_COLOR_DARKVIOLET 	0x901A
#define ILI9341_COLOR_DEEPPINK 		0xF8B2
#define ILI9341_COLOR_DEEPSKYBLUE 	0x05FF
#define ILI9341_COLOR_DIMGRAY 		0x6B4D
#define ILI9341_COLOR_DODGERBLUE 	0x1C9F
#define ILI9341_COLOR_FIREBRICK 	0xB104
#define ILI9341_COLOR_FLORALWHITE 	0xFFDE
#define ILI9341_COLOR_FORESTGREEN 	0x2444
#define ILI9341_COLOR_FUCHSIA 		0xF81F
#define ILI9341_COLOR_GAINSBORO 	0xDEFB
#define ILI9341_COLOR_GHOSTWHITE 	0xFFDF
#define ILI9341_COLOR_GOLD 			0xFEA0
#define ILI9341_COLOR_GOLDENROD 	0xDD24
#define ILI9341_COLOR_GRAY  		0x8410
#define ILI9341_COLOR_GREEN 		0x0400
#define ILI9341_COLOR_GREENYELLOW 	0xAFE5
#define ILI9341_COLOR_HONEYDEW 		0xF7FE
#define ILI9341_COLOR_HOTPINK 		0xFB56
#define ILI9341_COLOR_INDIANRED 	0xCAEB
#define ILI9341_COLOR_INDIGO 		0x4810
#define ILI9341_COLOR_IVORY 		0xFFFE
#define ILI9341_COLOR_KHAKI 		0xF731
#define ILI9341_COLOR_LAVENDER 		0xE73F
#define ILI9341_COLOR_LAVENDERBLUSH 0xFF9E
#define ILI9341_COLOR_LAWNGREEN 	0x7FE0
#define ILI9341_COLOR_LEMONCHIFFON 0xFFD9
#define ILI9341_COLOR_LIGHTBLUE 	0xAEDC
#define ILI9341_COLOR_LIGHTCORAL 	0xF410
#define ILI9341_COLOR_LIGHTCYAN 	0xE7FF
#define ILI9341_COLOR_LIGHTGOLDENRODYELLOW 	0xFFDA
#define ILI9341_COLOR_LIGHTGREEN 	0x9772
#define ILI9341_COLOR_LIGHTGREY 	0xD69A
#define ILI9341_COLOR_LIGHTPINK 	0xFDB8
#define ILI9341_COLOR_LIGHTSALMON 	0xFD0F
#define ILI9341_COLOR_LIGHTSEAGREEN 	0x2595
#define ILI9341_COLOR_LIGHTSKYBLUE 		0x867F
#define ILI9341_COLOR_LIGHTSLATEGRAY 	0x7453
#define ILI9341_COLOR_LIGHTSTEELBLUE 	0xB63B
#define ILI9341_COLOR_LIGHTYELLOW 	0xFFFC
#define ILI9341_COLOR_LIME 			0x07E0
#define ILI9341_COLOR_LIMEGREEN 	0x3666
#define ILI9341_COLOR_LINEN 		0xFF9C
#define ILI9341_COLOR_MAGENTA 		0xF81F
#define ILI9341_COLOR_MAROON 		0x8000
#define ILI9341_COLOR_MEDIUMAQUAMARINE 	0x6675
#define ILI9341_COLOR_MEDIUMBLUE 	0x0019
#define ILI9341_COLOR_MEDIUMORCHID 	0xBABA
#define ILI9341_COLOR_MEDIUMPURPLE 	0x939B
#define ILI9341_COLOR_MEDIUMSEAGREEN 	0x3D8E
#define ILI9341_COLOR_MEDIUMSLATEBLUE 	0x7B5D
#define ILI9341_COLOR_MEDIUMSPRINGGREEN 0x07D3
#define ILI9341_COLOR_MEDIUMTURQUOISE 	0x4E99
#define ILI9341_COLOR_MEDIUMVIOLETRED 	0xC0B0
#define ILI9341_COLOR_MIDNIGHTBLUE 	0x18CE
#define ILI9341_COLOR_MINTCREAM 	0xF7FF
#define ILI9341_COLOR_MISTYROSE 	0xFF3C
#define ILI9341_COLOR_MOCCASIN 		0xFF36
#define ILI9341_COLOR_NAVAJOWHITE 	0xFEF5
#define ILI9341_COLOR_NAVY 			0x0010
#define ILI9341_COLOR_OLDLACE 		0xFFBC
#define ILI9341_COLOR_OLIVE 		0x8400
#define ILI9341_COLOR_OLIVEDRAB 	0x6C64
#define ILI9341_COLOR_ORANGE 		0xFD20
#define ILI9341_COLOR_ORANGERED 	0xFA20
#define ILI9341_COLOR_ORCHID 		0xDB9A
#define ILI9341_COLOR_PALEGOLDENROD 0xEF55
#define ILI9341_COLOR_PALEGREEN 	0x9FD3
#define ILI9341_COLOR_PALETURQUOISE 0xAF7D
#define ILI9341_COLOR_PALEVIOLETRED 0xDB92
#define ILI9341_COLOR_PAPAYAWHIP 	0xFF7A
#define ILI9341_COLOR_PEACHPUFF 	0xFED7
#define ILI9341_COLOR_PERU 			0xCC27
#define ILI9341_COLOR_PINK 			0xFE19
#define ILI9341_COLOR_PLUM 			0xDD1B
#define ILI9341_COLOR_POWDERBLUE 	0xB71C
#define ILI9341_COLOR_PURPLE 		0x8010
#define ILI9341_COLOR_RED 			0xF800
#define ILI9341_COLOR_ROSYBROWN 	0xBC71
#define ILI9341_COLOR_ROYALBLUE 	0x435C
#define ILI9341_COLOR_SADDLEBROWN 	0x8A22
#define ILI9341_COLOR_SALMON 		0xFC0E
#define ILI9341_COLOR_SANDYBROWN 	0xF52C
#define ILI9341_COLOR_SEAGREEN 		0x2C4A
#define ILI9341_COLOR_SEASHELL 		0xFFBD
#define ILI9341_COLOR_SIENNA 		0xA285
#define ILI9341_SILVER 				0xC618
#define ILI9341_COLOR_SKYBLUE 		0x867D
#define ILI9341_COLOR_SLATEBLUE 	0x6AD9
#define ILI9341_COLOR_SLATEGRAY 	0x7412
#define ILI9341_COLOR_SNOW 			0xFFDF
#define ILI9341_COLOR_SPRINGGREEN 	0x07EF
#define ILI9341_COLOR_STEELBLUE 	0x4416
#define ILI9341_COLOR_TAN 		 	0xD5B1
#define ILI9341_COLOR_TEAL 			0x0410
#define ILI9341_COLOR_THISTLE 		0xDDFB
#define ILI9341_COLOR_TOMATO 		0xFB08
#define ILI9341_COLOR_TURQUOISE   	0x471A
#define ILI9341_COLOR_VIOLET 	  	0xEC1D
#define ILI9341_COLOR_WHEAT			0xF6F6
#define ILI9341_COLOR_WHITE 		0xFFFF
#define ILI9341_COLOR_WHITESMOKE	0xF7BE
#define ILI9341_COLOR_YELLOW 		0xFFE0
#define ILI9341_COLOR_YELLOWGREEN 	0x9E66
// RMB
#define ILI9341_COLOR_DARKGRAY    	0x18E3      /*  30,  30,  30 */
#define ILI9341_COLOR_GRAY1        	0x3186 	  /*  50,  50,  50 */ // Darkish
#define ILI9341_COLOR_GRAY2       	0x39E7      /*  60,  60,  60 */ // Lighter
#define ILI9341_COLOR_GRAY3       	0x4A69      /*  76,  76,  76 */ // Even more lighter
#define ILI9341_COLOR_GRAY4         0x5ACB     /* 90, 90, 90 */ // Even lighter
#define ILI9341_COLOR_LIGHTGREY2    0x94B2     /* 150, 150, 150 */ //
#define ILI9341_COLOR_LIGHTGREY3    0xD6BA     /* 214, 214, 214 */ // *standard* in most GUI

#else
#define ILI9341_COLOR_BLACK       0x0000      /*   0,   0,   0 */
#define ILI9341_COLOR_NAVY        0x000F      /*   0,   0, 128 */
#define ILI9341_COLOR_DARKGREEN   0x03E0      /*   0, 128,   0 */
#define ILI9341_COLOR_DARKCYAN    0x03EF      /*   0, 128, 128 */
#define ILI9341_COLOR_MAROON      0x7800      /* 128,   0,   0 */
#define ILI9341_COLOR_PURPLE      0x780F      /* 128,   0, 128 */
#define ILI9341_COLOR_OLIVE       0x7BE0      /* 128, 128,   0 */
#define ILI9341_COLOR_LIGHTGREY   0xC618      /* 192, 192, 192 */
#define ILI9341_COLOR_DARKGREY    0x7BEF      /* 128, 128, 128 */
#define ILI9341_COLOR_BLUE        0x001F      /*   0,   0, 255 */
#define ILI9341_COLOR_GREEN       0x07E0      /*   0, 255,   0 */
#define ILI9341_COLOR_CYAN        0x07FF      /*   0, 255, 255 */
#define ILI9341_COLOR_RED         0xF800      /* 255,   0,   0 */
#define ILI9341_COLOR_MAGENTA     0xF81F      /* 255,   0, 255 */
#define ILI9341_COLOR_YELLOW      0xFFE0      /* 255, 255,   0 */
#define ILI9341_COLOR_WHITE       0xFFFF      /* 255, 255, 255 */
#define ILI9341_COLOR_ORANGE      0xFD20      /* 255, 165,   0 */
#define ILI9341_COLOR_GREENYELLOW 0xAFE5      /* 173, 255,  47 */
#define ILI9341_COLOR_PINK        0xF81F
#define ILI9341_COLOR_DARKGRAY    0x18E3      /*  30,  30,  30 */
#define ILI9341_COLOR_GRAY        0x3186 	  /*  50,  50,  50 */ // Darkish
#define ILI9341_COLOR_GRAY2       0x39E7      /*  60,  60,  60 */ // Lighter
#define ILI9341_COLOR_GRAY3       0x4A69      /*  76,  76,  76 */ // Even more lighter
#endif

class Adafruit_ILI9341_STM: public Adafruit_GFX
{

	public:

		Adafruit_ILI9341_STM(int8_t _CS, int8_t _DC, int8_t _MOSI, int8_t _SCLK, int8_t _RST, int8_t _MISO);
		Adafruit_ILI9341_STM(int8_t _CS, int8_t _DC, int8_t _RST = -1);

		void begin(void);
		void setAddrWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);
		void setVerticalScrollDefinition(uint16_t wTFA, uint16_t wBFA);
		void setVerticalScrollStartAddress(uint16_t wVSP);
		void pushColor(uint16_t color), fillScreen(uint16_t color);
#if defined (__STM32F1__)
		void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
#endif
		void drawPixel(int16_t x, int16_t y, uint16_t color);
		void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
		void drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color);
		void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
		void setRotation(uint8_t r);
		void invertDisplay(boolean i);
		uint16_t color565(uint8_t r, uint8_t g, uint8_t b);

		/* These are not for current use, 8-bit protocol only! */
		uint8_t readdata(void), readcommand8(uint8_t reg, uint8_t index = 0);
		/*
		 uint16_t readcommand16(uint8_t);
		 uint32_t readcommand32(uint8_t);
		 void     dummyclock(void);
		 */

		void spiwrite(uint8_t), writecommand(uint8_t c), writedata(uint8_t d), commandList(uint8_t *addr);
		uint8_t spiread(void);

	private:
		uint8_t tabcolor;

		boolean hwSPI;
#if defined (__AVR__) || defined(TEENSYDUINO)
		uint8_t mySPCR;
		volatile uint8_t *mosiport, *clkport, *dcport, *rsport, *csport;
		int8_t _cs, _dc, _rst, _mosi, _miso, _sclk;
		uint8_t mosipinmask, clkpinmask, cspinmask, dcpinmask;
#elif defined (__STM32F1__)
		volatile uint32 *mosiport, *clkport, *dcport, *rsport, *csport;
		uint32_t _cs, _dc, _rst, _mosi, _miso, _sclk;
		uint32_t mosipinmask, clkpinmask, cspinmask, dcpinmask;
		uint16_t lineBuffer[ILI9341_TFTHEIGHT]; // DMA buffer. 16bit color data per pixel
#elif defined (__arm__)
		volatile RwReg *mosiport, *clkport, *dcport, *rsport, *csport;
		uint32_t _cs, _dc, _rst, _mosi, _miso, _sclk;
		uint32_t mosipinmask, clkpinmask, cspinmask, dcpinmask;
#endif
};

#endif
