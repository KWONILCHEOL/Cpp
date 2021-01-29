//[G4]9466 �� ������Ʈ
//https://www.acmicpc.net/problem/9466

#include<iostream>
#pragma warning(disable: 4996)
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t, n, time = 0;
	cin >> t;
	while (t--) {
		cin >> n;
		int arr[100001] = { 0 };
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			cin >> arr[i];

		int visit[100001] = { 0 };
		for (int i = 1; i <= n; i++) {
			if (visit[i] > 0)
				continue;
			
			time++;
			int s = i, e = i;
			//��ȯ���� or �湮�ߴ���������
			while (visit[e] == 0) {
				visit[e] = time;
				e = arr[e];
			}

			//���������� ��ȯ���� or �湮�ߴ� ��������
			while (visit[s] == time && s != e) {
				cnt++;
				s = arr[s];
			}
		}
		printf("%d\n", cnt);
	}
}