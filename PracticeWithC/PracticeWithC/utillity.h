#pragma once

// 해당 자릿수의 수만 추출하기
// ex) 199의 백의 자리는 1이다.

int extractNumofdigits(int num, int digits)
{
	return num / digits % 10;
}

