// [G3]13459 구슬 탈출
// https://www.acmicpc.net/problem/13459
/*
	파랑 구멍에 들어가면 안됨
	이동 : 좌 or 우 -> 상, 하
	이동 : 상 or 하 -> 좌, 우
*/
#include<cstdio>
#include<queue>
#pragma warning(disable: 4996)

struct NODE {
	int rx, ry, bx, by;
	bool ub;	//움직임 true(상하) false(좌우)
};
std::queue<NODE> q;
char board[10][10];
bool visit[10][10][10][10];	//rx,ry,bx,by
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", board[i]);

	NODE node;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			if (board[i][j] == 'B') node.bx = i, node.by = j;
			else if (board[i][j] == 'R') node.rx = i, node.ry = j;
	
	node.ub = true;
	q.push(node);

	node.ub = false;
	q.push(node);
	visit[node.rx][node.ry][node.bx][node.by] = true;

	for (int i = 1; i <= 10; i++) {
		int qSize = q.size();
		for (int j = 0; j < qSize; j++) {
			node = q.front();
			q.pop();
			int rx, ry, bx, by;
			if (node.ub) {
				//좌
				rx = node.rx, ry = node.ry;
				bx = node.bx, by = node.by;

				while (board[rx][ry - 1] != '#' && board[rx][ry] != 'O')
					ry -= 1;
				while (board[bx][by - 1] != '#' && board[bx][by] != 'O') 
					by -= 1;
				
				if (board[bx][by] != 'O') {
					if (board[rx][ry] == 'O') {
						printf("1");
						return 0;
					}
					if (rx == bx && ry == by)
						node.ry < node.by ? (by += 1) : (ry += 1);

					if (visit[rx][ry][bx][by] == false) {
						q.push({ rx,ry,bx,by,!node.ub });
						visit[rx][ry][bx][by] = true;
					}
				}
				
				//우
				rx = node.rx, ry = node.ry;
				bx = node.bx, by = node.by;

				while (board[rx][ry + 1] != '#' && board[rx][ry] != 'O')
					ry += 1;
				while (board[bx][by + 1] != '#' && board[bx][by] != 'O')
					by += 1;

				if (board[bx][by] != 'O') {
					if (board[rx][ry] == 'O') {
						printf("1");
						return 0;
					}
					if (rx == bx && ry == by)
						node.ry < node.by ? (ry -= 1) : (by -= 1);

					if (visit[rx][ry][bx][by] == false) {
						q.push({ rx,ry,bx,by,!node.ub });
						visit[rx][ry][bx][by] = true;
					}
				}
			}
			else {
				//상
				rx = node.rx, ry = node.ry;
				bx = node.bx, by = node.by;

				while (board[rx - 1][ry] != '#' && board[rx][ry] != 'O')
					rx -= 1;
				while (board[bx - 1][by] != '#' && board[bx][by] != 'O')
					bx -= 1;

				if (board[bx][by] != 'O') {
					if (board[rx][ry] == 'O') {
						printf("1");
						return 0;
					}
					if (rx == bx && ry == by)
						node.rx < node.bx ? (bx += 1) : (rx += 1);

					if (visit[rx][ry][bx][by] == false) {
						q.push({ rx,ry,bx,by,!node.ub });
						visit[rx][ry][bx][by] = true;
					}
				}

				//하
				rx = node.rx, ry = node.ry;
				bx = node.bx, by = node.by;

				while (board[rx + 1][ry] != '#' && board[rx][ry] != 'O')
					rx += 1;
				while (board[bx + 1][by] != '#' && board[bx][by] != 'O')
					bx += 1;

				if (board[bx][by] != 'O') {
					if (board[rx][ry] == 'O') {
						printf("1");
						return 0;
					}
					if (rx == bx && ry == by)
						node.rx < node.bx ? (rx -= 1) : (bx -= 1);

					if (visit[rx][ry][bx][by] == false) {
						q.push({ rx,ry,bx,by,!node.ub });
						visit[rx][ry][bx][by] = true;
					}
				}
			}
		}
	}
	printf("0");
}