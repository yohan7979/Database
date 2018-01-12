#pragma once
#include "swap.h"
#include <iostream>

// 퀵 정렬(Quicksort)
// 평균 실행 시간 : O(nlogn), 최악의 경우 O(n^2)
// 메모리 : O(logn)

// 원소 하나를 피봇으로 선택하고 피봇을 기준으로 두 배열로 분할
// 피봇보다 작은 값은 앞으로, 큰 값은 뒤로 보낸다. (swap 연산)
// 피봇이 중간값이냐 아니냐에 따라 그 성능이 결정된다.


int partition(int*, int, int);
void quicksort(int*, int, int);

void printall(int data[])
{
	for (int i = 0; i < 9; ++i)
	{
		std::cout << data[i] << " ";
	}
	cout << endl;
}

int partition(int data[], int left, int right)
{

	int pivot = data[right];
	cout << "피봇은 : " << pivot << endl;

	while (left <= right)
	{
		while (data[left] < pivot) left++;
		while (data[right] > pivot) right--;

		if (left <= right)
		{
			cout << data[left] << "와" << data[right] << " 스왑" << endl;
			
			Swap<int>(&data[left], &data[right]);
			left++;
			right--;
		}
	}
	printall(data);
	cout << "리턴 : " << data[left] << endl << endl;

	// left와 right가 만나는 위치와 pivot의 위치를 교환
	return left;

}


void quicksort(int data[], int left, int right)
{
	if (left < right)
	{
		int index = partition(data, left, right);
		quicksort(data, left, index - 1);
		quicksort(data, index, right);
	}

}