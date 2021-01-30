/*
	[G4]17140 이차원 배열과 연산
	https://www.acmicpc.net/problem/17140
	R() -> cols가 변함
	C() -> rows가 변함
*/
#include<cstdio>
#include<vector>
#include<algorithm>
#pragma warning(disable: 4996)
int r, c, k;
int rows = 2, cols = 2;
int board[100][100];

void init() {
	scanf("%d %d %d", &r, &c, &k);
	r -= 1;
	c -= 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &board[i][j]);

}

void getRow() {
	rows = 0;
	for (int j = 0; j < 100; j++)
		for (int i = 0; i < 100; i++)
			if (board[i][j] > 0)
				rows = rows > i ? rows : i;
}
void getCol() {
	cols = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (board[i][j] > 0)
				cols = cols > j ? cols : j;
}

void R() {
	for (int i = 0; i <= rows; i++) {
		std::vector<std::pair<int, int>> v;
		int arr[101] = { 0, };
		for (int j = 0; j <= cols; j++) {
			if (board[i][j] > 0) {
				arr[board[i][j]]++;
				board[i][j] = 0;
			}
		}
		
		for (int j = 0; j < 101; j++) {
			if (arr[j] > 0)
				v.push_back({ arr[j], j });
		}

		std::sort(v.begin(), v.end());
		for (int j = 0; j < v.size() && j < 50; j++) {
			board[i][j * 2] = v[j].second;
			board[i][j * 2 + 1] = v[j].first;
		}
	}
	getCol();
}

void C() {
	for (int j = 0; j <= cols; j++) {
		std::vector<std::pair<int, int>> v;
		int arr[101] = { 0, };
		for (int i = 0; i <= rows; i++) {
			if (board[i][j] > 0) {
				arr[board[i][j]]++;
				board[i][j] = 0;
			}
		}
		
		for (int i = 0; i < 101; i++) {
			if (arr[i] > 0)
				v.push_back({ arr[i],i });
		}
		
		std::sort(v.begin(), v.end());
		for (int i = 0; i < v.size() && i < 50; i++) {
			board[i * 2][j] = v[i].second;
			board[i * 2 + 1][j] = v[i].first;
		}
	}
	getRow();
}

int main() {
	init();
	if (board[r][c] == k) {
		printf("0");
		return 0;
	}

	for (int time = 1; time <= 100; time++) {
		rows >= cols ? R() : C();
		if (board[r][c] == k) {
			printf("%d", time);
			return 0;
		}
	}
	printf("-1");
}