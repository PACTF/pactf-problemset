void kirbyStandCheck(void) {
if ((keyDown(KEY_RIGHT))) {
Player1.state = 1;
Player1.stateframe = 0;
}

if ((keyDown(KEY_LEFT))) {
Player1.state = 3;
Player1.stateframe = 0;
}

if (keyDown(KEY_A)) {
Player1.state = 4;
Player1.stateframe = 0;
}

if (!(Player1.land == 1)) {
Player1.state = 6;
Player1.stateframe = 0;
}


}

void kirbyWalkCheck(void) {
if (!(keyDown(KEY_RIGHT))) {
Player1.state = 0;
Player1.stateframe = 0;
}

if (keyDown(KEY_A)) {
Player1.state = 4;
Player1.stateframe = 0;
}

if (!(Player1.land == 1)) {
Player1.state = 6;
Player1.stateframe = 0;
}

}

void kirbyStandLeftCheck(void) {
if ((keyDown(KEY_RIGHT))) {
Player1.state = 1;
Player1.stateframe = 0;
}

if ((keyDown(KEY_LEFT))) {
Player1.state = 3;
Player1.stateframe = 0;
}

if (keyDown(KEY_A)) {
Player1.state = 7;
Player1.stateframe = 0;
}

if (!(Player1.land == 1)) {
Player1.state = 9;
Player1.stateframe = 0;
}
}

void kirbyWalkLeftCheck(void) {
if (!(keyDown(KEY_LEFT))) {
Player1.state = 2;
Player1.stateframe = 0;
}

if (keyDown(KEY_A)) {
Player1.state = 7;
Player1.stateframe = 0;
}

if (!(Player1.land == 1)) {
Player1.state = 9;
Player1.stateframe = 0;
}

}

void kirbyJumpRightRise(void) {
Player1.xspeed = 0;
if (keyDown(KEY_RIGHT)) {
Player1.xspeed = 4;
}

if (keyDown(KEY_LEFT)) {
Player1.xspeed = -4;
}

if (!keyDown(KEY_A)) {
Player1.state = 5;
Player1.stateframe = 0;
}

if (Player1.stateframe == 4) {
Player1.yaccel = 1;
}



}

void kirbyJumpRightFlip(void) {
Player1.xspeed = 0;
if (keyDown(KEY_RIGHT)) {
Player1.xspeed = 4;
}

if (keyDown(KEY_LEFT)) {
Player1.xspeed = -4;
}

if (Player1.land == 1) {
Player1.state = 0;
Player1.stateframe = 0;
}


}

void kirbyFallingRight(void) {
Player1.xspeed = 0;
if (keyDown(KEY_RIGHT)) {
Player1.xspeed = 4;
}

if (keyDown(KEY_LEFT)) {
Player1.xspeed = -4;
}

if (Player1.land == 1) {
Player1.state = 0;
Player1.stateframe = 0;
}

if (Player1.yspeed > 12) { Player1.yspeed = 12; }

}

void kirbyJumpLeftRise(void) {
Player1.xspeed = 0;
if (keyDown(KEY_RIGHT)) {
Player1.xspeed = 4;
}

if (keyDown(KEY_LEFT)) {
Player1.xspeed = -4;
}

if (!keyDown(KEY_A)) {
Player1.state = 8;
Player1.stateframe = 0;
}

if (Player1.stateframe == 4) {
Player1.yaccel = 1;
}
}

void kirbyJumpLeftFlip(void) {
Player1.xspeed = 0;
if (keyDown(KEY_RIGHT)) {
Player1.xspeed = 4;
}

if (keyDown(KEY_LEFT)) {
Player1.xspeed = -4;
}

if (Player1.land == 1) {
Player1.state = 2;
Player1.stateframe = 0;
}

}

void kirbyFallingLeft(void) {
Player1.xspeed = 0;
if (keyDown(KEY_RIGHT)) {
Player1.xspeed = 4;
}

if (keyDown(KEY_LEFT)) {
Player1.xspeed = -4;
}

if (Player1.land == 1) {
Player1.state = 2;
Player1.stateframe = 0;
}

if (Player1.yspeed > 12) { Player1.yspeed = 12; }

}

