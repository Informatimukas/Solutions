#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using llll = pair<ll, ll>;

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
        auto off = (distance(a.begin(), ranges::max_element(a)) + 1) % n;
        vector<ll> res(n);
        vector<llll> seq;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            res[(i + off) % n] += sum;
            ll add = a[(i + off) % n], cnt = 1;
            while (!seq.empty() && seq.back().first <= add) {
                sum -= seq.back().first * seq.back().second;
                cnt += seq.back().second;
                seq.pop_back();
            }
            sum += add * cnt;
            seq.emplace_back(add, cnt);
        }
        seq.clear();
        sum = -a[(n - 1 + off) % n];
        for (int i = n - 1; i >= 0; i--) {
            ll add = a[(i + off) % n], cnt = 1;
            while (!seq.empty() && seq.back().first <= add) {
                sum -= seq.back().first * seq.back().second;
                cnt += seq.back().second;
                seq.pop_back();
            }
            sum += add * cnt;
            res[(i + off) % n] += sum;
            seq.emplace_back(add, cnt);
        }
        for (int i = 0; i < n; i++)
            cout << res[i] << (i + 1 < n ? ' ' : '\n');
    }
    return 0;
}
