#include "dispcnt.h"
#include "gba3.h"
#include "bg.h"
#include "gba_keys.h"
#include "gba_sprites.h"
#include "kirbystand.h"
#include "mariostand.h"




//Map Tiles Here
#include "debugtiles.h"
#include "debug.h"
#include "DebugCollide.h"


void DebugLevelScroll(void);
void CopyOAM(void);
void LevelDraw(void);
void DebugCharacterMove(void);
void FrameUpdate(void);
void PlayerPhysics(void);

//changed stuffses
#include "kirbyStates.h"







void stateUpdate(void);
void CollideCheck(void);





void BlankBlock(void);
void LandBlock(void);
void LeftEdge(void);
void RightEdge(void);
void EdgeHandler(void);
void LeftWall(void);
void RightWall(void);
void Filler(void);




void (*CollideBlock[])(void)  = {
   &BlankBlock,
   &LandBlock,
   &LeftEdge,
   &RightEdge,
   &EdgeHandler,
   &LeftWall,
   &RightWall,
   &Filler
};

//no more changed stuffies


OAMEntry sprites[128];
pRotData rotData = (pRotData)sprites;



u16* temp;
u16 loop;

Bg bg2;

typedef struct Character 
{
	s32 x;
	s32 y;
	s32 drawX;
	s32 drawY;
	u8 state; //Doubt seriously we'll need bigger numbers here than
	u8 laststate;
	u8 stateframe;
	u8 frame; // like, 50 maybe. Course, you never know...
	u16 xblock;
	u16 yblock;
	u8 xblockpos;
	u8 yblockpos;
	s8 xspeed;
	s8 yspeed;
	s8 xaccel;
	s8 yaccel;
	u8 land;
	u8 bounce;

}Character;

	Character Player1;

	Character Decoy;




int main() {
	SetMode( MODE_1 | BG2_ENABLE | OBJ_ENABLE | OBJ_MAP_1D);

	Player1.x = 1024;
	Player1.y = 1024;
	Player1.frame = 0;
	Player1.state = 0;
	Player1.stateframe = 0;

	
	
	
	Decoy.x = 1024;
	Decoy.y = 1024;
	

	bg2.number = 2;
	bg2.charBaseBlock = 0;
	bg2.screenBaseBlock = 28;
	bg2.colorMode = BG_COLOR_256;
	bg2.size = ROTBG_SIZE_512x512;
	bg2.mosaic = 0;
	bg2.x_scroll = 0;
	bg2.y_scroll = 0;
	bg2.DX = 0;
	bg2.DY = 0;
	bg2.PA = 256;
	bg2.PD = 256;

	EnableBackground(&bg2);
	
	memcpy( (u16 *)bg2.tileData, &debugtilesData, sizeof(debugtilesData) );
	
	temp = (u16*)Debug_map;
	for(loop = 0; loop < 2048; loop++) 
		bg2.mapData[loop] = temp[loop];

	memcpy( (u16 *)0x6010000, &kirbystandData, sizeof(kirbystandData) );
	memcpy( (u16 *)0x6010000 + (64*8), &mariostandData, sizeof(mariostandData) );
	memcpy( (u16 *)0x5000200, &kirbystandPalette, sizeof(kirbystandPalette) );
    

	rotData[0].pa = 256;
	rotData[0].pd = 256;
	
	sprites[0].attribute0 = COLOR_256 | SQUARE | ROTATION_FLAG | SIZE_DOUBLE | 80-32;
	sprites[0].attribute1 = SIZE_32 | ROTDATA(0) | 120-32;
	sprites[0].attribute2 = 0;

	sprites[1].attribute0 = COLOR_256 | SQUARE | ROTATION_FLAG | SIZE_DOUBLE | 80-32;
	sprites[1].attribute1 = SIZE_32 | ROTDATA(0) | 120+32;
	sprites[1].attribute2 = 32;

	LevelDraw();
	UpdateBackground(&bg2);
	WaitForVsync();
	memcpy( (u16 *)BGPaletteMem, &debugtilesPalette, sizeof(debugtilesPalette) );

	while(1) {
	
	stateUpdate();
	LevelDraw();
	FrameUpdate();
	WaitForVsync();
	UpdateBackground(&bg2);
	CopyOAM();
	
	}

	
	
	
			return 0;

}

//changed stuffses

void PlayerPhysics(void) {

Player1.x = Player1.x + Player1.xspeed;
Player1.y = Player1.y + Player1.yspeed;
Player1.xspeed = Player1.xspeed + Player1.xaccel;
Player1.yspeed = Player1.yspeed + Player1.yaccel;


}

void CollideCheck(void) {
	Player1.land = 0;
	Player1.bounce = 0;
	Player1.xblock = Player1.x/32;
	Player1.yblock = Player1.y/32;
	u16 collideblockNum = DebugCollide[Player1.xblock + (Player1.yblock * 64)];
	Player1.xblockpos = (Player1.x - (Player1.xblock * 32));
	Player1.yblockpos = (Player1.y - (Player1.yblock * 32));
	CollideBlock[collideblockNum]();






}

void BlankBlock(void) {

}

void LandBlock(void) {
	Player1.y = Player1.y - Player1.yblockpos;
	Player1.land = 1;
}

void LeftEdge(void) {
	Player1.y = Player1.y - Player1.yblockpos;
	Player1.land = 1;
}

void RightEdge(void) {
	Player1.y = Player1.y - Player1.yblockpos;
	Player1.land = 1;
}

void EdgeHandler(void) {

}

void LeftWall(void) {
	Player1.x = Player1.x - (Player1.xblockpos + 1);
	Player1.bounce = 1;
}

void RightWall(void) {
	Player1.x = Player1.x + (33 - Player1.xblockpos);
	Player1.bounce = 1;
}

void Filler(void) {

}

void stateUpdate(void) {
		Player1.laststate = Player1.state;
		Player1.frame = kirbyFrames[kirbyStateFrames[Player1.state] + Player1.stateframe];
		PlayerPhysics();
		CollideCheck();
		Player1.stateframe = Player1.stateframe + 1;
		kirbyRunFunc[Player1.state]();
			
		if (Player1.stateframe == kirbyStateLength[Player1.state]) {
			Player1.state = kirbyStateJumps[Player1.state];
			Player1.stateframe = 0;
		}

		if (Player1.state != Player1.laststate) {
			//Update Physics
			if (kirbyXspeedEnabled[Player1.state] == 1) {
				Player1.xspeed = kirbyXspeed[Player1.state];
			}
			if (kirbyYspeedEnabled[Player1.state] == 1) {
				Player1.yspeed = kirbyYspeed[Player1.state];
			}
			if (kirbyXaccelEnabled[Player1.state] == 1) {
				Player1.xaccel = kirbyXaccel[Player1.state];
			}
			if (kirbyYaccelEnabled[Player1.state] == 1) {
				Player1.yaccel = kirbyYaccel[Player1.state];
			}


		}


		











}

#include "kirbyFunctions.h"



//no more changed stuffies

void FrameUpdate(void) {
	memcpy( (u16 *)0x6010000, &kirbystandData + (Player1.frame), sizeof(kirbystandData) );
}


void DebugCharacterMove(void) {

	if (keyDown(KEY_LEFT)) Player1.x = Player1.x - 2;
	if (keyDown(KEY_RIGHT)) Player1.x = Player1.x + 2;
	if (keyDown(KEY_UP)) Player1.y = Player1.y - 2;
	if (keyDown(KEY_DOWN)) Player1.y = Player1.y + 2;
	if (keyDown(KEY_L)) Player1.frame = 0;
	if (keyDown(KEY_R)) Player1.frame = Player1.frame + 1;
	if (Player1.frame > 10) Player1.frame = 1;


}

void LevelDraw(void)
{
	s16 i = 0;
	s16 j = 0;
	s16 k = 0;
	s16 l = 0;
	s16 m = 0;
	s16 n = 0;
	s16 o = 0;

	//i = min (Player1.x , Decoy.x);
	i = Decoy.x;
	if (Player1.x < Decoy.x) i = Player1.x;
	//j = min (Player1.y , Decoy.y);
	j = Decoy.y;
	if (Player1.y < Decoy.y) j = Player1.y;
	//k = max (Player1.x , Decoy.x);
	k = Decoy.x;
	if (Player1.x > Decoy.x) k = Player1.x;
	//l = max (Player1.y , Decoy.y);
	l = Decoy.y;
	if (Player1.y > Decoy.y) l = Player1.y;

	i = i-192;
	j = j-192;
	k = k+192;
	l = l+192;


	m = k-i;
	n = l-j;

	if ((m/3) > (n/2)) o = 1;

	//Y + ((2/3)m)-n)/2;

	if (o == 1) {
	Player1.drawY = Player1.y + ((2 * m / 3) - n) / 2;
	Decoy.drawY = Decoy.y + ((2 * m / 3) - n) / 2;
		
	//Player1.drawY = Player1.y + (((2/3)*m)-n)/2;
	Player1.drawX = ((Player1.x - i) * 240) / m;
	Player1.drawY = ((Player1.drawY - j) * 240) / m;

	//Decoy.drawY = Decoy.y + ((2*(m-n)/3)/2);
	Decoy.drawX = ((Decoy.x - i) * 240) / m;
	Decoy.drawY = ((Decoy.drawY - j) * 240) / m;

	




	} else {
	Player1.drawX = Player1.x + ((3*n/2) - m)/2;
	Player1.drawX = ((Player1.drawX - i) * 160) / n;
	Player1.drawY = ((Player1.y - j) * 160) / n;
	
	Decoy.drawX = Decoy.x + ((3*n/2) - m)/2;
	Decoy.drawX = ((Decoy.drawX - i) * 160) / n;
	Decoy.drawY = ((Decoy.y - j) * 160) / n;

	}

	if (o == 1) {
		j = j - ((2 * m / 3) - n) / 2;
	} else {
		i = i - ((3*n/2) - m)/2;;
	}
	
	bg2.DX = i * 64;
	bg2.DY = j * 64;
	
	u8 mode = 240;
	if (o == 0) {
		m = n;
		mode = 160;
	}

	bg2.PA = ((m*64)/mode);
	bg2.PD = ((m*64)/mode);
	rotData[0].pa = bg2.PA;
	rotData[0].pd = bg2.PD;

	sprites[0].attribute0 = COLOR_256 | SQUARE | ROTATION_FLAG | SIZE_DOUBLE | ((Player1.drawY - 32) & 0x00FF);
	sprites[0].attribute1 = SIZE_32 | ROTDATA(0) | ((Player1.drawX - 32) & 0x01FF);
	

	sprites[1].attribute0 = COLOR_256 | SQUARE | ROTATION_FLAG | SIZE_DOUBLE | ((Decoy.drawY - 32) & 0x00FF);
	sprites[1].attribute1 = SIZE_32 | ROTDATA(0) | ((Decoy.drawX - 32) & 0x01FF);




}

void CopyOAM(void)
{
	u32 loop;
	u16* temp;
	temp = (u16*)sprites;
	for(loop = 0;loop < 128*4; loop++) {
		OAMmem[loop] = temp[loop];
	}
}


void DebugLevelScroll(void) {
	if (keyDown(KEY_LEFT)) {
		bg2.DX = bg2.DX - 128;
	}
	if (keyDown(KEY_RIGHT)) {
		bg2.DX = bg2.DX + 128;
	}

	if (keyDown(KEY_UP)) {
		bg2.DY = bg2.DY - 128;
	}

	if (keyDown(KEY_DOWN)) {
		bg2.DY = bg2.DY + 128;
	}

	if (keyDown(KEY_A)) {
		bg2.PA = bg2.PA + 1;
		bg2.PD = bg2.PD + 1;
		
	}
	if (keyDown(KEY_B)) {
		bg2.PA = bg2.PA - 1;
		bg2.PD = bg2.PD - 1;
	}
	rotData[0].pa = bg2.PA;
	rotData[0].pd = bg2.PD;
	

}



void EnableBackground(Bg* bg)
{
	u16 temp;

	bg->tileData = (u16*)CharBaseBlock(bg->charBaseBlock);
	bg->mapData = (u16*)ScreenBaseBlock(bg->screenBaseBlock);
	temp = bg->size | (bg->charBaseBlock<<CHAR_SHIFT) | (bg->screenBaseBlock<<SCREEN_SHIFT)
		| bg->colorMode | bg->mosaic | bg->wraparound;

	switch(bg->number)
	{
	case 0:
		{
			REG_BG0CNT = temp;
			REG_DISPCNT |= BG0_ENABLE;
		}break;
	case 1:
		{
			REG_BG1CNT = temp;
			REG_DISPCNT |= BG1_ENABLE;
		}break;
	case 2:
		{
			REG_BG2CNT = temp;
			REG_DISPCNT |= BG2_ENABLE;
		}break;
	case 3:
		{
			REG_BG3CNT = temp;
			REG_DISPCNT |= BG3_ENABLE;
		}break;

	default:break;

	}
}

void UpdateBackground(Bg* bg)
{
	switch(bg->number)
	{
	case 0:
		REG_BG0HOFS = bg->x_scroll;
		REG_BG0VOFS = bg->y_scroll;
		break;
	case 1:
		REG_BG1HOFS = bg->x_scroll;
		REG_BG1VOFS = bg->y_scroll;
		break;
	case 2:
		if(!(REG_DISPCNT & MODE_0))//it is a rot background
		{
			REG_BG2X = bg->DX;
			REG_BG2Y = bg->DY;

			REG_BG2PA = bg->PA;
			REG_BG2PB = bg->PB;
			REG_BG2PC = bg->PC;
			REG_BG2PD = bg->PD;
		}
		else  //it is a text background
		{
			REG_BG2HOFS = bg->x_scroll;
			REG_BG2VOFS = bg->y_scroll;
		}
		break;
	case 3:
		if(!(REG_DISPCNT & MODE_0))//it is a rot background
		{
			REG_BG3X = bg->DX;
			REG_BG3Y = bg->DY;

			REG_BG3PA = bg->PA;
			REG_BG3PB = bg->PB;
			REG_BG3PC = bg->PC;
			REG_BG3PD = bg->PD;
		}
		else //it is a text background
		{
			REG_BG3HOFS = bg->x_scroll;
			REG_BG3VOFS = bg->y_scroll;
		}
		break;
	default: break;
	}
}


