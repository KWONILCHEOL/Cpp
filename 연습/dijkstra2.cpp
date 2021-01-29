#pragma warning(disable: 4996)
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int number = 6;
int INF = 1000000000;

vector<pair<int, int>> a[7];	//���� ����
int d[7];	//�ּ� ���

struct compare {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

struct compare2 {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

void dijkstra3(int start) {
	d[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare2> pq;
	pq.push({ start, 0 });
	while (!pq.empty()) {
		int current = pq.top().first;
		int distance = pq.top().second;
		pq.pop();
		if (d[current] < distance) continue;
		for (int i = 0; i < a[current].size(); i++) {
			int next = a[current][i].first;
			int nextDistance = distance + a[current][i].second;

			if (d[next] <= nextDistance)
				continue;
			d[next] = nextDistance;
			pq.push({ next, nextDistance });
		}
	}
}

void dijkstra2(int start) {
	d[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ start,0 });
	while (!pq.empty()) {
		int current = pq.top().first;
		int distance = pq.top().second;
		pq.pop();
		if (d[current] < distance) continue;
		for (int i = 0; i < a[current].size(); i++) {
			int next = a[current][i].first;
			int nextDistance = distance + a[current][i].second;
			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push({ next, d[next] });
			}
		}
	}
}

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
	//����� ������� ó���ϹǷ� ť ���
	pq.push({ start, 0 });
	while (!pq.empty()) {
		int current = pq.top().first;
		//ª�� ���� ���� ������ ����ȭ
		int distance = pq.top().second;
		pq.pop();
		//�ִ� �Ÿ��� �ƴ� ��� ��ŵ
		if (d[current] < distance) continue;
		for (int i = 0; i < a[current].size(); i++) {
			int next = a[current][i].first;
			int nextDistance = distance + a[current][i].second;
			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push({ next, nextDistance });
			}
		}
	}
}

int main() {
	for (int i = 1; i <= number; i++) {
		d[i] = INF;
	}
	a[1].push_back({ 2,2 });
	a[1].push_back({ 3,5 });
	a[1].push_back({ 4,1 });
	
	a[2].push_back({ 1,2 });
	a[2].push_back({ 3,3 });
	a[2].push_back({ 4,2 });

	a[3].push_back({ 1,5 });
	a[3].push_back({ 2,3 });
	a[3].push_back({ 4,3 });
	a[3].push_back({ 5,1 });
	a[3].push_back({ 6,5 });

	a[4].push_back({ 1,1 });
	a[4].push_back({ 2,2 });
	a[4].push_back({ 3,3 });
	a[4].push_back({ 5,1 });

	a[5].push_back({ 3,1 });
	a[5].push_back({ 4,1 });
	a[5].push_back({ 6,2 });

	a[6].push_back({ 3,5 });
	a[6].push_back({ 5,2 });

	dijkstra(1);
	for (int i = 1; i <= number; i++) {
		printf("%d ", d[i]);
	}
	
	for (int i = 1; i < 7; i++)
		d[i] = INF;

	printf("\n");
	dijkstra2(1);
	for (int i = 1; i <= number; i++) {
		printf("%d ", d[i]);
	}

	for (int i = 1; i < 7; i++)
		d[i] = INF;

	printf("\n");
	dijkstra3(1);
	for (int i = 1; i <= number; i++) {
		printf("%d ", d[i]);
	}
}