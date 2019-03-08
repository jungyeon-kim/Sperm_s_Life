#pragma once
#pragma comment(lib, "winmm.lib")

#include <GL/freeglut.h>
#include <process.h>
#include <windows.h>
#include <iostream>
#include <math.h>
#include <mmsystem.h>

#define WIDTH 800
#define HEIGHT 600
#define VIRUS_NUM 4	// ���̷��� ����
#define WBC_NUM 2	// ������ ����
#define MAX_SPEED 100	// �ִ� ���ǵ�
#define FEVER_VALUE 1	// �ǹ������� ���� �� (MAX 10)
#define CLEAR_COUNT 180	// Ŭ���� ����

#define titleSound "./sound/titleSound.wav"
#define mainSound "./sound/mainSound.wav"
#define feverSound "./sound/feverSound.wav"
#define endSound "./sound/endSound.wav"

using namespace std;