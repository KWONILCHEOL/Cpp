/*
	날짜 : 20201224
	링크 : https://www.acmicpc.net/problem/11286
*/
#include<iostream>

#define ABS(a) (a > 0 ? a : -a)
#define SWAP(a, b) (a^=b^=a^=b)

using namespace std;
int heap[100001], idx = 0;

int comp(int a, int b) {
	if (ABS(heap[a]) < ABS(heap[b]))
		return a;
	if (heap[a] + heap[b] == 0 && heap[a] < 0)
		return a;
	return b;
}

void push(int x) {
	heap[++idx] = x;
	for (int i = idx; i > 1; i /= 2) {
		int c = comp(i, i / 2);
		if (i / 2 == c)
			break;
		SWAP(heap[i / 2], heap[c]);
	}
}

void pop() {
	cout << heap[1] << "\n";
	heap[1] = heap[idx];
	heap[idx] = 0;

	if (idx == 0)
		return;

	for (int i = 1; i * 2 < idx;) {
		int c;
		if (i * 2 + 1 < idx)
			c = comp(i * 2, i * 2 + 1);
		else
			c = i * 2;

		c = comp(i, c);
		if (i == c)
			break;

		SWAP(heap[i], heap[c]);
		i = c;
	}

	idx--;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, x;
	cin >> n;
	while (n--) {
		cin >> x;
		x != 0 ? push(x) : pop();
	}
}