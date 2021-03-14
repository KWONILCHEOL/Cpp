// [G4]1062 °¡¸£Ä§
// https://www.acmicpc.net/problem/1062

#include<iostream>
#include<vector>
#include<string>
#pragma warning(disable: 4996)
using namespace std;
vector<string> v;
int n, k, ans;
bool visit[26];
void check() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int size = v[i].size();
		cnt++;
		for (int j = 0; j < size; j++) {
			if (visit[v[i][j] - 'a'] == false) {
				cnt--;
				break;
			}
		}
	}
	ans = ans > cnt ? ans : cnt;
}
void go(int i, int cnt) {
	if (cnt == k) {
		check();
		return;
	}

	for (; i < 26; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			go(i + 1, cnt + 1);
			visit[i] = false;
		}
	}
}
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	visit['a' - 'a'] = true;
	visit['n' - 'a'] = true;
	visit['t' - 'a'] = true;
	visit['i' - 'a'] = true;
	visit['c' - 'a'] = true;
	k -= 5;
	go(0, 0);
	printf("%d", ans);
}