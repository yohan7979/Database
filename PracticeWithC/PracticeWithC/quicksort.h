#pragma once
#include "swap.h"
#include <iostream>

// �� ����(Quicksort)
// ��� ���� �ð� : O(nlogn), �־��� ��� O(n^2)
// �޸� : O(logn)

// ���� �ϳ��� �Ǻ����� �����ϰ� �Ǻ��� �������� �� �迭�� ����
// �Ǻ����� ���� ���� ������, ū ���� �ڷ� ������. (swap ����)
// �Ǻ��� �߰����̳� �ƴϳĿ� ���� �� ������ �����ȴ�.


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
	cout << "�Ǻ��� : " << pivot << endl;

	while (left <= right)
	{
		while (data[left] < pivot) left++;
		while (data[right] > pivot) right--;

		if (left <= right)
		{
			cout << data[left] << "��" << data[right] << " ����" << endl;
			
			Swap<int>(&data[left], &data[right]);
			left++;
			right--;
		}
	}
	printall(data);
	cout << "���� : " << data[left] << endl << endl;

	// left�� right�� ������ ��ġ�� pivot�� ��ġ�� ��ȯ
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