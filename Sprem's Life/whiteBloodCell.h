#pragma once

class Map;

class whiteBloodCell
{
private:
	float realX, realY, realZ;
	float fakeX, fakeY, fakeZ;
	float startZ;
	float size;
	float rotateLocation;
public:
	whiteBloodCell();
	void init();
	void draw(Map map);
	void update(Map map);

	float getRealZ() { return realZ; }
	float getRotateLocation() { return rotateLocation; }
	void setFakeZ(float x) { fakeZ = x; }
	void setStartZ(float x) { startZ = x; }
};