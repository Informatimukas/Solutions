#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using llll = pair<ll, ll>;

llll simpleAdd(const llll& fir, const llll& sec) {
    return {fir.first + sec.first, fir.second + sec.second};
}

llll oneMoreAdd(const llll& fir, const llll& sec) {
    return {fir.first + sec.first, fir.second + sec.second + sec.first};
}

int main() {
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
        array<array<llll, 2>, 2> zers;
        array<llll, 2> ones;
        ll res = 0;
        for (int i = 0; i < a.size(); i++) {
            array<array<llll, 2>, 2> nzers;
            array<llll, 2> nones;
            if (a[i] == 1) {
                // begin
                nones[1] = simpleAdd(nones[1], {1, 0});
                // from 0
                nones[1] = simpleAdd(nones[1], zers[1][0]);
                nones[1] = simpleAdd(nones[1], zers[1][1]);
                nones[1] = simpleAdd(nones[1], zers[0][1]);
                nones[0] = oneMoreAdd(nones[0], zers[0][0]);
                // from 1
                nones[1] = simpleAdd(nones[1], ones[0]);
                nones[0] = oneMoreAdd(nones[0], ones[1]);
                // end
                res += nones[0].second + nones[1].second;
            } else {
                // begin
                nzers[1][1] = simpleAdd(nzers[1][1], {1, 0});
                // from 0
                nzers[0][0] = oneMoreAdd(nzers[0][0], zers[1][0]);
                nzers[0][1] = oneMoreAdd(nzers[0][1], zers[1][1]);
                nzers[1][0] = simpleAdd(nzers[1][0], zers[0][0]);
                nzers[1][1] = simpleAdd(nzers[1][1], zers[0][1]);
                // from 1
                nzers[1][1] = simpleAdd(nzers[1][1], ones[0]);
                nzers[1][0] = simpleAdd(nzers[1][0], ones[1]);
                // end
                for (int c = 0; c < 2; c++)
                    for (int d = 0; d < 2; d++)
                        res += nzers[c][d].second;
            }
            zers = std::move(nzers);
            ones = std::move(nones);
        }
        cout << res << "\n";
    }
    return 0;
}