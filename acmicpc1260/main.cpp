#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int N, M, V;
vector<pair<int, int>> edges;
queue<int> q;
stack<int> s;
bool visitb[1001];
bool visitd[1001];
vector<int> result;

void dfs(int cur) {
    s.push(cur);
    cout << cur << ' ';
    visitd[cur] = true;

    for (pair<int, int> p : edges) {
        if (p.first == cur && !visitd[p.second]) {
            dfs(p.second);
        } else if (p.second == cur && !visitd[p.first]) {
            dfs(p.first);
        }
    }
}

void bfs() {
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';

        for (pair<int, int> p : edges) {
            if (p.second == cur) {
                if (visitb[p.first]) continue;
                visitb[p.first] = true;
                q.push(p.first);
            } else if (p.first == cur) {
                if (visitb[p.second]) continue;
                visitb[p.second] = true;
                q.push(p.second);
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);


    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({min(a, b), max(a,b)});
    }

    sort(edges.begin(), edges.end());

    dfs(V);
    cout << '\n';

    q.push(V);
    visitb[V] = true;
    bfs();
    cout << '\n';

    return 0;
}
