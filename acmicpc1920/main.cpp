#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch(vector<long> &a, int high, int low, int key) {
    while (low < high) {
        int mid = (high + low) / 2;
        if (a[mid] == key) {
            cout << 1 << ' ';
            return 1;
        }
        if (key > a[mid]) { //search high
            low = mid + 1;
        } else { //search low
            high = mid;
        }
    }


    cout << 0 << '\n';
    return 0;
}

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
        binarySearch(a, N, 0, temp);
    }

    return 0;
}