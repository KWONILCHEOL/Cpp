//[S1]1932 정수 삼각형
//https://www.acmicpc.net/problem/1932
//다이나믹 프로그래밍 DP
#include<iostream>
#define MAX(A,B) (A) > (B) ? (A) : (B)
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	int tri[500][500];
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			cin >> tri[i][j];

	for (int i = n - 1; i >= 0; i--)
		for (int j = 0; j < i; j++)
			tri[i - 1][j] += MAX(tri[i][j], tri[i][j + 1]);

	cout << tri[0][0];
}