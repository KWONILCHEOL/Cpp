// [G5]13549 숨바꼭질 3
// https://www.acmicpc.net/problem/13549
/*
	수빈 N점 동생 K점
	수빈 0초 이동(*2)
	수빈 1초 이동(-1), (+1)
*/
#include<cstdio>
#include<queue>
#pragma warning(disable: 4996)
std::queue<int> q;
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	bool visit[100001] = { false, };

	if (n >= k) {
		printf("%d", n - k);
		return 0;
	}

	q.push(k);

	int cnt = 0;

	if (visit[n]) {
		printf("%d", cnt);
		return 0;
	}

	while (true) {
		int qSize = q.size();
		//나누기 2
		for (int i = 0; i < qSize; i++) {
			int x = q.front();
			q.pop();
			q.push(x);
			while (x && x % 2 == 0) {
				x /= 2;
				if (visit[x])
					break;
				visit[x] = true;
				q.push(x);
			}
		}

		if (visit[n]) {
			printf("%d", cnt);
			return 0;
		}
		cnt++;

		qSize = q.size();
		//+-1
		for (int i = 0; i < qSize; i++) {
			int x = q.front();
			q.pop();
			if (visit[x + 1] == false) {
				q.push(x + 1);
				visit[x + 1] = true;
			}
			if (visit[x - 1] == false) {
				q.push(x - 1);
				visit[x - 1] = true;
			}
		}
		if (visit[n]) {
			printf("%d", cnt);
			return 0;
		}
	}
}