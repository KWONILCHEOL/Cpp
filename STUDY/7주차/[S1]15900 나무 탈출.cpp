// [S1]15900 나무 탈출
// https://www.acmicpc.net/problem/15900
/*
	입력 : N(정점), N-1개의 간선
	정점부터 모든 리프노드 까지의 거리 - 홀수(Yes) 짝수(No)
*/
#include<iostream>
#include<vector>
#include<queue>
#pragma warning(disable: 4996)
using namespace std;
vector<int> v[500001];
queue<int> q;
bool visit[500001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, a, b;
	cin >> n;
	while(--n) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	q.push(1);
	visit[1] = true;
	int cnt = 0, total = 0;
	while (!q.empty()) {
		int qLen = q.size();
		cnt++;
		for (int i = 0; i < qLen; i++) {
			int x = q.front();
			q.pop();

			int vCnt = 0;
			int vLen = v[x].size();
			for (int j = 0; j < vLen; j++) {
				if (visit[v[x][j]]) {
					vCnt++;
					continue;
				}
				visit[v[x][j]] = true;
				q.push(v[x][j]);
			}

			//리프노드
			if (vLen == vCnt) 
				total += (cnt - 1);
		}
	}
	cout << (total % 2 ? "Yes" : "No");
}