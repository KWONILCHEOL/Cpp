/*
	날짜 : 20201224
	링크 : https://www.acmicpc.net/problem/2470
*/
#include<iostream>
#include<algorithm>
using namespace std;

long long arr[100000];
int head, rear;
int main() {
	ios_base::sync_with_stdio(false);
	int n;
	long long _min = 2000000000;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(&arr[0], &arr[n]);

	long long result1, result2;
	for (head = 0, rear = n - 1; head != rear;) {
		long long sum = abs(arr[head] + arr[rear]);

		if (_min > sum) {
			result1 = arr[head];
			result2 = arr[rear];
			_min = sum;
			if (sum == 0)
				break;
		}
		if (abs(arr[head]) < abs(arr[rear]))
			rear--;
		else
			head++;
	}

	cout << result1 << " " << result2;
}