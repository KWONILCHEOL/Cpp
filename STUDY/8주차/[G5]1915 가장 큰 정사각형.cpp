// [G5]1915 가장 큰 정사각형
// https://www.acmicpc.net/problem/1915

#include<iostream>
#include<queue>
#define MAX(A,B) ((A) > (B) ? (A) : (B))
#pragma warning(disable: 4996)
char arr[1000][1000];
int temp[1000][1000];
int ans = 0;
int min(int a, int b, int c) {
	if (a > b) a = b;
	if (a > c) a = c;
	return a;
}
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];

	for (int i = 0; i < n; i++) {
		temp[i][0] = arr[i][0] - '0';
		temp[0][i] = arr[0][i] - '0';
		ans = MAX(MAX(ans, temp[i][0]), temp[0][i]);
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (arr[i][j] == '1') {
				temp[i][j] = (min(temp[i - 1][j], temp[i][j - 1], temp[i - 1][j - 1]) + 1);
				ans = MAX(ans, temp[i][j]);
			}
		}
	}

	printf("%d", ans * ans);
}