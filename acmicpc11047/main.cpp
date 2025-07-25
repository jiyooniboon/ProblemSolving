#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    int coins[N];

    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }

    int count = 0;

    for (int i = N - 1; i >= 0; i--) {
        count += K / coins[i];
        K %= coins[i];
    }

    cout << count << '\n';

    return 0;
}
