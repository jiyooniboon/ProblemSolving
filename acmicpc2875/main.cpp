#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int M, N, K;
    cin >> N >> M >> K;

    int T = min(N / 2, M); // number of teams
    int L = M + N - (3 * T); // leftover

    while(T > 0) {
        if (L < K) {
            T--;
            L += 3;
        } else break;
    }

    cout << T << '\n';

    return 0;
}