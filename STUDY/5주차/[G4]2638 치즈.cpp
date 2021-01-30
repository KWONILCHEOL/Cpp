/*
	[G4]2638 치즈
	https://www.acmicpc.net/problem/2638
*/
#include<cstdio>
#include<queue>
#pragma warning(disable: 4996)
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

int board[100][100];
int visited[100][100];
struct NODE {int x, y;};
int external = 0, cheese = 1, internal = 2;
std::queue<NODE> q1;	//치즈
std::queue<NODE> q2;	//치즈 외부
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j] == cheese) 
				q1.push({ i,j });
		}
	}
	
	q2.push({ 0,0 });
	visited[0][0] = 1;
	
	//외부공간 찾기(visited = 1)
	while (!q2.empty()) {
		NODE temp = q2.front();
		q2.pop();
		for (int i = 0; i < 4; i++) {
			int nx = temp.x + dx[i];
			int ny = temp.y + dy[i];
			if (nx < 0 || ny < 0 || nx == n || ny == m)
				continue;
			if (board[nx][ny] == cheese || visited[nx][ny])
				continue;
			q2.push({ nx,ny });
			visited[nx][ny] = 1;
		}
	}

	int time = 0;
	while (!q1.empty()) {
		time++;
		//치즈 녹이기
		int size = q1.size();
		for (int i = 0; i < size; i++) {
			NODE temp = q1.front();
			q1.pop();
			int cnt = 0;
			for (int j = 0; j < 4; j++) {
				int nx = temp.x + dx[j];
				int ny = temp.y + dy[j];
				//(0 < visited <= time) -> 외부공간
				if (0 < visited[nx][ny] && visited[nx][ny] <= time) {
					cnt++;
					if (cnt == 2)
						break;
				}
			}
			if (cnt < 2) {
				q1.push(temp);
			}
			else {
				visited[temp.x][temp.y] = time + 1;
				board[temp.x][temp.y] = 0;
				q2.push(temp);
			}
		}
		
		//외부공간 찾기 = visited = time + 1
		while (!q2.empty()) {
			NODE temp = q2.front();
			q2.pop();
			int cnt = 0;
			for (int j = 0; j < 4; j++) {
				int nx = temp.x + dx[j];
				int ny = temp.y + dy[j];
				if (nx < 0 || ny < 0 || nx == n || ny == m)
					continue;
				if (board[nx][ny] == cheese || visited[nx][ny])
					continue;
				q2.push({ nx,ny });
				visited[nx][ny] = time + 1;
			}
		}
	}
	printf("%d", time);
}