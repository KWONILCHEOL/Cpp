// [S5]11723 집합
// https://www.acmicpc.net/problem/11723
// 비트마스킹

#include <cstdio>
using namespace std;
#pragma warning(disable: 4996)
int main()
{
	int n;
	char str[10];
	int x, s = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %d", str, &x);
		
		if (str[1] == 'd') {
			s |= (1 << x);
		}
		else if (str[1] == 'e') {
			if (((1 << x) & s) == (1 << x))
				s -= (1 << x);
		}
		else if (str[1] == 'h') {
			if (((1 << x) & s) == (1 << x))
				printf("1\n");
			else
				printf("0\n");
		}
		else if (str[1] == 'o') {
			s ^= (1 << x);
		}
		else if (str[1] == 'l') {
			s = (1 << 21) - 1;
		}
		else if (str[1] == 'm') {
			s = 0;
		}
	}
}