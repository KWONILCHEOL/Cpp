// [S1]4889 안정적인 문자열
// https://www.acmicpc.net/problem/4889

#pragma warning(disable: 4996)
#include<cstdio>
int main() {
	for (int i = 1;; i++) {
		char str[2001];
		scanf(" %s", str);
		if (str[0] == '-')	break;
	
		int l = 0, r = 0;
		for (int j = 0; str[j] ; j++) {
			if (str[j] == '{') 
				l++;
			else if (str[j] == '}') {
				if (l == 0) r++;
				else l--;
			}
		}
		printf("%d. %d\n", i, (l >> 1) + (r >> 1) + (2 * (l % 2)));
	}
}