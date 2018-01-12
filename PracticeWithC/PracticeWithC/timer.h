#pragma once
#include <time.h>
#include <iostream>
using namespace std;

class Timer {
	clock_t startTime;
	clock_t endTime;
	bool isActivate;
public:
	Timer() : startTime(0), endTime(0), isActivate(false){}
	void Start()
	{
		startTime = clock();
		isActivate = true;
	}

	void End()
	{
		if (isActivate)
		{
			endTime = clock();
			cout << "������ �ð� : " << (float)(endTime - startTime) / CLOCKS_PER_SEC << endl;
			isActivate = false;
		}
		else
		{
			cout << "Ÿ�̸Ӱ� ���۵��� �ʾҽ��ϴ�." << endl;
		}
	}
};