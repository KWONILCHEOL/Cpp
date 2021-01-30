// [S1]2608 로마 숫자
// https://www.acmicpc.net/problem/2608

#pragma warning(disable: 4996)
#include<cstdio>
char a[16], b[16], c[16];
int RomaToInt(char c) {
	switch(c){
	case 'I': return 1;
	case 'V': return 5;
	case 'X': return 10;
	case 'L': return 50;
	case 'C': return 100;
	case 'D': return 500;
	case 'M': return 1000;
	}
}
int main() {
	scanf("%s %s", a, b);
	int sum = 0, i, j, val;
	for (i = 0; a[i]; i++) {
		if (a[i + 1] != 0 && RomaToInt(a[i]) < RomaToInt(a[i + 1])) {
			sum += RomaToInt(a[i + 1]) - RomaToInt(a[i]);
			i++;
		}
		else 
			sum += RomaToInt(a[i]);
	}

	for (i = 0; b[i]; i++) {
		if (b[i + 1] != 0 && RomaToInt(b[i]) < RomaToInt(b[i + 1])) {
			sum += RomaToInt(b[i + 1]) - RomaToInt(b[i]);
			i++;
		}
		else 
			sum += RomaToInt(b[i]);
	}
	
	i = 0;
	val = sum;
	// 1000의 자리
	for (j = sum / 1000; j > 0; j--)
		c[i++] = 'M';
	sum %= 1000;
	
	// 100의 자리
	if (sum / 100 == 9) {
		c[i++] = 'C';
		c[i++] = 'M';
	}
	else {
		if (sum / 100 >= 5) {
			c[i++] = 'D';
			sum -= 500;
		}
		else if (sum / 100 == 4) {
			c[i++] = 'C';
			c[i++] = 'D';
			sum -= 400;
		}
		for (j = sum / 100; j > 0; j--)
			c[i++] = 'C';
	}
	sum %= 100;

	// 10의 자리
	if (sum / 10 == 9) {
		c[i++] = 'X';
		c[i++] = 'C';
		sum %= 10;
	}
	else {
		if (sum / 10 >= 5) {
			c[i++] = 'L';
			sum -= 50;
		}
		else if (sum / 10 == 4) {
			c[i++] = 'X';
			c[i++] = 'L';
			sum -= 40;
		}
		for (j = sum / 10; j > 0; j--)
			c[i++] = 'X';
	}
	sum %= 10;

	// 1의 자리
	if (sum == 9) {
		c[i++] = 'I';
		c[i++] = 'X';
	}
	else {
		if (sum >= 5) {
			c[i++] = 'V';
			sum -= 5;
		}
		else if (sum == 4) {
			c[i++] = 'I';
			c[i++] = 'V';
			sum -= 4;
		}
		for (j = sum; j > 0; j--)
			c[i++] = 'I';
	}

	printf("%d\n%s", val, c);

	return 0;
}
