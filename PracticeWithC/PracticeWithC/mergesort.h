#pragma once
// 병합정렬(merge sort)
// 평균 및 최악 실행 시간 : O(nlogn)
// 메모리 : 상황에 따라 다름

// 1. 배열을 절반씩 나눔
// 2. 각각을 정렬
// 3. 다시 병합

// 과정 1을  Divide, 과정 2와 3을 Conquer라 해서
// Divide & Conquer 방식으로 통한다.


// 병합이 되는 배열의 두 부분을 임시 배열에 복사하고,
// 왼쪽 절반의 시작 지점(left), 오른쪽 절반의 시작 지점(right)를 통해 두 배열을 순회한다.
// 작은 값을 원래 배열에 차례로 넣는다. 
// 순회가 완료된 경우 왼쪽에 남은 원소를 모두 복사해 넣는다.


void mergesort(int*, int);
void mergesort(int*, int*, int, int);
void merge(int*, int*, int, int, int);


// 임시 배열 메모리할당
void mergesort(int data[], int size)
{
	int* helper = new int[size];
	mergesort(data, helper, 0, size - 1);
	delete[] helper;
}

// 왼쪽 절반, 오른쪽 절반 두 배열을 순회
void mergesort(int data[], int helper[], int low, int high)
{
	if(low < high)
	{
		int middle = (low + high) / 2;
		mergesort(data, helper, low, middle);
		mergesort(data, helper, middle + 1, high);
		merge(data, helper, low, middle, high);
	}

}

// 정렬 후 병합
void merge(int data[], int helper[], int low, int middle, int high)
{
	for (int i = low; i <= high; ++i)
	{
		helper[i] = data[i];
	}

	int left = low;
	int right = middle + 1;
	int current = low;

	while (left <= middle && right <= high)
	{
		if (helper[left] <= helper[right])
		{
			data[current] = helper[left];
			left++;
		}
		else
		{
			data[current] = helper[right];
			right++;
		}
		current++;
	}

	int remaining = middle - left;
	for (int i = 0; i <= remaining; ++i)
	{
		data[current + i] = helper[left + i];
	}
}