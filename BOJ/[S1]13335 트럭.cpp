// [S1]13335 트럭
// https://www.acmicpc.net/problem/13335

#pragma warning(disable: 4996)
#include<cstdio>
int truck[1000], arrive[100];
int arrived = 0, sum = 0, trucks = 0, time = 0;
int main() {
	int n, w, L;
	scanf("%d %d %d", &n, &w, &L);
	for (int i = 0; i < n; i++)
		scanf("%d", &truck[i]);

	for (int i = 0, j = 0; arrived != n; j = (j + 1) % w) {
		if (arrive[j] == 0 && sum + truck[i] > L) 
			for (;arrive[j] != 0; j = (j + 1) % w)
				time++;
		if (arrive[j] > 0) {
			sum -= arrive[j];
			trucks--;
			arrive[j] = 0;
			arrived++;
		}
		if (sum + truck[i] <= L && trucks < w) {
			sum += truck[i];
			trucks++;
			arrive[j] = truck[i];
			i++;
			
			if (i == n) {
				time += (w + 1);
				break;
			}
		}
		time++;
	}
	printf("%d", time);
}