#include <bits/stdc++.h>
using namespace std;

int a[1001][1001];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int main() {
	int n, find;
	cin >> n >> find;
	int x, y, row, col;

	row  = col = x = y = n / 2;

	int dir = 0;
	int size = 1;
	int num = 1;

	a[row][col] = num;
	bool run = true;

	while (run) {
		for (int i = 0; i < size; i++) {
			row += dr[dir];
			col += dc[dir];
			a[row][col] = ++num;

			if (num == n*n) {
				run = false;
				break;
			}
		}
		dir++;
		dir %= 4;
		if (dir % 2 == 0) size++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j]<< " ";
			if (find == a[i][j]) {
				x = i + 1;
				y = j + 1;
			}
		}
		cout << endl;
	}
	cout << x << " " << y;

	return 0;
}