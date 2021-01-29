#pragma warning(disable: 4996)
#include<cstdio>
#define ABS(A) (A > 0 ? A : -(A))
int main() {
	int a, b, n, dir, dis;
	int store[101][3];
	scanf("%d %d\n%d", &a, &b, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &dir, &dis);
		if (dir == 1) 
			store[i][0] = 0, store[i][1] = dis;
		else if (dir == 2) 
			store[i][0] = b, store[i][1] = dis;
		else if (dir == 3) 
			store[i][0] = dis, store[i][1] = 0;
		else if (dir == 4) 
			store[i][0] = dis, store[i][1] = a;
		store[i][2] = dir;
	}
	int x, y, _x, _y, _dir, _dis, sum = 0;
	scanf(" %d %d", &_dir, &_dis);
	if (_dir == 1)
		_x = 0, _y = _dis;
	else if (_dir == 2)
		_x = b, _y = _dis;
	else if (_dir == 3)
		_x = _dis, _y = 0;
	else if (_dir == 4)
		_x = _dis, _y = a;

	for (int i = 0; i < n; i++) {
		x = store[i][0];
		y = store[i][1];
		dir = store[i][2];
		
		if (dir == _dir)
			sum += ABS(x - _x) + ABS(y - _y);
		else if (_dir + dir > 3) 
			sum += ABS(_x - store[i][0]) + ABS(_y - store[i][1]);
		else if (dir < 3) {
			if (y + _y <= a)
				sum += y + _y + b;
			else
				sum += (2 * a) - y - _y + b;
		}
		else if (dir > 2) {
			if (x + _x <= b)
				sum += x + _x + a;
			else
				sum += (2 * b) - x - _x + a;
		}
	}
	printf("%d", sum);
}