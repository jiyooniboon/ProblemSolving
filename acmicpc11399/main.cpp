#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int a[N];

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    sort(a, a + N);
    int sum = 0;

    for (int i = 0; i < N; i++) {
        sum += (N - i) * a[i];
    }

    cout << sum << '\n';

    return 0;
}
