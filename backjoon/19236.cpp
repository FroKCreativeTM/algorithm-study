#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;

struct Fish
{
	int y, x, dir;
	bool live;
	Fish() {}
	Fish(int _y, int _x, int _dir, bool _live) : y(_y), x(_x), dir(_dir), live(_live) {}
};

int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };

vector<vector<int>> fishMap(4, vector<int>(4, -1));
vector<Fish> fishes(17, Fish());
int answer = INT_MIN;

bool IsInside(int y, int x) {
	return (y >= 0) && (y < 4) && (x >= 0) && (x < 4);
}

void dfs(vector<vector<int>>& vecFishMap, vector<Fish>& vecFishes, int sharkY, int sharkX, int lastDieScore)
{
	vector<vector<int>> copyMap(4, vector<int>(4, -1));
	vector<Fish> copyFishes(17, Fish());

	for (size_t y = 0; y < 4; y++)
		for (size_t x = 0; x < 4; x++)
			copyMap[y][x] = vecFishMap[y][x];

	for (size_t i = 0; i < 17; i++)
		copyFishes[i] = vecFishes[i];

	int fishNum = copyMap[sharkY][sharkX];
	int sharkDir = copyFishes[fishNum].dir;
	copyFishes[fishNum].live = false;
	copyMap[sharkY][sharkX] = -1;

	lastDieScore += fishNum;
	answer = max(answer, lastDieScore);

	for (int f = 1; f <= 16; f++) {
		if (copyFishes[f].live == false) continue;

		int curY = copyFishes[f].y;
		int curX = copyFishes[f].x;
		int curDir = copyFishes[f].dir;

		int ny = curY + dy[curDir];
		int nx = curX + dx[curDir];
		int nDir = curDir;

		while (!IsInside(ny, nx) || (ny == sharkY && nx == sharkX)) {
			nDir = (nDir + 1) % 8;
			ny = curY + dy[nDir];
			nx = curX + dx[nDir];
		}

		if (copyMap[ny][nx] != -1) {
			int targetFishNum = copyMap[ny][nx];

			copyFishes[targetFishNum].y = curY;
			copyFishes[targetFishNum].x = curX;

			copyFishes[f].y = ny;
			copyFishes[f].x = nx;
			copyFishes[f].dir = nDir;

			copyMap[ny][nx] = f;
			copyMap[curY][curX] = targetFishNum;
		}
		//2. 타겟 칸이 빈칸이면
		else {
			copyFishes[f].y = ny;
			copyFishes[f].x = nx;
			copyFishes[f].dir = nDir;

			copyMap[ny][nx] = f;
			copyMap[curY][curX] = -1;
		}
	}


	//상어 이동
	for (int i = 1; i <= 3; i++) {
		int ny = sharkY + dy[sharkDir] * i;
		int nx = sharkX + dx[sharkDir] * i;

		if (!IsInside(ny, nx)) break;

		if (copyMap[ny][nx] != -1) {
			dfs(copyMap, copyFishes, ny, nx, lastDieScore);
		}
	}
}

void solution()
{
	dfs(fishMap, fishes, 0, 0, 0);
}

int main()
{

	for (size_t y = 0; y < 4; y++)
	{
		for (size_t x = 0; x < 4; x++)
		{
			int num, dir;
			cin >> num >> dir;
			fishMap[y][x] = num;
			fishes[num] = Fish(y, x, dir - 1, true);
		}
	}

	solution();
	cout << answer << endl;

	return 0;
}