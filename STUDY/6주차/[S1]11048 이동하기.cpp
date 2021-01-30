//[S1]11048 이동하기
//https://www.acmicpc.net/problem/11048

#include<iostream>
#pragma warning(disable: 4996)
#define MAX(A,B) ((A) > (B) ? (A) : (B))
int dp[1000][1000];
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			std::cin >> dp[i][j];

	for (int i = 1; i < n; i++)
		dp[i][0] += dp[i - 1][0];

	for (int j = 1; j < m; j++)
		dp[0][j] += dp[0][j - 1];

	for (int i = 1; i < n; i++) 
		for (int j = 1; j < m; j++) 
			dp[i][j] = MAX(dp[i][j-1], dp[i-1][j]) + dp[i][j];
	
	printf("%d", dp[n-1][m-1]);
}


int dp[1000];
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, m, x;
	std::cin >> n >> m;
	
	std::cin >> dp[0];
	for (int j = 1; j < m; j++) {
		std::cin >> dp[j];
		dp[j] += dp[j - 1];
	}

	for (int i = 1; i < n; i++) {
		std::cin >> x;
		dp[0] += x;
		for (int j = 1; j < m; j++) {
			std::cin >> x;
			dp[j] = MAX(dp[j - 1], dp[j]) + x;
		}
	}
	printf("%d", dp[m - 1]);
}