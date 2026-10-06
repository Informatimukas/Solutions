#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        array<int, 105> cnt{};
        int n;
        cin >> n;
        while (n--) {
            int a;
            cin >> a;
            cnt[a]++;
        }
        vector<int> res;
        for (int i = 0; i < 105; i++)
            for (int j = 104; j >= 0; j--)
                if (cnt[j] > 0) {
                    res.push_back(j);
                    cnt[j]--;
                }
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
    }
    return 0;
}
