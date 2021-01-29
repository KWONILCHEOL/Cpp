/*
	[S1]18405 경쟁적 전염
	https://www.acmicpc.net/problem/18405
*/
#include<cstdio>
#include<algorithm>
#pragma warning(disable: 4996)
using namespace std;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

struct NODE { int x, y, k; };
bool compare(NODE a, NODE b) { return a.k < b.k; }
int qSize, front, rear, cnt;
int n, k, a, b, c;
int main() {
	NODE q[40000];
	int board[200][200];
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j]) 
				q[rear++] = { i,j,board[i][j] };
		}
	}
	std::sort(&q[front], &q[rear], compare);
	cnt = qSize = rear;
	scanf("%d %d %d", &c, &a, &b);
	for (int i = 0; i < c; i++) {
		if (cnt == n * n)
			break;

		int size = qSize;
		for (int j = 0; j < size; j++) {
			NODE temp = q[front];
			front++;
			qSize--;

			for (int k = 0; k < 4; k++) {
				int nx = temp.x + dx[k];
				int ny = temp.y + dy[k];
				if (nx < 0 || ny < 0 || nx == n || ny == n)
					continue;
				if (board[nx][ny] == 0) {
					board[nx][ny] = temp.k;
					q[rear++] = { nx,ny,temp.k };
					qSize++;
					cnt++;
				}
			}
		}
	}
	printf("%d", board[a - 1][b - 1]);
}