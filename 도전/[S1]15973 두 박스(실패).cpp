// [S1]15973 두 박스(실패)
// https://www.acmicpc.net/problem/15973

#pragma warning(disable: 4996)
#include<cstdio>
long long a[4], b[4];
long long ap[4][2], bp[4][2];
void getP(long long p[4][2], long long x[4]) {
	p[0][0] = x[0];p[0][1] = x[1];
	p[1][0] = x[0];p[1][1] = x[3];
	p[2][0] = x[2];p[2][1] = x[1];
	p[3][0] = x[2];p[3][1] = x[3];
}

bool cFACE(long long p[4][2], long long c[4]) {
	for (long long i = 0; i < 4; i++) {
		long long x = p[i][0], y = p[i][1];
		if (c[0] < x && x < c[2] && c[1] < y && y < c[3])
			return true;
	}
	return false;
}
bool cFACE2(long long c[4], long long d[4]) {
	if (c[0] < d[0] && d[2] < c[2] && d[1] < c[1] && c[3] < d[3])
		return true;

	if (c[0] == d[0] || c[2] == d[2]) {

	}
	return c[0] == d[0] && c[1] == d[1] && c[2] == d[2] && c[3] == d[3];
}
bool getSamePoint() {
	for(long long i=0; i < 4; i++)
		for (long long j = 0; j < 4; j++) 
			if (ap[i][0] == bp[j][0] && ap[i][1] == bp[j][1])
				return true;
	return false;
}
bool getMid(long long p[4][2], long long c[4]) {
	for (long long i = 0; i < 4; i++) {
		long long x = p[i][0], y = p[i][1];
		if ((c[0] < x && x < c[2]) || (c[1] < y && y < c[3]))
			return true;
	}
	return false;
}
bool cNULL() {
	if (a[0] > b[2] || b[0] > a[2] || a[1] > b[3] || b[1] > a[3])
		return true;
	return false;
}
int main() {
	for (long long i = 0; i < 4; i++)
		scanf("%lld", &a[i]);
	for (long long i = 0; i < 4; i++)
		scanf("%lld", &b[i]);
	getP(ap, a); getP(bp, b);

	if (getSamePoint()) {
		if (getMid(ap, b) || getMid(bp, a)) {
			printf("LINE");
			return 0;
		}
		printf("POINT");
		return 0;
	}

	if (cFACE2(a, b) || cFACE(ap, b) || cFACE(bp, a)) {
		printf("FACE");
		return 0;
	}

	printf("%s",cNULL() ? "NULL" : "LINE");
}