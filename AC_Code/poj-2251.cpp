#include <iostream>
#include <queue>
#include <cstdio>
#include <string.h>
using namespace std;

int L, R, C;
typedef struct {
	int x, y, z;
	int step;
}pos;
pos start;
char dungeon[35][35][35];
int direction[6][3] = {{0,0,1},{0,0,-1},{1,0,0},{-1,0,0},{0,1,0},{0,-1,0}};
bool vis[35][35][35] = { 0 };
int bfs() {
	queue <pos> q;
	q.push(start);
	while (!q.empty()) {

		pos temp = q.front();
		q.pop();

		for (int i = 0; i < 6; i++) {
			pos new_pos;
			new_pos.x = temp.x + direction[i][0];
			new_pos.y = temp.y + direction[i][1];
			new_pos.z = temp.z + direction[i][2];
			new_pos.step = temp.step + 1;
			if (!vis[new_pos.x][new_pos.y][new_pos.z] && new_pos.x <= L && new_pos.x >= 1 && new_pos.y <= R && new_pos.y >= 1 && new_pos.z <= C && new_pos.z >= 1 && dungeon[new_pos.x][new_pos.y][new_pos.z] != '#') {
				vis[new_pos.x][new_pos.y][new_pos.z] = 1;
				if (dungeon[new_pos.x][new_pos.y][new_pos.z] == 'E')  return new_pos.step;
				q.push(new_pos);
			}
		}
	}
	return -1;
}
int main() {

	while (~scanf("%d%d%d", &L, &R, &C)) {
		if (L == 0 && R == 0 && C == 0)
			break;
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= L; i++) {
			for (int j = 1; j <= R; j++)
				for (int k = 1; k <= C; k++) {
					scanf(" %c", &dungeon[i][j][k]);
					if (dungeon[i][j][k] == 'S') {
						start.x = i;
						start.y = j;
						start.z = k;
						start.step = 0;
					}
				}
		}

		int t = bfs();
		if (t != -1)
			printf("Escaped in %d minute(s).\n", t);
		else
			printf("Trapped!\n");
	}
	return 0;
}
