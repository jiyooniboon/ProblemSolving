#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    vector<long> a;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    sort(a.begin(), a.end());
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int temp;
        cin >> temp;
        cout << binary_search(a.begin(), a.end(), temp) << '\n';
    }

    return 0;
}