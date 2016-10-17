#include <cstdio>

int N, M;
char grid[105][105];
bool visited[105][105];

/* dx[]          dy[]
* -1 -1 -1      -1  0 +1
*  0  0  0      -1  0 +1
* +1 +1 +1      -1  0 +1
*/

int dx[] = { -1,-1,-1, 0, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1,-1, 0, 1,-1, 0, 1 };

bool isValid(int x, int y) {
	return (x >= 0 && y >= 0 && x < N && y < M) && grid[x][y] == 'W' && !visited[x][y];
}

void resetVisited() {
	for (int i = 0; i < 105; i++) {
		for (int j = 0; j < 105; j++) {
			visited[i][j] = false;
		}
	}
}

int dfs(int x, int y) {
	if (!isValid(x, y)) {
		return 0;
	}

	visited[x][y] = true;
	int result = 1;

	for (int di = 0; di < 9; di++) {
		int r = x + dx[di];
		int c = y + dy[di];
		result += dfs(r, c);
	}
	return result;
}

void calculateArea(int x, int y) {
	resetVisited();
	printf("%d\n", dfs(x, y));
}

int main(int argc, char** argv) {
	char line[105];
	int T;
	scanf("%d ", &T);
	int hasItem = scanf("%[^\n]", &line);
	bool EOL = false;
	while (T-- > 0) {
		if (hasItem > 0) {
			N = 0;
			for (N = 0; line[0] == 'L' || line[0] == 'W'; N++) {
				for (M = 0; line[M] != '\0'; M++) {
					grid[N][M] = line[M];
				}
				scanf("\n");
				scanf("%[^\n]", line);
			}

			int r, c;
			while (true) {
				sscanf(line, "%d %d", &r, &c);
				calculateArea(r - 1, c - 1); // Area Calculation

				scanf("\n");
				hasItem = scanf("%[^\n]", line);
				if (!(hasItem > 0)) {
					EOL = true;
					break;
				}

				if ((hasItem > 0) && (line[0] == 'L' || line[0] == 'W')) {
					break;
				}
			}
		}

		if (T > 0) {
			printf("\n");
		}

		if (EOL) break;
	}

	return 0;
}