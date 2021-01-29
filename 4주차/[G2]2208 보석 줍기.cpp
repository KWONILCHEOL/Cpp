#include<iostream>
#define MAX(A,B) (A) > (B) ? (A) : (B);
#define MIN(A,B) (A) < (B) ? (A) : (B);
using namespace std;
int n, m, rSum, lSum, _min = 0, ans = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short arr[100000];
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		rSum += arr[i];
		if (i >= m) {
			lSum += arr[i - m];
			_min = MIN(_min, lSum);
			ans = MAX(ans, rSum - _min);
		}
	}

	cout << ans;
}