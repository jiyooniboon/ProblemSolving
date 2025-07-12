#include <iostream>
#include <map>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    map<int, int> a = {};

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        auto it = a.insert(make_pair(temp, 1));
        if (!it.second) a[temp]++;
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int temp;
        cin >> temp;
        auto it = a.find(temp);
        if (it == a.end()) cout << 0 << ' ';
        else cout << it->second << ' ';
    }

    return 0;
}