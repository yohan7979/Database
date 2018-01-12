#pragma once
// ��������(merge sort)
// ��� �� �־� ���� �ð� : O(nlogn)
// �޸� : ��Ȳ�� ���� �ٸ�

// 1. �迭�� ���ݾ� ����
// 2. ������ ����
// 3. �ٽ� ����

// ���� 1��  Divide, ���� 2�� 3�� Conquer�� �ؼ�
// Divide & Conquer ������� ���Ѵ�.


// ������ �Ǵ� �迭�� �� �κ��� �ӽ� �迭�� �����ϰ�,
// ���� ������ ���� ����(left), ������ ������ ���� ����(right)�� ���� �� �迭�� ��ȸ�Ѵ�.
// ���� ���� ���� �迭�� ���ʷ� �ִ´�. 
// ��ȸ�� �Ϸ�� ��� ���ʿ� ���� ���Ҹ� ��� ������ �ִ´�.


void mergesort(int*, int);
void mergesort(int*, int*, int, int);
void merge(int*, int*, int, int, int);


// �ӽ� �迭 �޸��Ҵ�
void mergesort(int data[], int size)
{
	int* helper = new int[size];
	mergesort(data, helper, 0, size - 1);
	delete[] helper;
}

// ���� ����, ������ ���� �� �迭�� ��ȸ
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

// ���� �� ����
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