#include <bits/stdc++.h>
using namespace std;

constexpr int Maxd = 10;

bool Check(array<int, Maxd> cnt, int x) {
    int a = min(x, cnt[0]);
    int b = x - a;
    cnt[0] -= a;
    cnt[1] -= b;
    if (cnt[1] < 0)
        return false;
    int cur = cnt[0] + cnt[1];
    cur -= b;
    if (cur < 0)
        return false;
    cur += cnt[2] + cnt[3] + cnt[4] + cnt[5];
    cur -= x;
    if (cur < 0)
        return false;
    cur += cnt[6] + cnt[7] + cnt[8] + cnt[9];
    cur -= (x + a);
    return cur >= 0;
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
        string s;
        cin >> s;
        array<int, Maxd> cnt{};
        for (auto ch : s)
            cnt[ch - '0']++;
        int lef = 1, rig = n;
        while (lef <= rig) {
            int mid = (lef + rig) / 2;
            if (Check(cnt, mid))
                lef = mid + 1;
            else rig = mid - 1;
        }
        cout << rig << "\n";
    }
    return 0;
}
