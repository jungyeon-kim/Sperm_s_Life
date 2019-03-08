#include "stdafx.h"
#include "title.h"

Title::Title()
{
	start = false;
}

void Title::drawStick()
{
	glScalef(4, 1, 1);
	glColor3f(0.5, 1.0, 0);
	glutSolidCube(5);
}

void Title::draw()
{
	// S
	{
		glPushMatrix();
		glTranslatef(-105, 80, 140);
		drawStick();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-112.5, 67.5, 140);
		glRotatef(90, 0, 0, 1);
		drawStick();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-105, 60, 140);
		drawStick();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-97.5, 50, 140);
		glRotatef(90, 0, 0, 1);
		drawStick();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-105, 42.5, 140);
		drawStick();
		glPopMatrix();
	}
	glTranslatef(30, 0, 0);
	// P
	{
		glPushMatrix();
		glTranslatef(-105, 80, 140);
		drawStick();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-112.5, 67.5, 140);
		glRotatef(90, 0, 0, 1);
		drawStick();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-97.5, 67.5, 140);
		glRotatef(90, 0, 0, 1);
		drawStick();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-105, 60, 140);
		drawStick();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-112.5, 50, 140);
		glRotatef(90, 0, 0, 1);
		drawStick();
		glPopMatrix();
	}
	glTranslatef(30, 0, 0);
	// E
	{
		glPushMatrix();
		glTranslatef(-105, 80, 140);
		drawStick();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-112.5, 67.5, 140);
		glRotatef(90, 0, 0, 1);
		drawStick();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-105, 60, 140);
		drawStick();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-112.5, 50, 140);
		glRotatef(90, 0, 0, 1);
		drawStick();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-105, 42.5, 140);
		drawStick();
		glPopMatrix();
	}
	glTranslatef(30, 0, 0);
	// R
	{
		glPushMatrix();
		glTranslatef(-105, 80, 140);
		drawStick();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-112.5, 67.5, 140);
		glRotatef(90, 0, 0, 1);
		drawStick();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-97.5, 67.5, 140);
		glRotatef(90, 0, 0, 1);
		drawStick();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-105, 60, 140);
		drawStick();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-112.5, 50, 140);
		glRotatef(90, 0, 0, 1);
		drawStick();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-102.5, 50, 140);
		glRotatef(-45, 0, 0, 1);
		drawStick();
		glPopMatrix();
	}
	glTranslatef(30, 0, 0);
	// M
	{
		glPushMatrix();
		glScalef(1, 1.2, 1);
		glTranslatef(-112.5, 59, 140);
		glRotatef(90, 0, 0, 1);
		drawStick();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-112.5, 50, 140);
		glRotatef(90, 0, 0, 1);
		drawStick();
		glPopMatrix();

		glPushMatrix();
		glScalef(1, 1.2, 1);
		glTranslatef(-97.5, 59, 140);
		glRotatef(90, 0, 0, 1);
		drawStick();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-97.5, 50, 140);
		glRotatef(90, 0, 0, 1);
		drawStick();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-110, 72.5, 140);
		glRotatef(-75, 0, 0, 1);
		drawStick();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-100, 72.5, 140);
		glRotatef(-105, 0, 0, 1);
		drawStick();
		glPopMatrix();
	}
	glTranslatef(30, 0, 0);
	// '
	{
		glPushMatrix();
		glScalef(0.25, 1, 1);
		glTranslatef(-450, 80, 140);
		drawStick();
		glPopMatrix();
		glTranslatef(15, 0, 0);
	}
	// S
	{
		glPushMatrix();
		glTranslatef(-105, 80, 140);
		drawStick();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-112.5, 67.5, 140);
		glRotatef(90, 0, 0, 1);
		drawStick();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-105, 60, 140);
		drawStick();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-97.5, 50, 140);
		glRotatef(90, 0, 0, 1);
		drawStick();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-105, 42.5, 140);
		drawStick();
		glPopMatrix();
	}
	// L
	{
		glPushMatrix();
		glScalef(1, 2, 1);
		glTranslatef(-247.5, 5, 140);
		glRotatef(90, 0, 0, 1);
		drawStick();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-235, -7.5, 140);
		drawStick();
		glPopMatrix();
	}
	// I
	{
		glPushMatrix();
		glScalef(1, 2, 1);
		glTranslatef(-210, 5, 140);
		glRotatef(90, 0, 0, 1);
		drawStick();
		glPopMatrix();
	}
	// F
	{
		glPushMatrix();
		glScalef(1, 2, 1);
		glTranslatef(-195, 5, 140);
		glRotatef(90, 0, 0, 1);
		drawStick();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-182.5, 10, 140);
		drawStick();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-182.5, 27.5, 140);
		drawStick();
		glPopMatrix();
	}
	// E
	{
		glPushMatrix();
		glScalef(1, 2, 1);
		glTranslatef(-162, 5, 140);
		glRotatef(90, 0, 0, 1);
		drawStick();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-149.5, 10, 140);
		drawStick();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-149.5, 27.5, 140);
		drawStick();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-149.5, -7.5, 140);
		drawStick();
		glPopMatrix();
	}
}