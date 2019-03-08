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
#define VIRUS_NUM 4	// 바이러스 개수
#define WBC_NUM 2	// 백혈구 개수
#define MAX_SPEED 100	// 최대 스피드
#define FEVER_VALUE 1	// 피버게이지 차는 양 (MAX 10)
#define CLEAR_COUNT 180	// 클리어 조건

#define titleSound "./sound/titleSound.wav"
#define mainSound "./sound/mainSound.wav"
#define feverSound "./sound/feverSound.wav"
#define endSound "./sound/endSound.wav"

using namespace std;