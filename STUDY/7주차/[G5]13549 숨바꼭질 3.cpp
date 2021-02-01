// [G5]13549 숨바꼭질 3
// https://www.acmicpc.net/problem/13549
/*
	수빈 N점 동생 K점
	수빈 1초 이동(-1), (+1)
	수빈 0초 이동(*2)
*/
#include<iostream>
#include<queue>
#pragma warning(disable: 4996)
using namespace std;
queue<int> q;
queue<int> q2;
bool visit[200001];
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	
	if (n >= k) {
		printf("%d", n - k);
		return 0;
	}
	if (n - k == 1 || k - n == 1) {
		printf("1");
		return 0;
	}
	for (int i = n; i <= k; i *= 2) {
		if (i != k)
			continue;

		printf("0");
		return 0;
	}

	q.push(k);
	q2.push(k);
	visit[k] = true;
	
	int cnt = 0;
	while (true) {
		if (visit[n]) {
			printf("%d", cnt);
			return 0;
		}

		cnt++;
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int x = q.front();
			q.pop();


			if (visit[x + 1] == false) {
				q2.push(x + 1);
				visit[x + 1] = true;
			}

			if (visit[x - 1] == false) {
				q2.push(x + 1);
				visit[x - 1] = true;
			}
		}
	}
}