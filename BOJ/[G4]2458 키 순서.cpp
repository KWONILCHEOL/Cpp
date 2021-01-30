// [G4]2458 키 순서
// https://www.acmicpc.net/problem/2458

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	int n, m, a, b, result = 0, visit[501] = { 0, };
	cin >> n >> m;
	vector<vector<int>> vLarge(n + 1);	//large
	vector<vector<int>> vSmall(n + 1);	//small
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		vLarge[a].push_back(b);
		vSmall[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		int temp = 1;
		queue<int> q;
		visit[i] = i;
		
		q.push(i);
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			int vSize = vLarge[x].size();
			for (int j = 0; j < vSize; j++) {
				if (visit[vLarge[x][j]] == i)
					continue;
				q.push(vLarge[x][j]);
				visit[vLarge[x][j]] = i;
				temp++;
			}
		}

		q.push(i);
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			int vSize = vSmall[x].size();
			for (int j = 0; j < vSize; j++) {
				if (visit[vSmall[x][j]] == i)
					continue;
				q.push(vSmall[x][j]);
				visit[vSmall[x][j]] = i;
				temp++;
			}
		}
		if (temp == n)
			result++;
	}
	cout << result;
}