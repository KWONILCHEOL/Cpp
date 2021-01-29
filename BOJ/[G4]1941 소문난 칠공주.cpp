//[G4]1941 소문난 칠공주
//https://www.acmicpc.net/problem/1941
#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
#define NODE pair<int, int>
#pragma warning(disable: 4996)
using namespace std;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
char s[5][5];
short visit[5][5];
vector<NODE> princess;	//현재 공주
set<vector<NODE>> ans;

void go(int n, int cnt) {
	if (cnt + (7 - n) < 4)
		return;

	if (n == 7) {
		if (cnt >= 4) {
			vector<NODE> temp = princess;
			sort(temp.begin(), temp.end());
			ans.insert(temp);
		}
		return;
	}

	set<NODE> possible;
	for (NODE node : princess) {
		for (int i = 0; i < 4; i++) {
			int nx = node.first + dx[i];
			int ny = node.second + dy[i];
			if (nx < 0 || ny < 0 || nx == 5 || ny == 5 || visit[nx][ny])
				continue;

			possible.insert({ nx,ny });
		}
	}

	for (NODE node : possible) {
		visit[node.first][node.second] = true;
		princess.push_back({node});
		
		if (s[node.first][node.second] == 'S')
			go(n + 1, cnt + 1);
		else
			go(n + 1, cnt);

		princess.pop_back();
		visit[node.first][node.second] = false;
	}
}
int main() {
	for (int i = 0; i < 5; i++) 
		scanf("%s", &s[i]);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (s[i][j] == 'S') {
				visit[i][j] = true;
				princess.push_back({ i,j });
				go(1, 1);
				princess.pop_back();
			}
		}
	}

	printf("%d", ans.size());
}