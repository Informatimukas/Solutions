#include <bits/stdc++.h>
using namespace std;

bool Check3(const vector<int>& seq) {
    cout << "? " << seq.size();
    for (auto x : seq)
        cout << " " << x;
    cout << endl;
    int res;
    cin >> res;
    return (seq.size() - res) % 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int N = 2 * n + 1;
        int l = 1, r = N;
        while (l <= r) {
            int m = (l + r) / 2;
            vector<int> cur(m);
            iota(cur.begin(), cur.end(), 1);
            if (Check3(cur))
                r = m - 1;
            else l = m + 1;
        }
        int res1 = l;
        l = 1, r = N;
        while (l <= r) {
            int m = (l + r) / 2;
            vector<int> cur(N - m + 1);
            iota(cur.begin(), cur.end(), m);
            if (Check3(cur))
                l = m + 1;
            else r = m - 1;
        }
        int res2 = r;
        vector<int> lft;
        for (int i = 1; i <= N; i++)
            if (i != res1 && i != res2)
                lft.push_back(i);
        l = 0, r = lft.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            vector<int> cur;
            for (int i = 0; i <= m; i++)
                cur.push_back(lft[i]);
            cur.push_back(res1);
            cur.push_back(res2);
            if (Check3(cur))
                r = m - 1;
            else l = m + 1;
        }
        int res3 = lft[l];
        cout << "! " << res1 << " " << res2 << " " << res3 << endl;
    }
    return 0;
}
