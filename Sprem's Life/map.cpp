#include "stdafx.h"
#include "map.h"
#include "title.h"

Map::Map()
{
	translateRoad = 0;
	rotateRoad = 0;
	rotateValue = 2;
	speed = 10;
	firstPipe = -1150;
	secondPipe = -2930;
	thirdPipe = -4710;
	endOfPipe = 1780;
	type = 0;
	count = 1;
	stopRotate = true;
	endGame = false;
	stopTranslate = false;
}

void Map::init()
{
	speed = 10;
	rotateValue = 2;
}

void Map::draw(Title title)
{
	glLineWidth(3);
	//translateRoad = 맵 z축 이동
	//rotateRoad = 맵 회전

	glPushMatrix();
	{
		if (!stopTranslate)
			glTranslatef(0, 0, translateRoad + 400);
		//1번 통로 - 솔리드, 와이어
		glPushMatrix();
		{
			glTranslatef(0, 45, firstPipe);
			if (!stopRotate)
				randomColor();
			else
			{
				glRotatef(rotateRoad, 0, 0, 1);
				glColor3f(0.6, 0, 0.3);
			}
			glPushMatrix();
			{
				glScalef(1.5, 1.5, 10);
				glutWireTorus(90, 180, 30, 30);
			}
			glPopMatrix();
			if (!stopRotate)
				randomColor();
			else
				glColor3f(1, 0.6, 0.8);
			glPushMatrix();
			{
				glScalef(1.5, 1.5, 10);
				glutSolidTorus(88, 179, 30, 30);
			}
			glPopMatrix();
		}
		glPopMatrix();

		//2번 통로 - 솔리드, 와이어
		glPushMatrix();
		{
			glTranslatef(0, 45, secondPipe);
			if (!stopRotate)
				randomColor();
			else
			{
				glRotatef(rotateRoad, 0, 0, 1);
				glColor3f(0.6, 0, 0.3);
			}
			glPushMatrix();
			{
				glScalef(1.5, 1.5, 10);
				glutWireTorus(90, 180, 30, 30);
			}
			glPopMatrix();
			if (!stopRotate)
				randomColor();
			else
				glColor3f(1, 0.6, 0.8);
			glPushMatrix();
			{
				glScalef(1.5, 1.5, 10);
				glutSolidTorus(88, 179, 30, 30);
			}
			glPopMatrix();
		}
		glPopMatrix();

		//3번 통로 - 솔리드, 와이어
		glPushMatrix();
		{
			glTranslatef(0, 45, thirdPipe);
			if (!stopRotate)
				randomColor();
			else
			{
				glRotatef(rotateRoad, 0, 0, 1);
				glColor3f(0.6, 0, 0.3);
			}
			glPushMatrix();
			{
				glScalef(1.5f, 1.5f, 10.f);
				glutWireTorus(90, 180, 30, 30);
			}
			glPopMatrix();
			if (!stopRotate)
				randomColor();
			else
				glColor3f(1, 0.6, 0.8);
			glPushMatrix();
			{
				glScalef(1.5f, 1.5f, 10.f);
				glutSolidTorus(88, 179, 30, 30);
			}
			glPopMatrix();
		}
		glPopMatrix();

		if (endGame)
		{
			glPushMatrix();
			if (!stopTranslate)
				glTranslated(0, 0, (endOfPipe) * (count + 6) * -1);
			glColor3f(1, 0, 0);
			glutSolidSphere(100, 30, 30);
			glColor3f(0.8, 0, 0);
			glutWireSphere(101, 30, 30);
			glPopMatrix();
		}
	}
	glPopMatrix();
}

void Map::update(Title title)
{
	// 맵 이동속도
	if (!stopTranslate)
		translateRoad += speed;

	// 무한 스크롤링
	if (translateRoad >= endOfPipe * count && !endGame)
	{
		if (type % 3 == 0) firstPipe -= endOfPipe * 3;
		else if (type % 3 == 1) secondPipe -= endOfPipe * 3;
		else thirdPipe -= endOfPipe * 3;

		if (count == CLEAR_COUNT && title.getStart()) endGame = true;
		++count;
		++type;
	}

	if (endGame)
	{
		init();
		if (rotateView <= 15)
			rotateView += 0.05;
	}

	if (translateRoad >= endOfPipe * (count + 6) - 400)
		stopTranslate = true;
}

void Map::rotateUpdate()
{
	// 회전
	if (!endGame)
	{
		if (rRotateSwitch) rotateRoad -= rotateValue;
		if (lRotateSwitch) rotateRoad += rotateValue;
	}
}

void Map::randomColor()
{
	float R = (float)(rand() % 255 * 0.005);
	float G = (float)(rand() % 255 * 0.005);
	float B = (float)(rand() % 255 * 0.005);

	glColor3f(R, G, B);
}