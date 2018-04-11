/*
Description

Due to recent rains, water has pooled in various places in Farmer John's field, which is represented by a rectangle of N x M (1 <= N <= 100; 1 <= M <= 100) squares. Each square contains either water ('W') or dry land ('.'). Farmer John would like to figure out how many ponds have formed in his field. A pond is a connected set of squares with water in them, where a square is considered adjacent to all eight of its neighbors. 

Given a diagram of Farmer John's field, determine how many ponds he has.
Input

* Line 1: Two space-separated integers: N and M 

* Lines 2..N+1: M characters per line representing one row of Farmer John's field. Each character is either 'W' or '.'. The characters do not have spaces between them.
Output

* Line 1: The number of ponds in Farmer John's field.
Sample Input

10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.
Sample Output

3
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool visited[105][105];
char map[105][105];
int N, M;

void dfs(int i, int j) {
	
	visited[i][j] = true;

	for (int dx = -1; dx <= 1; dx++) {
		for (int dy = -1; dy <= 1; dy++) {
			int nx = i + dx;
			int ny = j + dy;
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == 'W' && (visited[nx][ny] == false))
				dfs(nx, ny);
		}
	}
}

int solve() {
	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'W' && visited[i][j] == false) {
				dfs(i, j);
				res++;
			}
		}
	}
	return res;
}

int main() {
	while (scanf("%d %d", &N, &M) != EOF) {
		for (int i = 0; i < N; i++) {
			scanf("%s", map[i]);
		}

		int res;
		memset(visited, false, sizeof(visited));
		
		res = solve();
		printf("%d\n", res);
	}
	return 0;
}