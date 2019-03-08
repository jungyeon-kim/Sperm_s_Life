#include "stdafx.h"
#include "title.h"
#include "sperm.h"
#include "map.h"
#include "virus.h"
#include "whiteBloodCell.h"

void init();
void drawScene(void);
void reshape(int w, int h);
void timerFunction(int value);
void keyboard(unsigned char key, int x, int y);
void specialKeyboardDown(int key, int x, int y);
void specialKeyboardUp(int key, int x, int y);

int timer;

Title title;
Sperm sperm;
Map map;
Virus virus[VIRUS_NUM];
whiteBloodCell wBC[WBC_NUM];

void main(int argc, char *argv[])
{
	init();
	PlaySound(TEXT(titleSound), NULL, SND_ASYNC | SND_LOOP);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // 디스플레이 모드 설정
	glutInitWindowPosition(0, 0); // 윈도우의 위치지정
	glutInitWindowSize(WIDTH, HEIGHT); // 윈도우의 크기 지정
	glutCreateWindow("Sperm's Life"); // 윈도우 생성 (윈도우 이름)
	glutDisplayFunc(drawScene); // 출력 함수의 지정
	glutReshapeFunc(reshape);
	glutTimerFunc(15, timerFunction, 1);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeyboardDown);
	glutSpecialUpFunc(specialKeyboardUp);
	glutMainLoop();
}

void init()
{
	// 바이러스의 Z값
	int virusFakeZ[VIRUS_NUM];
	int virusCycle = 1000;	// 등장 주기
	int virusValue = -virusCycle;
	for (int i = 0; i < VIRUS_NUM; i++)
	{
		virusFakeZ[i] = virusValue - 3000;
		virusValue -= virusCycle;
		virus[i].setStartZ(virusCycle * -VIRUS_NUM);
		virus[i].setFakeZ(virusFakeZ[i]);
	}
	// 백혈구의 Z값
	int wBCFakeZ[WBC_NUM];
	int wBCCycle = 2700;	// 등장 주기
	int wBCValue = -wBCCycle;
	for (int i = 0; i < WBC_NUM; i++)
	{
		wBCFakeZ[i] = wBCValue - 3000;
		wBCValue -= wBCCycle;
		wBC[i].setStartZ(wBCCycle * -WBC_NUM);
		wBC[i].setFakeZ(wBCFakeZ[i]);
	}
}

void drawScene(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	// 드로우
	glPushMatrix();
	{
		if (map.getEndGame())
			glRotatef(map.getRotateView(), 0, 1, 0);
		if (!title.getStart())
		{
			glRotatef(10, 1, 0, 0);
			glRotatef(20, 0, 1, 0);
		}
		sperm.draw();
		map.draw(title);
		if (title.getStart())
		{
			for (int i = 0; i < VIRUS_NUM; i++) virus[i].draw(map);
			for (int i = 0; i < WBC_NUM; i++) wBC[i].draw(map);
		}
		if (!title.getStart())
			title.draw();
	}
	glPopMatrix();

	glutSwapBuffers();
}

void reshape(int w = WIDTH, int h = HEIGHT)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(60.0, double(w) / h, 1.0, 4000.0); // 원근투영
	glTranslatef(0.0, 0.0, -300.0); // 시야확보

	glMatrixMode(GL_MODELVIEW);
}

void timerFunction(int value)
{
	// 업데이트
	sperm.update(map);
	map.update(title);
	if (title.getStart())
	{
		for (int i = 0; i < VIRUS_NUM; i++) virus[i].update(map);
		for (int i = 0; i < WBC_NUM; i++) wBC[i].update(map);

		// 충돌 체크
		sperm.collideVirus(virus, map);
		sperm.collideWBC(wBC, map);

		// 타이머
		timer++;
		timer = timer % 251;
		// 타이머에 따른 이동 속도, 회전 속도 증가
		if (timer == 250 && map.getSpeed() < MAX_SPEED)
		{
			map.setSpeed(map.getSpeed() + 5);
			map.setRotateValue(map.getRotateValue() + 0.5);
		}
	}
	glutTimerFunc(15, timerFunction, 1);

	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case VK_SPACE:
		if (!title.getStart())
		{
			PlaySound(TEXT(mainSound), NULL, SND_ASYNC | SND_LOOP);
			map.Map::Map();
			title.setStart(true);
			break;
		}
		else
			break;
	case VK_ESCAPE:
		exit(1);
		break;
	}

	glutPostRedisplay();
}

void specialKeyboardDown(int key, int x, int y)
{
	if (title.getStart() && sperm.getFeverCheck())
	{
		if (key == GLUT_KEY_RIGHT) map.setRRotateSwitch(true);
		if (key == GLUT_KEY_LEFT) map.setLRotateSwitch(true);
	}

	glutPostRedisplay();
}

void specialKeyboardUp(int key, int x, int y)
{
	if (title.getStart() && sperm.getFeverCheck())
	{
		if (key == GLUT_KEY_RIGHT) map.setRRotateSwitch(false);
		if (key == GLUT_KEY_LEFT) map.setLRotateSwitch(false);
	}

	glutPostRedisplay();
}