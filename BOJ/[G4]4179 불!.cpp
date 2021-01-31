//[G4]4179 ?!
//https://www.acmicpc.net/problem/4179

#include<iostream>
#include<queue>
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
struct NODE {
	int x, y;
};
char map[1000][1001];
int t, n, m, answer = 1e6;
int check[1000][1000];
std::queue<NODE> JI, fire;
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n >> m;

	for (int i = 0; i < m; i++)
		std::cin >> map[i];
	
	for (int j = 0; j < m; j++) {
		for (int k = 0; k < n; k++) {
			if (map[j][k] == 'F')
				fire.push({ j, k });
			else if (map[j][k] == 'J') {
				JI.push({ j, k });
				check[j][k] = 1;
			}
		}
	}

	int ans = 0;
	while (!JI.empty()) {
		ans++;
		int size2 = fire.size();
		for (int i = 0; i < size2; i++) {
			NODE temp = fire.front();
			fire.pop();
			for (int j = 0; j < 4; j++) {
				int nx = temp.x + dx[j];
				int ny = temp.y + dy[j];
				if (nx < 0 || ny < 0 || nx == n || ny == m)
					continue;
				if (map[nx][ny] == '.' || map[nx][ny] == 'J') {
					map[nx][ny] = 'F';
					fire.push({ nx, ny });
				}
			}
		}
		int size1 = JI.size();
		for (int i = 0; i < size1; i++) {
			NODE temp = JI.front();
			JI.pop();
			for (int j = 0; j < 4; j++) {
				int nx = temp.x + dx[j];
				int ny = temp.y + dy[j];
				if (nx < 0 || ny < 0 || nx == n || ny == m) {
					std::cout << ans << '\n';
					return 0;
				}
				if (map[nx][ny] == '.' && check[nx][ny] != 1) {
					JI.push({ nx, ny });
					check[nx][ny] = 1;
				}
			}
		}
	}

	std::cout << "IMPOSSIBLE\n";
}