#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

constexpr int Maxv = 105;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        array<int, Maxv> cnt{};
        int my = 0;
        vector<int> seq;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] != -1) {
                seq.push_back(i);
                if (a[i] == x)
                    my++;
                else cnt[a[i]]++;
            }
        }
        vector<ii> srt;
        for (int i = 1; i < Maxv; i++)
            if (cnt[i])
                srt.emplace_back(cnt[i], i);
        ranges::sort(srt);
        int pnt = 0;
        while (my > 0) {
            my--;
            a[seq[pnt++]] = x;
        }
        int cur = 0;
        while (pnt < seq.size()) {
            while (srt[cur].first == 0)
                cur = (cur + 1) % srt.size();
            a[seq[pnt++]] = srt[cur].second;
            srt[cur].first--;
            cur = (cur + 1) % srt.size();
        }
        ranges::fill(cnt, 0);
        array<int, Maxv> freq{};
        set<ii, greater<ii>> S;
        for (auto& num : a)
            if (num == -1) {
                auto it = S.begin();
                auto it2 = next(S.begin());
                if (it2 == S.end() || it->first > it2->first)
                    cnt[it->second]++;
            } else {
                cnt[num]++;
                S.erase({freq[num], num});
                S.insert({++freq[num], num});
            }
        int res1 = cnt[x];
        int res2 = 0;
        for (int i = 0; i < cnt.size(); i++)
            if (i != x)
                res2 = max(res2, cnt[i]);
        cout << (res1 > res2 ? "Yes" : "No") << "\n";
    }
    return 0;
}
