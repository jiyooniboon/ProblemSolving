#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int M, N, CHI;
pair<int, int> selected[13];
vector< pair<int, int>> chicken;
vector< pair<int, int>> house;
queue<pair<int, int>> q;
int visitb[51][51] = {};
bool visitd[51][51] = {};
int map[51][51];
int MIN = 2147483647;
const int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int bfs() {
	int sum = 0;

	for (pair<int, int> h : house) {
		int dist = 2147483647;
		for (int i = 0; i < M; i++) {
			pair<int, int> c = selected[i];
			dist = min(dist, abs(h.first - c.first) + abs(h.second - c.second));
		}
		sum += dist;
	}
	return sum;
}

void dfs(int depth, int index) {
	if (depth == M) {
		MIN = min(MIN, bfs());
		return;
	}

	for (int i = index; i < CHI; i++) {
		int curi = chicken[i].first;
		int curj = chicken[i].second;
		if (visitd[curi][curj]) continue;
		selected[depth] = { curi, curj };
		visitd[curi][curj] = true;
		dfs(depth + 1, i);
		visitd[curi][curj] = false;
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				CHI++;
				chicken.push_back({ i, j });
			} 
			if (map[i][j] == 1) {
				house.push_back({ i, j });
			}
		}
	}

	dfs(0, 0);

	cout << MIN;
	return 0;
}