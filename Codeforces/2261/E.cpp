#include <bits/stdc++.h>
using namespace std;

constexpr int nil = 500000;
constexpr int Maxn = 1000000;

vector<int> mx(Maxn);

bool Check(int need, int k, const string& s) {
    int nil = s.length();
    fill(mx.begin(), mx.begin() + 2 * nil + 1, -1000000000);
    int st = nil;
    int bad = 0;
    mx[st] = bad;
    for (int i = 0; i < s.length(); i++) {
        st += s[i] == '(' ? 1 : -1;
        bad += s[i] == ')';
        if (st - need >= 0 && bad - mx[st - need] <= k)
            return true;
        mx[st] = bad;
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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int res = 0;
        for (int i = 0, j; i < n; i = j) {
            j = i;
            while (j < n && s[i] == s[j])
                j++;
            if (s[i] == '(')
                res = max(res, j - i);
        }
        int bad = 0;
        int st = 0;
        for (auto ch : s) {
            if (ch == '(')
                st++;
            else {
                st--;
                bad++;
            }
            if (bad <= k)
                res = max(res, st + k);
        }
        res = min(res, n / 2);
        int lef = 1, rig = n / 2;
        while (lef <= rig) {
            int mid = (lef + rig) / 2;
            if (Check(mid, k, s))
                lef = mid + 1;
            else rig = mid - 1;
        }
        res = max(res, rig);
        cout << res << "\n";
    }
    return 0;
}
