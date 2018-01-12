#pragma once
#include <iostream>

// ����� ���̳��� ���α׷���(�޸������̼�)
int fibonacci(int n, int memo[])
{
	if (n == 0 || n == 1) return n;
	if (memo[n] == 0)
	{
		memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
	}
	else
		std::cout << memo[n] << " : ĳ�� �� �״�� ��ȯ" << std::endl;
	return memo[n];
}

int fibonacci(int n)
{
	return fibonacci(n, new int[n + 1]());
}



// ����� ���̳��� ���α׷���
int fibonacci_up(int n)
{
	if (n == 0) return 0;
	int a = 0;
	int b = 1;
	for (int i = 2; i < n; ++i)
	{
		int c = a + b;
		a = b;
		b = c;
		std::cout << c << std::endl;
	}
	
	return a + b;
}


