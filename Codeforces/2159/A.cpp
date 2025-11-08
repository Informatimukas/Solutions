#include <bits/stdc++.h>
using namespace std;

int getVal(const vector<int>& seq) {
    cout << "? " << seq.size();
    for (auto& x : seq)
        cout << " " << x;
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
        vector a(2 * n + 1, 0);
        vector seq = {1};
        vector<int> known;
        for (int i = 2; i <= 2 * n; i++) {
            seq.push_back(i);
            int got = getVal(seq);
            if (got > 0) {
                a[i] = got;
                known.push_back(i);
                seq.pop_back();
            }
        }
        for (int i = 2 * n; i >= 1; i--)
            if (!a[i]) {
                known.push_back(i);
                a[i] = getVal(known);
                known.pop_back();
            }
        cout << "!";
        for (int i = 1; i <= 2 * n; i++)
            cout << " " << a[i];
        cout << endl;
    }
    return 0;
}
