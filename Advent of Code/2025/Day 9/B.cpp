#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using llll = pair<ll, ll>;
using ll3 = pair<ll, llll>;

constexpr int Inf = 1000000000;
constexpr int lim = 100000;

struct row {
    map<int, int> st;
    vector<llll> edges;
    void Insert(int key) {
        if (!st.contains(key))
            st.emplace(key, 1);
    }
};

bool Check(const vector<row>& rows, llll a, llll b) {
    if (a.first > b.first)
        swap(a.first, b.first);
    if (a.second > b.second)
        swap(a.second, b.second);
    for (int y = a.second; y <= b.second; y++) {
        auto it = ranges::lower_bound(rows[y].edges, llll{a.first + 1, 0});
        if (it == rows[y].edges.begin())
            return false;
        --it;
        if (it->second < b.first)
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    vector<llll> a;
    string s;
    while (getline(cin, s)) {
        s[s.find(',')] = ' ';
        stringstream ss(s);
        ll x, y;
        ss >> x >> y;
        a.emplace_back(x, y);
    }
    vector<row> rows(lim);
    for (int i = 0; i < a.size(); i++) {
        int ni = (i + 1) % a.size();
        if (min(a[i].second, a[ni].second) <= -1 && -1 <= max(a[i].second, a[ni].second)) {
            cout << a[i].first << " " << a[i].second << endl;
            cout << " " << a[ni].first << " " << a[ni].second << endl;
        }
        if (a[i].second != a[ni].second) {
            if (a[i].second < a[ni].second)
                for (int j = a[i].second; j <= a[ni].second; j++)
                    rows[j].st[a[i].first] = 1;
            else for (int j = a[i].second; j >= a[ni].second; j--)
                rows[j].st[a[i].first] = -1;
        } else rows[a[i].second].edges.emplace_back(min(a[i].first, a[ni].first),
            max(a[i].first, a[ni].first));
    }
    for (int i = 0; i < rows.size(); i++) {
        auto& r = rows[i];
        if (!r.st.empty() && (r.st.begin()->second != -1 ||
            r.st.rbegin()->second != 1)) {
            cout << "i = " << i << endl;
            for (auto& [key, val] : r.st)
                cout << " key " << key << ", val = " << val << endl;
            return 0;
        }
        int rig = 0;
        for (auto& [key, val] : r.st | views::reverse)
            if (rig && val == -1) {
                r.edges.emplace_back(key, rig);
                rig = 0;
            } else if (!rig && val == 1)
                rig = key;
        ranges::sort(r.edges);
        vector<llll> cur;
        for (auto& [fir, sec] : r.edges)
            if (cur.empty() || cur.back().second + 1 < fir)
                cur.emplace_back(fir, sec);
            else cur.back().second = max(cur.back().second, sec);
        r.edges = std::move(cur);
    }
    cout << "ended" << endl;
    vector<ll3> cands;
    for (int i = 0; i < a.size(); i++)
        for (int j = i + 1; j < a.size(); j++) {
            ll cand = (abs(a[i].first - a[j].first) + 1) *
                (abs(a[i].second - a[j].second) + 1);
            cands.push_back({cand, {i, j}});
        }
    ranges::sort(cands, greater());
    for (auto& c : cands) {
        auto& [i, j] = c.second;
        if (Check(rows, a[i], a[j])) {
            cout << c.first << endl;
            break;
        }
    }
    return 0;
}