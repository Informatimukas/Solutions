#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

constexpr int Maxa = 20;
constexpr int Maxb = 21;

int Ask(int u, int v, int w) {
    cout << "? " << u << " " << v << " " << w << endl;
    int res;
    cin >> res;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int h;
    cin >> h;
    int n = (1 << h) - 1;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    vector<ii> seq(Maxa);
    vector M(Maxa, map<int, int>());
    vector my(Maxa, vector<int>());
    for (int i = 0; i < Maxa; i++) {
        seq[i].first = uniform_int_distribution(1, n)(rng);
        seq[i].second = (seq[i].first - 1 +
            uniform_int_distribution(1, n - 1)(rng)) % n + 1;
        vector<int> a;
        for (int j = 1; j <= n; j++)
            if (j != seq[i].first && j != seq[i].second)
                a.push_back(j);
        ranges::shuffle(a, rng);
        for (int j = 0; j < Maxb && j < a.size(); j++)
            ++M[i][Ask(seq[i].first, seq[i].second, a[j])];
        for (auto& val : M[i] | views::values)
            my[i].push_back(val);
        ranges::sort(my[i], greater());
    }
    int best = 0;
    for (int i = 1; i < Maxa; i++)
        if (my[i] < my[best])
            best = i;
    auto [u, v] = seq[best];
    map<int, int> fM;
    for (int i = 1; i <= n; i++)
        if (i != u && i != v)
            ++fM[Ask(u, v, i)];
    for (auto& [key, val] : fM)
        if (val == 1) {
            cout << "! " << key << endl;
            break;
        }
    return 0;
}
