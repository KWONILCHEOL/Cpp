/*
	[G2]4491 로봇 청소기
	https://www.acmicpc.net/problem/4491
*/
#include<iostream>
#include<queue>
#pragma warning(disable: 4996)
using namespace std;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

struct Node {
	int x, y;
};

Node node[11];
char room[21][21];
int dis[11][11];	//(0) 로봇, (1~10) 더러운 칸 거리
int dirty_num[20][20];
int dirty_cnt;
bool visit[11];
int r, c, answer;
queue<Node> q;

void Distance() {
	for (int i = 0; i < dirty_cnt; i++) {
		q.push(node[i]);
		bool check[20][20] = { false, };
		check[node[i].x][node[i].y] = true;

		int cnt = 0;
		while (!q.empty()) {
			cnt++;
			int size = q.size();
			for (int j = 0; j < size; j++) {
				int x = q.front().x;
				int y = q.front().y;
				q.pop();
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (nx < 0 || ny < 0 || nx == r || ny == c || check[nx][ny])
						continue;
					
					check[nx][ny] = true;
					if (room[nx][ny] == '*' || room[nx][ny] == 'o') {
						int num = dirty_num[nx][ny];
						dis[i][num] = cnt;
						dis[num][i] = cnt;
						q.push({ nx,ny });
					}
					else if (room[nx][ny] == '.')
						q.push({ nx,ny });
				}
			}
		}
	}
}

void Move(int n, int cur,int moves) {
	if (n == 0) {
		if (answer == -1)
			answer = moves;
		else
			answer = answer < moves ? answer : moves;
		return;
	}
	//n개 방문, 백트레킹
	for (int i = 1; i <= dirty_cnt; i++) {
		if (visit[i])
			continue;
		
		if (dis[cur][i] > 0) {
			visit[i] = true;
			Move(n - 1, i, moves + dis[cur][i]);
			visit[i] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> c >> r) {
		if (r == 0 && c == 0)
			break;
		
		dirty_cnt = 0;
		for (int i = 0; i < 11; i++) {
			visit[i] = false;
			for (int j = 0; j < 11; j++)
				dis[i][j] = 0;
		}

		for (int i = 0; i < r; i++) {
			cin >> room[i];
			for (int j = 0; j < c; j++) {
				if (room[i][j] == 'o') {
					node[0] = { i,j };
					dirty_num[i][j] = 0;
				}
				else if (room[i][j] == '*') {
					dirty_cnt++;
					node[dirty_cnt] = { i,j };
					dirty_num[i][j] = dirty_cnt;	//범위 : 1 ~ 11
				}
			}
		}

		Distance();

		answer = -1;
		visit[0] = true;
		Move(dirty_cnt, 0, 0);	//더러운 방, 현재 위치, 이동 거리
		cout << answer << '\n';
	}
}