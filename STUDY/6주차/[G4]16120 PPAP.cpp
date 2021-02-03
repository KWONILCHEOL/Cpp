// [G4]16120 PPAP
// https://www.acmicpc.net/problem/16120
// P다음 P이면 +1, 아니고 AP이면 -1
#include<cstdio>
#include<cstring>
#pragma warning(disable: 4996)

int main() {
	char s[1000001];
	scanf("%s", s);
	
	int ans = 0;
	int len = strlen(s);

	if (s[0] == 'A')
		ans = -1;

	if (len % 3 != 1) {
		printf("NP");
		return 0;
	}

	for (int i = 0; i < len - 1;) {
		if (s[i + 1] == 'P') {
			ans++;
			i++;
		}
		else if (s[i + 1] == 'A' && s[i + 2] == 'P') {
			ans--;
			i += 2;
			if (ans < 0)
				break;
		}
		else {
			ans = -1;
			break;
		}
	}
	printf("%s", (ans == 0 ? "PPAP" : "NP"));
}