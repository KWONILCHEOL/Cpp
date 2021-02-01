// [G5]1747 �Ҽ�&�Ӹ����
// https://www.acmicpc.net/problem/1747
/*
	�Ҽ��̸鼭 N���� ũ�ų� ����, ���� ���� �Ӹ���� �� ���ϱ�
	1. �Ҽ� ã��
	1-1. N���� ũ�ų� ������ �Ӹ���� Ȯ��
*/

#include<cstdio>
#pragma warning(disable: 4996)
bool primes[1200001];
bool isPalindrome(int x) {
	int len = 1;
	int temp[7] = { x % 10 };

	while (x /= 10) 
		temp[len++] = x % 10;
	
	for (int i = 0; i < len / 2; i++) 
		if (temp[i] != temp[len - 1 - i])
			return false;

	return true;
}
int main() {
	int n;
	scanf("%d", &n);
	
	if (n > 98689) { 
		printf("1003001");
		return 0; 
	}

	for (int i = 2; i <= 1200000; i += (i % 2 ? 2 : 1)){
		if (primes[i])
			continue;
		
		if (i >= n && isPalindrome(i)) {
			printf("%d", i);
			return 0;
		}

		for (int j = i + i; j <= 1200000; j += i)
			primes[j] = true;
	}
}