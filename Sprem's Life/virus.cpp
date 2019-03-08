#include "stdafx.h"
#include "virus.h"
#include "map.h"

Virus::Virus()
{
	fakeX = 0;
	fakeY = -90;
	fakeZ = 0;
	size = 30;
	rotateLocation = rand() % 360;
}

void Virus::init()
{
	fakeZ = startZ;
	rotateLocation = rand() % 360;
}

void Virus::draw(Map map)
{
	glPushMatrix();
	{
		glTranslatef(0, 45, 0);
		glRotatef(rotateLocation + map.getRotateRoad(), 0, 0, 1);
		glTranslatef(fakeX, fakeY, fakeZ);
		glColor3f(0.1, 0.1, 0.1);
		glutSolidSphere(size, 10, 10);
		glColor3f(0.8, 0, 0);
		glLineWidth(7);
		glutWireSphere(size + 0.5, 5, 5);
	}
	glPopMatrix();
}

void Virus::update(Map map)
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