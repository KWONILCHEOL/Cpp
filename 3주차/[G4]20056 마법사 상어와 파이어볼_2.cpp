#include<iostream>
#include<queue>
#include<set>
using namespace std;
int dx[] = { -1 ,-1 ,0,1,1,1,0,-1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };
struct NODE {
	int a[5] = { 0, };
	int b[5] = { 0, };
	int ODDEVEN = 0;
};
NODE arr[50][50];   //m,s,d,n,i, m,s,d,n,i, (1-È¦¼ö,2-Â¦¼ö,3-µÑ´Ù)

queue<pair<int, int>> q1, q2;
int main() {
	ios_base::sync_with_stdio(false);
	int n, m, k, answer = 0;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		r--, c--;
		q1.push({ r, c });
		arr[r][c].a[0] = m;
		arr[r][c].a[1] = s % n;
		arr[r][c].a[2] = d;
		arr[r][c].a[3] = 1;
		arr[r][c].a[4] = 0;
		arr[r][c].ODDEVEN = d % 2 ? 1 : 2;
	}

	for (int i = 1; i <= k; i++) {
		while (!q1.empty()) {
			int x = q1.front().first;
			int y = q1.front().second;
			q1.pop();
			if (arr[x][y].b[3] > 1 && arr[x][y].b[4] == i - 1) {
				for (int j = (arr[x][y].ODDEVEN == 3 ? 1 : 0); j < 8; j += 2) {
					int nx = (x + ((dx[j] * arr[x][y].a[1]) % n) + n) % n;
					int ny = (y + ((dy[j] * arr[x][y].a[1]) % n) + n) % n;

					if (arr[nx][ny].b[4] == i) {
						arr[nx][ny].b[0] += arr[x][y].a[0];   //m
						arr[nx][ny].b[1] += arr[x][y].a[1];   //s
						arr[nx][ny].b[2] = j;   //d
						arr[nx][ny].b[3]++;               //n
						arr[nx][ny].ODDEVEN |= (j % 2 ? 1 : 2);
					}
					else {
						q2.push({ nx,ny });
						arr[nx][ny].b[0] = arr[x][y].a[0];
						arr[nx][ny].b[1] = arr[x][y].a[1];
						arr[nx][ny].b[2] = j;
						arr[nx][ny].b[3] = 1;
						arr[nx][ny].b[4] = i;
						arr[nx][ny].ODDEVEN = (j % 2 ? 1 : 2);
					}
				}
			}
			else {
				int nx = (x + ((dx[arr[x][y].a[2]] * arr[x][y].a[1]) % n) + n) % n;
				int ny = (y + ((dy[arr[x][y].a[2]] * arr[x][y].a[1]) % n) + n) % n;
				if (arr[nx][ny].b[4] == i) {
					arr[nx][ny].b[0] += arr[x][y].a[0];   //m
					arr[nx][ny].b[1] += arr[x][y].a[1];   //s
					arr[nx][ny].b[2] = arr[x][y].a[2];   //d
					arr[nx][ny].b[3]++;               //n
					arr[nx][ny].ODDEVEN |= (arr[x][y].a[2] % 2 ? 1 : 2);
				}
				else {
					q2.push({ nx,ny });
					arr[nx][ny].b[0] = arr[x][y].a[0];
					arr[nx][ny].b[1] = arr[x][y].a[1];
					arr[nx][ny].b[2] = arr[x][y].a[2];
					arr[nx][ny].b[3] = 1;
					arr[nx][ny].b[4] = i;
					arr[nx][ny].ODDEVEN = (arr[x][y].a[2] % 2 ? 1 : 2);
				}
			}
		}
		while (!q2.empty()) {
			int x = q2.front().first;
			int y = q2.front().second;
			q2.pop();
			if (arr[x][y].b[3] == 1) {
				arr[x][y].a[0] = arr[x][y].b[0];
				arr[x][y].a[1] = arr[x][y].b[1];
				arr[x][y].a[2] = arr[x][y].b[2];
				arr[x][y].a[3] = 1;
				arr[x][y].a[4] = arr[x][y].b[4];
			}
			else if (arr[x][y].b[3] > 1) {
				arr[x][y].a[0] = arr[x][y].b[0] / 5;
				arr[x][y].a[1] = arr[x][y].b[1] / arr[x][y].b[3];
				arr[x][y].a[2] = arr[x][y].b[2];
				arr[x][y].a[3] = arr[x][y].b[3];
				arr[x][y].a[4] = arr[x][y].b[4];
			}
			q1.push({ x,y });
		}
	}
	while (!q1.empty()) {
		int x = q1.front().first;
		int y = q1.front().second;
		if (arr[x][y].a[3] > 1)
			answer += (arr[x][y].a[0] << 2);
		else
			answer += arr[x][y].a[0];
		q1.pop();
	}
	cout << answer;
}