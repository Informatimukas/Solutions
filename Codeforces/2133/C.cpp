#include <bits/stdc++.h>
using namespace std;

int Ask(int x, const set<int>& S) {
    cout << "? " << x << " " << S.size();
    for (auto& el : S)
        cout << " " << el;
    cout << endl;
    int res;
    cin >> res;
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
        vector seq(n + 1, vector<int>());
        set<int> S;
        for (int i = 1; i <= n; i++)
            S.insert(i);
        for (int i = 1; i <= n; i++)
            seq[Ask(i, S)].push_back(i);
        int mx = n;
        while (seq[mx].empty())
            mx--;
        int root = seq[mx][0];
        while (seq[mx].size() > 1) {
            S.erase(seq[mx].back());
            seq[mx].pop_back();
        }
        for (int i = mx - 1; i > 0; i--) {
            for (int j = 0; j < seq[i].size(); j++) {
                S.erase(seq[i][j]);
                if (Ask(seq[mx][0], S) < mx) {
                    S.insert(seq[i][j]);
                    swap(seq[i][j], seq[i][0]);
                    break;
                }
            }
            while (seq[i].size() > 1) {
                S.erase(seq[i].back());
                seq[i].pop_back();
            }
        }
        cout << "! " << mx;
        for (int i = mx; i > 0; i--)
            cout << " " << seq[i][0];
        cout << endl;
    }
    return 0;
}
