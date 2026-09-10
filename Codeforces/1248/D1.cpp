#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

array<ii, 2000> seq;
int st, en;

void Add(ii p) {
    while (st < en && p.first <= seq[en - 1].first)
        --en;
    seq[en++] = std::move(p);
}

int Solve(const string& s) {
    st = en = 0;
    int cur = 0;
    for (int i = 0; i < s.length(); i++) {
        cur += s[i] == '(' ? 1 : -1;
        Add({cur, i});
    }
    int res = 0;
    cur = 0;
    for (int i = 0; i < s.length(); i++) {
        cur += s[i] == '(' ? 1 : -1;
        if (seq[st].second == i)
            ++st;
        Add({cur, s.length() + i});
        res += seq[st].first >= cur;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int res = 0;
    for (auto ch : s)
        res += ch == '(' ? 1 : -1;
    if (res != 0) {
        cout << "0\n";
        cout << "1 1\n";
        return 0;
    }
    res = -1;
    int bi, bj;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++) {
            swap(s[i], s[j]);
            int cand = Solve(s);
            if (cand > res) {
                res = cand;
                bi = i; bj = j;
            }
            swap(s[i], s[j]);
        }
    cout << res << "\n";
    cout << bi + 1 << " " << bj + 1 << "\n";
    return 0;
}
