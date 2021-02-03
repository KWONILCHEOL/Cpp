//[S1]2294 µ¿Àü 2
//https://www.acmicpc.net/problem/2294

#include<cstdio>
#pragma warning(disable: 4996)
#define MIN(A,B) (A) < (B) ? (A) : (B)
int main() {
	int n, k;
	int arr[100];
	int dp[10001] = { 0 };

	scanf("%d %d", &n, &k);

	for (int i = 1; i <= k; i++)
		dp[i] = 10001;

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = 1; i <= k; i++)
		for (int j = 0; j < n; j++)
			if (i - arr[j] >= 0)
				dp[i] = MIN(dp[i], dp[i - arr[j]] + 1);

	printf("%d", dp[k] == 10001 ? -1 : dp[k]);
}