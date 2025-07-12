#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    vector<int> a;
    vector<int> b;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
        b.push_back(temp);
    }

    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    for (int i : a) {
        cout << lower_bound(b.begin(), b.end(), i) - b.begin() << ' ';
    }

    return 0;
}