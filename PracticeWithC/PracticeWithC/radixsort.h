#pragma once
#include <math.h>
#include "queue.h"
#include <stdio.h>
#include "utillity.h"

// ��� ����(radix sort)
// ���� �ð� : O(n*k) (n�� ������ ����, k�� �ڸ���)

// �� �ڸ����� ��ȸ�ذ��鼭 �ڸ��� ���� ���� �׷��� ������.
// ù ��° �ڸ����� ����..
// �� ��° �ڸ����� ����..
// k ��°���� �ݺ��Ѵ�.

// 0 ~ 9���� 10���� ��Ŷ�� �ʿ��ϴ�.
#define BUCKET_COUNT 10

void Radixsort(int data[], int length, int k)
{
	MyQueue<int> queue[BUCKET_COUNT];

	// k��ŭ �ݺ��Ѵ�.
	for (int i = 1; i <= k; ++i)
	{
	
		// �迭�� ��ȸ
		for (int j = 0; j < length; ++j)
		{
			// �� �ڸ����� ���� �����Ͽ� �� ���� �´� ��Ŷ�� �����Ѵ�.
			queue[extractNumofdigits(data[j], pow(10, i - 1))].Enqueue(data[j]);
		}

		// �����͸� ���ʷ� dequeue�Ͽ� �迭�� ����
		int current = 0;
		for (int j = 0; j < BUCKET_COUNT; ++j)
		{
			while (!queue[j].isEmpty())
			{
				QueueNode<int>* node = queue[j].Dequeue();
				data[current] = node->data;
				current++;
				delete node;
			}
		}

	}

}
