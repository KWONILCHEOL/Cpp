// [S1]15900 ���� Ż��
// https://www.acmicpc.net/problem/15900
/*
	�Է� : N(����), N-1���� ����
	�������� ��� ������� ������ �Ÿ� - Ȧ��(Yes) ¦��(No)
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

			//�������
			if (vLen == vCnt) 
				total += (cnt - 1);
		}
	}
	cout << (total % 2 ? "Yes" : "No");
}