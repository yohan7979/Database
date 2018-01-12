#pragma once
#include <iostream>

// 하향식 다이나믹 프로그래밍(메모이제이션)
int fibonacci(int n, int memo[])
{
	if (n == 0 || n == 1) return n;
	if (memo[n] == 0)
	{
		memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
	}
	else
		std::cout << memo[n] << " : 캐쉬 값 그대로 반환" << std::endl;
	return memo[n];
}

int fibonacci(int n)
{
	return fibonacci(n, new int[n + 1]());
}



// 상향식 다이나믹 프로그래밍
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


