#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count (vector<int> &a, int curIndex, int curSum, int sum, bool empty) {

    if (curIndex == a.size() - 1) {
        if (!empty) {
            if ((curSum == sum) && (curSum + a[curIndex] == sum)) return 2;
            else if ((curSum == sum) || (curSum + a[curIndex] == sum)) return 1;
            else return 0;
        } else {
            if (a[curIndex] == sum) return 1;
            else return 0;
        }
    }

    return count(a, curIndex + 1, curSum + a[curIndex], sum, false) +
        count(a, curIndex + 1, curSum, sum, empty);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, S;
    cin >> N >> S;

    vector<int> a;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    sort(a.begin(), a.end());
    int result = count(a, 0, 0, S, true);
    cout << result << '\n';

    return 0;
}