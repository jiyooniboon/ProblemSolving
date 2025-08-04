#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int N;
int map[51][51];
int heightMap[51][51];
int dir[8][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0},
    {1, 1}, {-1, 1}, {1, -1}, {-1, -1}
};

int startI, startJ, houseCount;
bool heightAdded[1000001] = {};
int height[2500];
bool visit[50][50] = {};
int tired = 1000001;

int search(int high, int low, int curI, int curJ) { //bfs
    int house = 0;
    bool visit[51][51] = {0};
    queue<pair<int, int>> q;
    if (heightMap[curI][curJ] > high || heightMap[curI][curJ] < low) return 0;

    q.push({curI, curJ});
    visit[curI][curJ] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 8; i++) {
            int nexti = x + dir[i][0];
            int nextj = y + dir[i][1];
            if (visit[nexti][nextj]) continue;
            if (nexti < 0 || nexti > N || nextj < 0 || nextj > N) continue;
            if (heightMap[nexti][nextj] < low || heightMap[nexti][nextj] > high) continue;
            if (map[nexti][nextj] == 'K') house++;
            q.push({nexti, nextj});
            visit[nexti][nextj] = true;

            if (house == houseCount) return house;
        }
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
            } else if (map[i][j] == 'K') {
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

    int minheight = 0;
    int maxheight = 0;

    int result = 0;

    while (minheight <= maxheight && maxheight <= heightIndex - 1) {
        //check end condition
        if (heightMap[startI][startJ] > height[maxheight]) {
            maxheight++;
            continue;
        }

        if (heightMap[startI][startJ] < height[minheight]) break;

        //memset(visit, 0x00, sizeof(visit));

        result = search(height[maxheight], height[minheight], startI, startJ);
        if (result >= houseCount) {
            //update tired
            int newtired = height[maxheight] - height[minheight];
            tired = min(tired, newtired);
            minheight++;
        } else if (result < houseCount) {
            maxheight++;
        }
    }

    cout << tired << '\n';


    return 0;
}
