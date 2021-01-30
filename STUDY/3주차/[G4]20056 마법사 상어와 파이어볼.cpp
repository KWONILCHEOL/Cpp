// [G4]20056 마법사 상어와 파이어볼
// https://www.acmicpc.net/problem/20056

#include<iostream>
#include<map>
#include<queue>
using namespace std;
int dx[] = { -1 ,-1 ,0,1,1,1,0,-1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };

struct MNODE {
	int m, s, d, n;
	bool ODD = true, EVEN = true;
	MNODE() { m = 0, s = 0, d = 0, n = 0; }
	void set(int p1, int p2, int p3) {
		m = p1, s = p2, d = p3, n = 1;
		if (d % 2) EVEN = false;
		else ODD = false;
	}
	MNODE operator+(MNODE &mnode) {
		m += mnode.m;
		s += mnode.s;
		d = mnode.d; 
		n += 1;
		ODD = ODD && mnode.ODD;
		EVEN = EVEN && mnode.EVEN;
		return *this;
	}
};
struct QNODE {
	int r, c;
	MNODE mnode;
	QNODE(int p1, int p2, int p3, int p4, int p5) {
		r = p1, c = p2, mnode.set(p3, p4, p5);
	}
};
queue<QNODE> q;
int main() {
	ios_base::sync_with_stdio(false);
	int n, m, k, answer = 0;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		q.push(QNODE(r, c, m, s, d));
 	}
	for (int i = 0; i < k; i++) {
		int qSize = q.size();
		if (qSize == 0)
			break;
		map<pair<int, int>, MNODE> m;
		while (qSize--) {
			QNODE qnode = q.front();
			q.pop();
			int s = qnode.mnode.s;
			int d = qnode.mnode.d;
			int x = qnode.r = (qnode.r + ((dx[d] * s) % n) + n) % n;
			int y = qnode.c = (qnode.c + ((dy[d] * s) % n) + n) % n;
			m[{x,y}] = m[{x,y}] + qnode.mnode;
		}
		for (auto it = m.begin(); it != m.end(); it++) {
			if (it->second.n > 1) {
				it->second.m /= 5;
				if (it->second.m == 0)
					continue;
				it->second.s /= it->second.n;
				int x = it->first.first;
				int y = it->first.second;
				int m = it->second.m;
				int s = it->second.s;
				
				for (int i = !(it->second.EVEN || it->second.ODD); i < 8; i += 2)
					q.push(QNODE(x, y, m, s, i));
			}
			else
				q.push(QNODE(it->first.first, it->first.second, it->second.m, it->second.s, it->second.d));
		}
	}
	while (!q.empty()) {
		answer += q.front().mnode.m;
		q.pop();
	}
	cout << answer;
}