#include<cstdio>
#include<cmath>
#pragma warning(disable: 4996)
long long a, b, x, n, nine, start;
int main() {
	scanf("%lld %lld", &a, &b);
	
	if (b < 10) {
		printf("%lld", b <= a ? b : -1);
		return 0;
	}

	for (int i = 2, start = 9, x = 9, nine = 90;;i++, start += nine, nine *= 10) {
		if (b < x + i * nine) {
			n = start + ((b - x + i - 1) / i);
			if (a < n)
				printf("-1");
			else {
				if ((b - x) % i == 0)
					printf("%lld", n % 10);
				else
					printf("%lld", (n / (int)pow(10, (i - ((b - x) % i)))) % 10);
			}
			return 0;
		}
		x = x + i * nine;
	}
}