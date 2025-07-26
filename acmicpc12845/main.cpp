#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int levels[N];

    for (int i = 0; i < N; i++) {
        cin >> levels[i];
    }

    sort(levels, levels + N);
    int sum = 0;

    for (int i = N - 1; i > 0; i--) {
        sum += levels[i] + levels[i - 1];
        levels[i - 1] = levels[i];
    }

    cout << sum << '\n';

    return 0;
}
