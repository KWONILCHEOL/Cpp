// [S1]1713 후보 추천하기
// https://www.acmicpc.net/problem/1713

#pragma warning(disable: 4996)
#include<cstdio>

int frame[20][3];
bool check[101];
int main() {
	int n, m, s, _min;
	scanf(" %d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &s);
		if (check[s]) {
			for (int j = 0; j < n; j++) {
				if (frame[j][0] == s) {
					frame[j][1]++;
					break;
				}
			}
		}
		else {
			_min = 0;
			for (int j = 1; j < n; j++) 
				if (frame[_min][1] > frame[j][1]) 
					_min = j;
				else if (frame[_min][1] == frame[j][1] && frame[_min][2] > frame[j][2]) 
						_min = j;

			check[frame[_min][0]] = false;
			frame[_min][0] = s;
			frame[_min][1] = 1;
			frame[_min][2] = i;
			check[s] = true;
		}
	}
	for (int i = 1; i <= 100; i++) if (check[i]) printf("%d ", i);
}