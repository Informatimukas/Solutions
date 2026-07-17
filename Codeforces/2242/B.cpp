#include <bits/stdc++.h>
using namespace std;

bool Check(const vector<int>& seq) {
    vector<int> my(seq.size());
    my[seq.size() - 1] = 0;
    for (int i = seq.size() - 2; i >= 0; i--)
        if (seq[i] <= 2)
            my[i] = max(my[i + 1] + 1, 1);
        else my[i] = my[i + 1] - 1;
    int cur = 0;
    for (int i = 0; i + 2 < seq.size(); i++) {
        cur += seq[i] <= 1 ? 1 : -1;
        if (cur >= 0 && my[i + 1] >= 0)
            return true;
    }
    return false;
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
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        cout << (Check(a) ? "YES" : "NO") << "\n";
    }
    return 0;
}
