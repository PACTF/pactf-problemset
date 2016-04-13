//
//Sprites
//

#ifndef GBA_SPRITES_H
#define GBA_SPRITES_H



//Attribute 0

#define ROTATION_FLAG     0x0100
#define SIZE_DOUBLE       0x0200
#define MODE_NORMAL       0x0000
#define MODE_TRANSPARENT  0x0400
#define MODE_WINDOWED     0x0800
#define MOSAIC            0x1000
#define COLOR_16          0x0000
#define COLOR_256         0x2000
#define SQUARE            0x0000
#define WIDE              0x4000
#define TALL              0x8000

//Attribute1

#define ROTDATA(n)        (n << 9)
#define HORIZONTAL_FLIP   0x1000
#define VERTICAL_FLIP     0x2000
#define SIZE_8            0x0000
#define SIZE_16           0x4000
#define SIZE_32           0x8000
#define SIZE_64           0xC000

//Attribute 2

#define PRIORITY(n)       ((n)<<10)
#define PALETTE(n)        ((n)<<12)

//sprite structure definitions



//sprite rotation data

typedef struct tagRotData
{
	u16 filler1[3];
	u16 pa;
	u16 filler2[3];
	u16 pb;
	u16 filler3[3];
	u16 pc;
	u16 filler4[3];
	u16 pd;
} RotData, *pRotData;

#endif

