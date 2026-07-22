#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> seq;
    for (int i = 1; i <= 9; i++) {
        int cur = 0;
        for (int j = 0; j < 9; j++) {
            cur = 10 * cur + i;
            seq.push_back(cur);
        }
    }
    ranges::sort(seq);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << distance(seq.begin(), ranges::upper_bound(seq, n)) << "\n";
    }
    return 0;
}
