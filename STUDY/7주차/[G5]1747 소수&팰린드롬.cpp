// [G5]1747 소수&팰린드롬
// https://www.acmicpc.net/problem/1747
/*
	소수이면서 N보다 크거나 같고, 가장 작은 팰린드롬 수 구하기
	1. 소수 찾기
	1-1. N보다 크거나 같으면 팰린드롬 확인
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