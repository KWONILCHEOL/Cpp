/*
	[G5]15961 회전 초밥2
	https://www.acmicpc.net/problem/15961
*/
#include<iostream>
#pragma warning(disable: 4996)
#define MAX(A,B) A > B ? A : B
using namespace std;

int curSushi[3001];	//먹은 초밥 현황
int front[3000];	//1~k번 스시 (회전)
int temp[3000];	
int n, d, k, c, x;
int answer = 0;
int cnt = 0;

void Del(int del) {
	curSushi[del]--;
	if (curSushi[del] == 0 && del != c)
		cnt--;
}

void Add(int add) {
	curSushi[add]++;
	if (curSushi[add] == 1 && add != c)
		cnt++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> d >> k >> c;

	for (int i = 0; i < k; i++) {
		cin >> x;
		front[i] = x;
		temp[i] = x;

		curSushi[x]++;
		cnt += (curSushi[x] == 1);
	}

	cnt += (curSushi[c] == 0);
	answer = cnt;

	if ((answer == k + 1) || (answer == d)) {
		cout << answer;
		return 0;	
	}
	
	for (int i = k; i < n; i++) {
		Del(temp[(i % k)]);
		cin >> temp[(i % k)];
		Add(temp[(i % k)]);
		
		answer = MAX(answer, cnt);

		if ((answer == k + 1) || (answer == d)) {
			cout << answer;
			return 0;
		}
	}

	for (int i = 0, j = n; i < k; i++, j++) {
		Del(temp[j % k]);
		Add(front[i]);
		
		answer = MAX(answer, cnt);

		if ((answer == k + 1) || (answer == d)) {
			cout << answer;
			return 0;
		}
	}

	cout << answer;
}