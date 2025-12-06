#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    vector<string> B;
    string s;
    while (getline(cin, s))
        B.push_back(s);
    vector<vector<ll>> nums(B.size() - 1);
    for (int i = 0; i + 1 < B.size(); i++) {
        stringstream ss(B[i]);
        ll x;
        while (ss >> x)
            nums[i].push_back(x);
    }
    vector<char> ops;
    stringstream ss(B.back());
    char ch;
    while (ss >> ch)
        ops.push_back(ch);
    ll res = 0;
    for (int j = 0; j < ops.size(); j++)
        if (ops[j] == '+') {
            ll cur = 0;
            for (auto& num : nums)
                cur += num[j];
            res += cur;
        } else {
            ll cur = 1;
            for (auto& num : nums)
                cur *= num[j];
            res += cur;
        }
    cout << res << endl;
    return 0;
}