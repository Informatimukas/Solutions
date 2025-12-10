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
        if (a[i].second == a[ni].second) {
            rows[a[i].second].st[max(a[i].first, a[ni].first)]++;
            rows[a[i].second].st[min(a[i].first, a[ni].first) - 1]--;
        } else if (a[i].second < a[ni].second)
            for (int j = a[i].second; j <= a[ni].second; j++)
                rows[j].st[a[i].first]++;
        else for (int j = a[i].second; j >= a[ni].second; j--)
            rows[j].st[a[i].first - 1]--;
    }
    for (auto& r : rows) {
        int cur = 0, rig = 0;
        for (auto& [key, val] : r.st | views::reverse) {
            cur += val;
            if (cur < 0) {
                cout << "cur = " << cur << endl;
                for (auto& [key, val] : r.st)
                    cout << key << " " << val << endl;
                return 0;
            }
            if (cur != 0) {
                if (!rig)
                    rig = key;
            } else {
                if (rig)
                    r.edges.emplace_back(key + 1, rig);
                rig = 0;
            }
        }
        ranges::reverse(r.edges);
       /* if (!r.edges.empty()) {
            cout << "newy" << endl;
            for (auto& e : r.edges)
                cout << " " << e.first << " " << e.second;
            cout << endl;
        }*/
    }
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