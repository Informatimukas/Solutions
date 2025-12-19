#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

void getRanks(const vector<vector<ii>>& vals, vector<int>& rnk) {
    ii lst = {-1, -1};
    int col = -1;
    for (int i = 0; i < vals.size(); i++)
        for (auto& [el, sec] : vals[i]) {
            ii cur = {i, sec};
            if (cur != lst) {
                lst = cur;
                ++col;
            }
            rnk[el] = col;
        }
}

void processDelta(int n, int delt, vector<int>& rnk) {
    vector<vector<ii>> nxt(n);
    vector<vector<int>> seq(n);
    for (int j = 0; j < n; j++)
        seq[rnk[j]].push_back(j);
    for (auto& V : seq)
        for (auto el : V) {
            int lst = (el - delt + n) % n;
            nxt[rnk[lst]].emplace_back(lst, rnk[el]);
        }
    getRanks(nxt, rnk);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int k, t;
    cin >> k >> t;
    int n = 1 << k;
    string s;
    cin >> s;
    int z = t % k;
    vector un(s.begin(), s.end());
    ranges::sort(un);
    un.erase(ranges::unique(un).begin(), un.end());
    vector<int> rnk(n);
    for (int i = 0; i < n; i++)
        rnk[i] = distance(un.begin(), ranges::lower_bound(un, s[i]));
    for (int i = 0; i < z; i++)
        processDelta(n, 1 << (k - z + i), rnk);
    for (int i = 0; i < k - z; i++)
        processDelta(n, 1 << i, rnk);
    int ind = distance(rnk.begin(), ranges::min_element(rnk));
    ranges::rotate(s, s.begin() + ind);
    string nw = s;
    int pnt = 0;
    int delt = 1 << (k - z);
    int tims = 1 << z;
    for (int i = 0; i < delt; i++)
        for (int j = 0; j < tims; j++)

    string nw = s;
    while (z--) {
        int pnt = 0;
        for (int i = 0; i < n / 2; i++) {
            nw[pnt++] = s[i];
            nw[pnt++] = s[n / 2 + i];
        }
        s = nw;
    }
    cout << s << "\n";
    return 0;
}
