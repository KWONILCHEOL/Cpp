// [G1]3197 ������ ȣ��
// https://www.acmicpc.net/problem/3197
/*
	��(.)�� ������ ����(X)�� ����
	����(L)�� �����¿�θ� ������

	ice(���� ����)
	ice2(���� ����)
	swan(���� �̵�)
	swan2(���� ��ó ����)
*/

#include<iostream>
#include<queue>
#pragma warning(disable: 4996)
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
struct NODE { int x, y; };
std::queue<NODE> ice, ice2, swan, swan2;
char board[1500][1500];
bool visit[1500][1500];
int main() {
	std::ios_base::sync_with_stdio(false);
	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) 
		std::cin >> board[i];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'X') {
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || ny < 0 || nx == n || ny == m)
						continue;
					if (board[nx][ny] != 'X') {
						ice.push({ i,j });
						break;
					}
				}
			}
			else if (board[i][j] == 'L') swan.push({ i,j });
		}
	}

	NODE node = swan.front();
	swan.pop();
	board[node.x][node.y] = 'O';

	visit[swan.front().x][swan.front().y] = true;

	for (int i = 0; i < 3000; i++) {
		//���ǰ� ����� ������ swan2�� push
		while (!swan.empty()) {
			int x = swan.front().x;
			int y = swan.front().y;
			swan.pop();
			bool flag = false;
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				
				if (nx < 0 || ny < 0 || nx == n || ny == m || visit[nx][ny])
					continue;

				if (board[nx][ny] == 'O') {
					printf("%d", i);
					return 0;
				}
				if (board[nx][ny] == 'X')
					flag = true;
				else if (board[nx][ny] == '.') {
					swan.push({ nx,ny });
					visit[nx][ny] = true;
				}
			}
			if (flag)
				swan2.push({ x,y });
		}
		swan = swan2;
		swan = {};

		//ice(���� ����) -> ice2(���� ����)
		while (!ice.empty()) {
			int x = ice.front().x;
			int y = ice.front().y;
			ice.pop();
			board[x][y] = '.';
			ice2.push({ x,y });
		}
		
		//ice2(���� ����)���� ice(������ ���� ����) ã��
		bool visit2[1500][1500] = { false };	//�޸� �ʰ� �ذ�
		while (!ice2.empty()) {
			int x = ice2.front().x;
			int y = ice2.front().y;
			ice2.pop();
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx < 0 || ny < 0 || nx == n || ny == m || visit2[nx][ny])
					continue;
				if (board[nx][ny] == 'X') {
					ice.push({ nx,ny });
					visit2[nx][ny] = true;
				}
			}
		}
	}
}