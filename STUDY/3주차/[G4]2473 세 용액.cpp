// [G4]2473 세 용액
// https://www.acmicpc.net/problem/2473

#include<cstdio>
#include<algorithm>
#define ABS(A) ((A) > 0 ? (A) : -(A))
#define EXIT printf("%d %d %d",a,b,c)
#pragma warning(disable: 4996)
using namespace std;

long long arr[5000];
int n, a, b, c;
long long _min = 3e9;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &arr[i]);
	
	sort(&arr[0], &arr[n]);
	for (auto i = &arr[0]; i != &arr[n - 2]; i++){
		for (auto f = i + 1, r = &arr[n - 1]; f != r;) {
			long long sum = (*i) + (*f) + (*r);
			if (_min > ABS(sum)) {
				_min = ABS(sum);
				a = *i, b = *f, c = *r;
			}
			if (sum < 0)f++;
			else if (sum > 0) r--;
			else { EXIT; return 0; }
		}
	}
	EXIT;
}