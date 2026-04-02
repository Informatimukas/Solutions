#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

vector<int> Ask(int k) {
    cout << "? " << k << endl;
    int q;
    cin >> q;
    vector<int> res(q);
    for (auto& x : res)
        cin >> x;
    return res;
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
        set<ii> S;
        vector<int> cur;
        vector<int> cnt(n + 1);
        vector<bool> closed(n + 1);
        int k = 1;
        while (true) {
            auto nw = Ask(k);
            while (!cur.empty() && (nw.size() < cur.size() ||
                cur.back() != nw[cur.size() - 1])) {
                closed[cur.back()] = true;
                cur.pop_back();
            }
            if (nw.empty())
                break;
            if (closed[nw.back()]) {
                for (int i = 0; i + 1 < nw.size(); i++) {
                    S.insert({nw[i], nw[i + 1]});
                    cnt[nw[i]] += cnt[nw.back()] + 1;
                }
                k += cnt[nw.back()] + 1;
            } else {
                for (int i = 0; i + 1 < nw.size(); i++) {
                    S.insert({nw[i], nw[i + 1]});
                    cnt[nw[i]]++;
                }
                k++;
            }
            cur = nw;
        }
        cout << "! " << S.size() << endl;
        for (auto& [a, b] : S)
            cout << a << " " << b << endl;
    }
    return 0;
}
