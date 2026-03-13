#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int countLeft(const vector<int>& a, const vector<ll>& sum, const vector<int>& seq,
    int lef, int ind) {
    int res = 0;
    if (sum[lef] >= a[ind])
        ++res;
    for (auto z : seq)
        if (z > lef && z < ind && a[z] > sum[z - 1] + a[ind] ||
            z > ind && a[z] > sum[z - 1])
            ++res;
    return res;
}

int countRight(const vector<int>& a, const vector<ll>& sum, const vector<int>& seq,
    int rig, int ind) {
    int res = 0;
    if (sum[rig] - a[ind] >= a[ind])
        ++res;
    for (auto z : seq)
        if (z > rig && a[z] > sum[z - 1])
            ++res;
    return res;
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
        vector<int> a(n + 1);
        vector<ll> sum(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum[i] = a[i] + sum[i - 1];
        }
        vector<int> seq;
        for (int i = 1; i <= n; i++)
            if (a[i] > sum[i - 1])
                seq.push_back(i);
        for (int i = 1; i <= n; i++) {
            int lef = 1, rig = i - 1;
            while (lef <= rig) {
                int mid = (lef + rig) / 2;
                if (sum[mid] >= a[i])
                    rig = mid - 1;
                else lef = mid + 1;
            }
            int lef2 = 0, rig2 = rig;
            while (lef2 <= rig2) {
                int mid = (lef2 + rig2) / 2;
                if (countLeft(a, sum, seq, mid, i) <= k)
                    rig2 = mid - 1;
                else lef2 = mid + 1;
            }
            int res = rig - rig2;
            lef2 = rig + 1, rig2 = i - 1;
            while (lef2 <= rig2) {
                int mid = (lef2 + rig2) / 2;
                if (countLeft(a, sum, seq, mid, i) <= k)
                    rig2 = mid - 1;
                else lef2 = mid + 1;
            }
            res += i - 1 - rig2;
            lef = i + 1, rig = n;
            while (lef <= rig) {
                int mid = (lef + rig) / 2;
                if (sum[mid] >= 2 * a[i])
                    rig = mid - 1;
                else lef = mid + 1;
            }
            lef2 = i + 1, rig2 = rig;
            while (lef2 <= rig2) {
                int mid = (lef2 + rig2) / 2;
                if (countRight(a, sum, seq, mid, i) <= k)
                    rig2 = mid - 1;
                else lef2 = mid + 1;
            }
            res += rig - rig2;
            lef2 = rig + 1, rig2 = n;
            while (lef2 <= rig2) {
                int mid = (lef2 + rig2) / 2;
                if (countRight(a, sum, seq, mid, i) <= k)
                    rig2 = mid - 1;
                else lef2 = mid + 1;
            }
            res += n - rig2;
            cout << res << (i + 1 <= n ? ' ' : '\n');
        }
    }
    return 0;
}
