#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

struct pos {
    string s;
    vector<ii> seq;
    bool cost{false};
    void Change(int l, int r) {
        seq.emplace_back(l, r);
        for (int i = l; i <= r; i++)
            s[i] = s[i] == '0' ? '1' : '0';
    }
    void changeDigit(int ind) {
        if (s[0] != s[ind])
            Change(0, ind);
        else {
            Change(0, 1);
            Change(0, ind);
        }
    }
    void ensureDiff() {
        if (s == string(s.length(), s[0])) {
            cost = true;
            Change(0, 0);
        } else if (s[0] == s[1]) {
            int p = 2;
            while (s[0] == s[p])
                ++p;
            Change(1, p);
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        pos A, B;
        cin >> A.s;
        cin >> B.s;
        if (A.s == B.s) {
            cout << "0\n0\n";
            continue;
        }
        A.ensureDiff();
        B.ensureDiff();
        if (A.cost && B.cost) {
            cout << "1\n1\n" << 1 << " " << n << "\n";
            continue;
        }
        for (int i = n - 1; i > 1; --i)
            if (A.s[i] != B.s[i])
                A.changeDigit(i);
        if (A.s[0] != B.s[0])
            A.Change(0, 1);
        int res = (A.cost || B.cost) ? 1 : 0;
        cout << res << "\n";
        auto ans = A.seq;
        ranges::reverse(B.seq);
        ans.insert(ans.end(), B.seq.begin(), B.seq.end());
        cout << ans.size() << "\n";
        for (auto& [a, b] : ans)
            cout << a + 1 << " " << b + 1 << "\n";
    }
    return 0;
}
