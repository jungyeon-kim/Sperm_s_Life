#pragma once

class Title;

class Map
{
private:
	float translateRoad;
	float rotateRoad, rotateValue;
	float firstPipe, secondPipe, thirdPipe, endOfPipe;
	float rotateView;
	int type;
	int speed;
	int count;
	bool rRotateSwitch, lRotateSwitch;
	bool stopRotate, endGame, stopTranslate;
public:
	Map();
	void init();
	void draw(Title title);
	void update(Title title);
	void rotateUpdate();
	void randomColor();

	float getTranslateRoad() { return translateRoad; }
	float getRotateValue() { return rotateValue; }
	float getRotateRoad() { return rotateRoad; }
	float getRRotateSwitch() { return rRotateSwitch; }
	float getLRotateSwitch() { return lRotateSwitch; }
	float getEndOfPipe() { return endOfPipe; }
	float getRotateView() { return rotateView; }
	int getSpeed() { return speed; }
	bool getEndGame() { return endGame; }

	void setTranslateRoad(float x) { translateRoad = x; }
	void setRotateValue(float x) { rotateValue = x; }
	void setRotateRoad(float x) { rotateRoad = x; }
	void setRRotateSwitch(bool x) { rRotateSwitch = x; }
	void setLRotateSwitch(bool x) { lRotateSwitch = x; }
	void setStopRotate(bool x) { stopRotate = x; }
	void setSpeed(int x) { speed = x; }
};