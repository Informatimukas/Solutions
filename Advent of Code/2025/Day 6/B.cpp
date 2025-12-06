#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll parseNumber(const vector<string>& B, int col) {
    ll res = 0;
    for (int i = 0; i + 1 < B.size(); i++)
        if (isdigit(B[i][col]))
            res = 10 * res + (B[i][col] - '0');
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    vector<string> B;
    string s;
    while (getline(cin, s))
        B.push_back(s);
    int from = B[0].length() - 1;
    ll res = 0;
    for (int j = B[0].length() - 1; j >= 0; j--)
        if (B.back()[j] == '+' || B.back()[j] == '*') {
            vector<ll> nums;
            for (int k = j; k <= from; k++) {
                ll got = parseNumber(B, k);
                if (got)
                    nums.push_back(got);
            }
            from = j - 1;
            if (B.back()[j] == '+')
                for (auto x : nums)
                    res += x;
            else {
                ll cur = 1;
                for (auto x : nums)
                    cur *= x;
                res += cur;
            }
        }
    cout << res << endl;
    return 0;
}