#pragma warning(disable: 4996)
#include<cstdio>
char map[200][201];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int main() {
	int r, c, n;
	scanf("%d %d %d", &r, &c, &n);
	for(int i=0; i < r; i++)
		scanf("%s", map[i]);
	printf("\n");
	if (n % 2 == 0) {
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				map[i][j] = 'O';
	}
	else if (n % 4 == 3) {
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++) 
				map[i][j] = map[i][j] == '.' ? 'O' : 'X';

		for (int x = 0; x < r; x++) {
			for (int y = 0; y < c; y++) {
				if (map[x][y] == 'X') {
					for (int i = 0; i < 4; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (nx < 0 || ny < 0 || nx == r || ny == c || map[nx][ny] == 'X')
							continue;
						map[nx][ny] = '.';
					}
					map[x][y] = '.';
				}
			}
		}
	}
	else if (n > 4) {
		for (int x = 0; x < r; x++) {
			for (int y = 0; y < c; y++) {
				if (map[x][y] == 'O') {
					for (int i = 0; i < 4; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (nx < 0 || ny < 0 || nx == r || ny == c || map[nx][ny] == 'O')
							continue;
						map[nx][ny] = 'X';
					}
				}
			}
		}
		for (int x = 0; x < r; x++) {
			for (int y = 0; y < c; y++) {
				if (map[x][y] == '.') {
					for (int i = 0; i < 4; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (nx < 0 || ny < 0 || nx == r || ny == c || map[nx][ny] == '.')
							continue;
						map[nx][ny] = 'N';
					}
				}
			}
		}
		for (int x = 0; x < r; x++)
			for (int y = 0; y < c; y++)
				map[x][y] = map[x][y] == 'X' ? 'O' : map[x][y] == 'N' ? '.' : map[x][y];
	}


	for (int i = 0; i < r; i++)
		printf("%s\n", map[i]);
}