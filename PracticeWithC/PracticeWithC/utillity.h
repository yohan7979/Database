#pragma once

// �ش� �ڸ����� ���� �����ϱ�
// ex) 199�� ���� �ڸ��� 1�̴�.

int extractNumofdigits(int num, int digits)
{
	return num / digits % 10;
}

