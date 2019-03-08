#include "stdafx.h"
#include "sperm.h"
#include "map.h"
#include "virus.h"
#include "whiteBloodCell.h"

Sperm::Sperm()
{
	fakeX = 0;
	fakeY = -120;
	fakeZ = 30;
	collideCount = 0;
	speedBeforeFiver = 0;
	feverGague = 0;
	feverCheck = true;
}

void Sperm::draw()
{
	if (!feverCheck)
		glRotatef(rotateSperm, 0, 0, 1);
	glPushMatrix();
	{
		sinHeight += 5.f;
		glScalef(0.5f, 0.5f, 1.5f);
		glTranslatef(fakeX, fakeY, fakeZ);
		glColor3d(0.9, 0.9 - (feverGague*0.1), 0.9 - (feverGague*0.1));
		glutSolidSphere(30, 30, 30);
		glPushMatrix();
		{
			glColor3d(0.7, 0.7 - (feverGague*0.1), 0.7 - (feverGague*0.1));
			glScalef(1.0f, 1.0f, 1.5f);
			glTranslated(0, 0, 20);
			glutSolidTorus(5, 8, 8, 8);
			glPushMatrix();
			{
				glRotatef(-90, 0, 1, 0);
				drawTail();
			}
			glPopMatrix();
			glPushMatrix();
			{
				glTranslatef(0, 0, 550);
				blinkRectAnimation();
			}
			glPopMatrix();
		}
		glPopMatrix();
	}
	glPopMatrix();

	shakeAnimation();
}

void Sperm::update(Map &map)
{
	realX = fakeX;
	realY = fakeY;
	realZ = fakeZ;

	feverMode(map);
	if (rotateSperm <= 720 && !feverCheck)
		rotateSperm += 1;

	// 피버일 때, 아닐 때 컨트롤
	if (feverCheck)	// false = fever mode
	{
		map.rotateUpdate();
		map.setStopRotate(true);
		if (!map.getEndGame())
		{
			if (map.getSpeed() >= MAX_SPEED)
				map.setSpeed(speedBeforeFiver);
			speedBeforeFiver = map.getSpeed();
			map.setSpeed(speedBeforeFiver);
		}
	}
	else
	{
		map.setLRotateSwitch(false);
		map.setRRotateSwitch(false);
		map.setStopRotate(false);
		map.setSpeed(MAX_SPEED);
	}
}


void Sperm::drawTail()
{
	float x, z;
	float radian = (float)3.141592 / 180;
	float num = 0;
	glLineWidth(5);
	glColor3d(1, 1 - (feverGague*0.1), 1 - (feverGague*0.1));
	glBegin(GL_LINE_STRIP);
	for (float i = 0; i < 280; i += 0.1)
	{
		int temp = i / 4;
		x = temp;
		z = (num * sin(2 * (sinHeight - i) * radian));
		if (num < 20)
			num += 0.01;

		glVertex3f(x, 0, z);
	}
	glEnd();
}

void Sperm::blinkRectAnimation()
{
	if (collide)
	{
		blinkCount++;
		glPushMatrix();
		{
			glColor3f(1, 0, 0);
			glutSolidCube(1000);
		}
		glPopMatrix();
	}
	if (blinkCount > 3)
	{
		collide = false;
		blinkCount = 0;
	}
}

void Sperm::shakeAnimation()
{
	if (collide)
		shake = true;
	if (shake)
	{
		shakeCount++;
		shakeStopCount++;
		shakeCount = shakeCount % 2;
		glTranslatef(shakeX, 0, 0);

		if (shakeCount == 0) shakeX = 15;
		else shakeX = -15;
	}
	if (shakeStopCount > 20)
	{
		shakeStopCount = 0;
		shake = false;
	}
}

void Sperm::feverMode(Map &map)
{
	if (feverGague == 10)
	{
		if (feverRotateUnit == 1)
			PlaySound(TEXT(feverSound), NULL, SND_ASYNC);

		feverCheck = false;
		feverRotateUnit += 1;
	}
	if (feverRotateUnit >= 720)
	{
		if (!map.getEndGame())
			PlaySound(TEXT(mainSound), NULL, SND_ASYNC);

		feverCheck = true;
		feverRotateUnit = 0;
		rotateSperm = 0;
		feverGague = 0;
	}
	if (map.getEndGame())
	{
		if (!endSoundCheck)
		{
			PlaySound(TEXT(endSound), NULL, SND_ASYNC);
			endSoundCheck = true;
		}
		feverCheck = true;
	}
}

void Sperm::collideVirus(Virus virus[], Map &map)	// 참조이유: call-by-value (맵복사)
{
	float limitedRotateRoad[VIRUS_NUM];	// 충돌체크용 회전각도

	for (int i = 0; i < VIRUS_NUM; i++)
	{
		limitedRotateRoad[i] = virus[i].getRotateLocation() + map.getRotateRoad();
		if (limitedRotateRoad[i] >= 360 * (collideCount + 1)) collideCount++;
		if (limitedRotateRoad[i] <= 360 * (collideCount - 1)) collideCount--;

		if (virus[i].getRealZ() > realZ - 50 && virus[i].getRealZ() < realZ + 50 && !map.getEndGame() && feverCheck)
			if ((limitedRotateRoad[i] > -20 + 360 * collideCount && limitedRotateRoad[i] < 20 + 360 * collideCount) ||
				(limitedRotateRoad[i] < -340 + 360 * collideCount && limitedRotateRoad[i] > -360 + 360 * collideCount) ||
				(limitedRotateRoad[i] > 340 + 360 * collideCount && limitedRotateRoad[i] < 360 + 360 * collideCount))
			{
				map.init();
				virus[i].init();
				feverGague = 0;
				collide = true;
			}
	}
}

void Sperm::collideWBC(whiteBloodCell wBC[], Map map)
{
	float limitedRotateRoad[WBC_NUM];	// 충돌체크용 회전각도

	for (int i = 0; i < WBC_NUM; i++)
	{
		limitedRotateRoad[i] = wBC[i].getRotateLocation() + map.getRotateRoad();
		if (limitedRotateRoad[i] >= 360 * (collideCount + 1)) collideCount++;
		if (limitedRotateRoad[i] <= 360 * (collideCount - 1)) collideCount--;

		if (wBC[i].getRealZ() > realZ - 40 && wBC[i].getRealZ() < realZ + 40 && !map.getEndGame() && feverCheck)
			if ((limitedRotateRoad[i] > -20 + 360 * collideCount && limitedRotateRoad[i] < 20 + 360 * collideCount) ||
				(limitedRotateRoad[i] < -340 + 360 * collideCount && limitedRotateRoad[i] > -360 + 360 * collideCount) ||
				(limitedRotateRoad[i] > 340 + 360 * collideCount && limitedRotateRoad[i] < 360 + 360 * collideCount))
			{
				wBC[i].init();
				feverGague += FEVER_VALUE;
			}
	}
}