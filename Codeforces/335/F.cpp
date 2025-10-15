#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using llll = pair<ll, ll>;

struct pos {
    ll deltKey{0}, deltValue{0};
    map<ll, ll> M;
    optional<llll> Get(ll key) {
        key -= deltKey;
        auto it = M.lower_bound(key);
        return it != M.end() ? llll{it->first + deltKey, it->second + deltValue} :
            optional<llll>{};
    }
    void Insert(ll key, ll value) {
        key -= deltKey;
        value -= deltValue;
        auto it = M.lower_bound(key);
        if (it != M.end()) {
            if (it->second <= value)
                return;
            if (it->first == key)
                ++it;
        }
        while (it != M.begin()) {
            --it;
            if (it->second >= value)
                M.erase(it++);
            else break;
        }
        M.emplace(key, value);
    }
    void Move(ll key, ll value) {
        deltKey += key;
        deltValue += value;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    pos dp;
    map<int, int, greater<int>> M;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        M[a]++;
    }
    dp.Insert(0, 0);
    for (auto& [value, cnt] : M) {
        vector<llll> seq;
        for (auto it = dp.M.begin(); it != dp.M.end() && dp.deltKey + it->first <= cnt; ++it)
            while (it != dp.M.begin()) {
                auto tmp = prev(it);
                if (static_cast<ll>(value) * (it->first - tmp->first) / 2 > it->second - tmp->second)
                    dp.M.erase(tmp);
                else break;
            }
        for (int i = 1; i <= cnt; i++)
            if (auto got = dp.Get(i))
                seq.emplace_back(got->first - i + (cnt - i),
                    got->second + static_cast<ll>(cnt - i) * value);
        dp.Move(cnt, static_cast<ll>(cnt) * value);
        for (auto& [key, val] : seq)
            dp.Insert(key, val);
    }
    cout << dp.Get(0)->second << "\n";
    return 0;
}
