u32 kirbyFrames[] = { 0 , 10 , 10 , 1 , 1 , 1 , 1 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 3 , 3 , 3 , 3 , 4 , 4 , 5 , 5 , 6 , 6 , 6 , 6 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 8 , 8 , 8 , 8 , 9 , 9 , 11 , 21 , 21 , 12 , 12 , 12 , 12 , 13 , 13 , 13 , 13 , 13 , 13 , 13 , 13 , 14 , 14 , 14 , 14 , 15 , 15 , 16 , 16 , 17 , 17 , 17 , 17 , 18 , 18 , 18 , 18 , 18 , 18 , 18 , 18 , 19 , 19 , 19 , 19 , 20 , 20 , 22 , 22 , 22 , 22 , 22 , 22 , 22 , 22 , 22 , 22 , 22 , 22 , 22 , 22 , 22 , 22 , 22 , 22 , 22 , 22 , 22 , 22 , 22 , 22 , 22 , 22 , 22 , 23 , 23 , 24 , 24 , 25 , 25 , 26 , 26 , 27 , 27 , 28 , 28 , 28 , 29 , 29 , 30 , 30 , 31 , 31 , 31 , 31 , 31 , 31 , 31 , 31 , 31 , 31 , 31 , 31 , 31 , 31 , 31 , 31 , 31 , 31 , 31 , 31 , 31 , 31 , 31 , 31 , 31 , 31 , 31 , 32 , 32 , 33 , 33 , 34 , 34 , 35 , 35 , 36 , 36 , 37 , 37 , 37 , 38 , 38 , 39 , 39 };
u32 kirbyStateFrames[] = { 0 , 1 , 41 , 42 , 82 , 109 , 122 , 126 , 153 , 166 };
u32 kirbyStateLength[] = { 1 , 40 , 1 , 40 , 27 , 13 , 4 , 27 , 13 , 4 };
u32 kirbyStateJumps[] = {0,1,2,3,5,6,6,8,9,9};
u32 kirbyXspeed[] = {0,4,0,-4,0,0,0,0,0,0};
u32 kirbyXspeedEnabled[] = { 1 , 1 , 1 , 1 , 0 , 0 , 0 , 0 , 0 , 0 };
u32 kirbyYspeed[] = {4,4,4,4,-16,0,0,-16,0,0};
u32 kirbyYspeedEnabled[] = { 1 , 1 , 1 , 1 , 1 , 1 , 0 , 1 , 1 , 0 };
u32 kirbyXaccel[] = {0,0,0,0,0,0,0,0,0,0};
u32 kirbyXaccelEnabled[] = { 1 , 1 , 1 , 1 , 0 , 0 , 0 , 0 , 0 , 0 };
u32 kirbyYaccel[] = {0,0,0,0,0,1,1,0,1,1};
u32 kirbyYaccelEnabled[] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 0 , 1 , 1 };

void kirbyStandCheck(void);
void kirbyWalkCheck(void);
void kirbyStandLeftCheck(void);
void kirbyWalkLeftCheck(void);
void kirbyJumpRightRise(void);
void kirbyJumpRightFlip(void);
void kirbyFallingRight(void);
void kirbyJumpLeftRise(void);
void kirbyJumpLeftFlip(void);
void kirbyFallingLeft(void);

//function array:
void (*kirbyRunFunc[])(void)  = {
&kirbyStandCheck,
&kirbyWalkCheck,
&kirbyStandLeftCheck,
&kirbyWalkLeftCheck,
&kirbyJumpRightRise,
&kirbyJumpRightFlip,
&kirbyFallingRight,
&kirbyJumpLeftRise,
&kirbyJumpLeftFlip,
&kirbyFallingLeft
};
