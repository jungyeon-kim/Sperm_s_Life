#pragma once

class Map;
class Virus;
class whiteBloodCell;

class Sperm
{
private:
	float realX, realY, realZ;
	float fakeX, fakeY, fakeZ;
	float sinHeight;
	float rotateSperm;
	float feverGague;
	int collideCount;
	int blinkCount;
	int shakeX, shakeCount, shakeStopCount;
	int feverRotateUnit;
	int speedBeforeFiver;
	bool collide;
	bool shake;
	bool feverCheck;
	bool endSoundCheck;
public:
	Sperm();
	void draw();
	void update(Map &map);
	void drawTail();
	void blinkRectAnimation();
	void shakeAnimation();
	void feverMode(Map &map);
	void collideVirus(Virus virus[], Map &map);
	void collideWBC(whiteBloodCell wBC[], Map map);

	bool getFeverCheck() { return feverCheck; }
};
