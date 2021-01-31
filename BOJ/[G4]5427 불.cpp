//[G4]5427 บา
//https://www.acmicpc.net/problem/5427

#include<iostream>
#include<queue>
using std::queue;
using std::ios_base;
using std::cin;
using std::cout;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
struct NODE {
	int x, y;
};
char map[1000][1001];
int t, n, m;
int check[1000][1000];
queue<NODE> q1, q2;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> m;
		for (int i = 0; i < m; i++)
			cin >> map[i];
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				if (map[j][k] == '*')
					q2.push({ j, k });
				else if (map[j][k] == '@') {
					q1.push({ j, k });
					check[j][k] = tc;
				}
			}
		}
		int ans = 0;
		bool escape = false;
		while (!q1.empty()) {
			ans++;
			int size2 = q2.size();
			for (int i = 0; i < size2; i++) {
				NODE temp = q2.front();
				q2.pop();
				for (int j = 0; j < 4; j++) {
					int nx = temp.x + dx[j];
					int ny = temp.y + dy[j];
					if (nx < 0 || ny < 0 || nx == m || ny == n)
						continue;
					if (map[nx][ny] == '.' || map[nx][ny] == '@') {
						map[nx][ny] = '*';
						q2.push({ nx, ny });
					}
				}
			}
			int size1 = q1.size();
			for (int i = 0; i < size1; i++) {
				NODE temp = q1.front();
				q1.pop();
				for (int j = 0; j < 4; j++) {
					int nx = temp.x + dx[j];
					int ny = temp.y + dy[j];
					if (nx < 0 || ny < 0 || nx == m || ny == n) {
						cout << ans << '\n';
						while (!q1.empty())
							q1.pop();
						while (!q2.empty())
							q2.pop();
						i = size1;
						escape = true;
						break;
					}
					if (map[nx][ny] == '.' && check[nx][ny] != tc) {
						q1.push({ nx, ny });
						check[nx][ny] = tc;
					}
				}
			}
		}
		while (!q2.empty())
			q2.pop();
		if (!escape)
			cout << "IMPOSSIBLE\n";
	}
}