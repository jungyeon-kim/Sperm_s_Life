#include "stdafx.h"
#include "whiteBloodCell.h"
#include "map.h"

whiteBloodCell::whiteBloodCell()
{
	fakeX = 0;
	fakeY = -90;
	fakeZ = 0;
	size = 30;
	rotateLocation = rand() % 360;
}

void whiteBloodCell::init()
{
	fakeZ = startZ;
	rotateLocation = rand() % 360;
}

void whiteBloodCell::draw(Map map)
{
	glPushMatrix();
	{
		glTranslatef(0, 45, 0);
		glRotatef(rotateLocation + map.getRotateRoad(), 0, 0, 1);
		glTranslatef(fakeX, fakeY, fakeZ);
		glColor3f(0.9, 0.9, 0.9);
		glutSolidSphere(size - 8, 30, 30);
		glColor3f(1, 1, 0);
		glLineWidth(1);
		glutWireSphere(size, 50, 5);
	}
	glPopMatrix();
}

void whiteBloodCell::update(Map map)
{
	realX = fakeX;
	realY = fakeY + 45;
	realZ = fakeZ;

	// 이동
	fakeZ += map.getSpeed();

	// 회전
	if (map.getRRotateSwitch()) map.setRotateRoad(map.getRotateRoad() - map.getRotateValue());
	if (map.getRRotateSwitch()) map.setRotateRoad(map.getRotateRoad() + map.getRotateValue());

	// 초기화
	if (fakeZ >= 290 && map.getEndGame()) return;
	else if (fakeZ >= 300 && !map.getEndGame()) init();
}