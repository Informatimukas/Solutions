#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll mod = 1000000007;

ll Solve(const vector<int>& a) {
    set forb(a.begin(), a.end());
    deque<int> D;
    for (int i = 0; i <= a.size(); i++)
        if (!forb.contains(i))
            D.push_back(i);
    ll res = 1;
    int cnt = 0;
    for (int i = a.size() - 1; i >= 0; i--)
        if (i == 0 && a[0] == a.size() || i > 0 && a[i] == a[i - 1]) {
            while (!D.empty() && D.front() < a[i]) {
                cnt++;
                D.pop_front();
            }
            res = res * cnt % mod;
            cnt--;
        } else if (i == 0 && a[0] > a.size() || i > 0 && a[i] > a[i - 1])
            return 0;
    if (res == 0)
        return res;
    for (int i = 0; i <= a.size(); i++)
        if (!forb.contains(i))
            D.push_back(i);
    set<int> allowed;
    for (int i = 0; i < a.size(); i++) {
        while (!D.empty() && D.back() >= a[i]) {
            allowed.insert(D.back());
            D.pop_back();
        }
        if (i == 0 && a[0] == a.size() || i > 0 && a[i] == a[i - 1]) {
            allowed.insert(D.back());
            D.pop_back();
        } else {
            if (i > 0)
                allowed.insert(a[i - 1]);
            else allowed.insert(a.size());
            res = res * static_cast<ll>(allowed.size()) % mod;
        }
    }
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
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        cout << Solve(a) << "\n";
    }
    return 0;
}
