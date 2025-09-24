#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll oneStep(const map<int, int>& M) {
    int mex = 0;
    while (M.contains(mex))
        mex++;
    ll res = 0;
    for (auto& [key, val] : M)
        if (key > mex || val >= 2)
            res += static_cast<ll>(mex) * val;
        else res += key;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        map<int, int> M;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            M[a]++;
        }
        if (k == 1) {
            cout << oneStep(M) << "\n";
            continue;
        }
        ll res = 0, need = 0;
        for (auto& [key, val] : M) {
            if (key > need) {
                k--;
                break;
            }
            if (val >= 2) {
                k -= 2;
                break;
            }
            need++;
        }
        int cnt = 0;
        for (auto& [key, val] : M)
            if (key > need)
                cnt += val;
        int toVal = k % 2 && cnt > 1 ? need + 1 : need;
        for (auto& [key, val] : M)
            if (key >= need)
                res += static_cast<ll>(toVal) * val;
            else res += key;
        cout << res << "\n";
    }
    return 0;
}