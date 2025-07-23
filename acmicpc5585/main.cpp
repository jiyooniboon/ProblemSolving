#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int coins[] = {500, 100, 50, 10, 5, 1};
    int result = 0;

    int C;
    cin >> C;
    C = 1000 - C;

    for (int j = 0; j < 6; j++) {
        result += C / coins[j];
        C = C % coins[j];
    }

    cout << result << '\n';

    return 0;
}
