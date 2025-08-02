#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int N;
int map[50][50];
int heightMap[50][50];
int dir[8][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 },
					{ 1, 1 }, { -1, 1 }, { 1, -1 }, { -1, -1 } };

int startI, startJ, houseCount;
bool heightAdded[1000001] = {};
int height[2500];
int visit[50][50] = {};
int tired = 1000001;

int search(int high, int low, int curI, int curJ) {
	int house = 0;
	if (heightMap[curI][curJ] > high || heightMap[curI][curJ] < low) return 0;

	if (map[curI][curJ] == 'K') house++;

	for (int i = 0; i < 8; i++) {
		int nextI = curI + dir[i][0];
		int nextJ = curJ + dir[i][1];
		if (nextI < 0 || nextI > N || nextJ < 0 || nextJ > N) continue;
		if (heightMap[nextI][nextJ] < low || heightMap[nextI][nextJ] > high) continue;
		if (visit[nextI][nextJ]) continue;

		visit[nextI][nextJ] = true;
		house += search(high, low, nextI, nextJ);
	}

	return house;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	houseCount = 0;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < N; j++) {
			map[i][j] = str[j];
			if (map[i][j] == 'P') {
				startI = i;
				startJ = j;
			}
			else if (map[i][j] == 'K') {
				houseCount++;
			}
		}
	}

	int heightIndex = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> heightMap[i][j];
			int cur = heightMap[i][j];
			if (heightAdded[cur]) continue;
			heightAdded[cur] = true;
			height[heightIndex] = cur;
			heightIndex++;
		}
	}

	sort(height, height + heightIndex);

	int minheight = height[0];
	int maxheight = height[0];

	int result = 0;

	while (minheight <= maxheight && maxheight <= height[heightIndex - 1]) { //check end condition
		//if (heightMap[startI][startJ] < minheight || heightMap[startI][startJ] > maxheight) continue;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visit[i][i]) visit[i][j] = 0;
			}
		}

		result = search(maxheight, minheight, startI, startJ);
		if (result >= houseCount) { //update tired
			int newtired = maxheight - minheight;
			tired = min(tired, newtired);
			minheight++;
		}
		else if (result < houseCount) {
			maxheight++;
		}
	}

	cout << tired << '\n';
	return 0;
}