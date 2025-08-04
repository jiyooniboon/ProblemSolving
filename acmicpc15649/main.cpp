#include <iostream>

using namespace std;

int N, M;
int ans[9];
bool visit[9] = {};

void dfs(int depth) {

    if (depth == M) { //terminal condition
        for (int i = 0; i < M; i++) cout << ans[i] << ' ';
        cout << '\n';
    }

    for (int i = 0; i < N; i++) {
        if (visit[i + 1]) continue;
        ans[depth] = i + 1;
        visit[i + 1] = true;
        dfs(depth + 1);
        visit[i + 1] = false;
    }

}

int main() {


    cin >> N >> M;

    dfs(0);


}