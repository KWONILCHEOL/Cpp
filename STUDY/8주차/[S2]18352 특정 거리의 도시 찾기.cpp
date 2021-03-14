// [S2]18352 특정 거리의 도시 찾기
// https://www.acmicpc.net/problem/18352
/*
	시작점(x)에서 최단 거리가 k인 노드 출력
	(sep='\n'), 없으면 -1
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#pragma warning(disable: 4996)
#define INF 1e9
using namespace std;

int ans[300000];
int dist[300001];
int ansSize = 0;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, k, x, a, b;
	cin >> n >> m >> k >> x;
	vector<vector<int>> v(n+1);
	for (int i = 1; i <= n; i++) 
		dist[i] = INF;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
	}
	
	queue<int> q;
	dist[x] = 0;
	q.push(x);

	while (!q.empty()) {
		int curNode = q.front();
		q.pop();

		int size = v[curNode].size();
		for (int i = 0; i < size; i++) {
			int nextNode = v[curNode][i];
			if (dist[nextNode] == INF) {
				dist[nextNode] = dist[curNode] + 1;
				if (dist[nextNode] == k)
					ans[ansSize++] = nextNode;
				q.push(nextNode);
			}
		}
	}
	
	if (ansSize == 0)
		printf("-1");
	else {
		sort(&ans[0], &ans[ansSize]);
		for (int i = 0; i < ansSize; i++)
			printf("%d\n", ans[i]);
	}
}