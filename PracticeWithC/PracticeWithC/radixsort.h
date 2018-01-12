#pragma once
#include <math.h>
#include "queue.h"
#include <stdio.h>
#include "utillity.h"

// 기수 정렬(radix sort)
// 실행 시간 : O(n*k) (n은 원소의 갯수, k는 자릿수)

// 각 자릿수를 순회해가면서 자리의 값에 따라 그룹을 나눈다.
// 첫 번째 자릿수로 정렬..
// 두 번째 자릿수로 정렬..
// k 번째까지 반복한다.

// 0 ~ 9까지 10개의 버킷이 필요하다.
#define BUCKET_COUNT 10

void Radixsort(int data[], int length, int k)
{
	MyQueue<int> queue[BUCKET_COUNT];

	// k만큼 반복한다.
	for (int i = 1; i <= k; ++i)
	{
	
		// 배열을 순회
		for (int j = 0; j < length; ++j)
		{
			// 각 자릿수에 수를 추출하여 그 수에 맞는 버킷에 삽입한다.
			queue[extractNumofdigits(data[j], pow(10, i - 1))].Enqueue(data[j]);
		}

		// 데이터를 차례로 dequeue하여 배열을 갱신
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
