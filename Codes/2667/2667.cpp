#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

#pragma warning(disable : 4996)
using namespace std;

int map[25][25];
int sz[323] = { 0 };
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int cnt;
int n;

bool isrange(int a, int b) {
	return (a >= 0 && a < n) && (b >= 0 && b < n);
}

void dfs(int a, int b, int key) {
	map[a][b] = key;

	for (int i = 0; i < 4; i++) {
		int dy = a + dir[i][0];
		int dx = b + dir[i][1];


		if (map[dy][dx] == 1) 
			if (a >= 0 && a < n && b >= 0 && b < n)
				dfs(dy, dx, key);
		
	}
}

void func() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				cnt++;
				dfs(i, j, cnt + 1);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] > 1)
				sz[map[i][j] - 2]++;
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	func();
	sort(sz, sz + cnt);

	cout << cnt << endl;
	for (int i = 0; i < cnt; i++)
		cout << sz[i] << endl;


	return 0;
}
