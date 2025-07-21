#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;

    int coins[] = {25, 10, 5, 1};

    for (int i = 0; i < T; i++) {
        int C;
        cin >> C;

        for (int j = 0; j < 4; j++) {
            cout << C / coins[j] << ' ';
            C = C % coins[j];
        }

        cout << '\n';
    }

    return 0;
}