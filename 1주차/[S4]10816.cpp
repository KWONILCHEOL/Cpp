/*
	날짜 : 20201224
	링크 : https://www.acmicpc.net/problem/10816
*/
#include<iostream>
#define c 10000000
using namespace std;
int a[c + c + 1], n, x;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> x;
		a[x + c]++;
	}
	cin >> n;
	while (cin >> x)
		cout << a[x + c] << " ";
}