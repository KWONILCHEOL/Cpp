#include<iostream>
using namespace std;
#define MIN(A,B) (A < B ? A : B)
#define INF 10000000
#pragma warning(disable: 4996)

int bus[101][101];
int main() {
	int n, m, a, b, x;
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; bus[i][i] = 0, i++)
		for (int j = 1; j <= n; j++)
			bus[i][j] = INF;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> x;
		bus[a][b] = MIN(bus[a][b], x);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (i == k)	continue;
			for (int j = 1; j <= n; j++) {
				if (j == k || i == j) continue;
				bus[i][j] = MIN(bus[i][j], bus[i][k] + bus[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++, cout << '\n')
		for (int j = 1; j <= n; j++)
			cout << (bus[i][j] % INF) << ' ';
}