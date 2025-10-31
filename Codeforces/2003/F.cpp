#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using iii = pair<int, ii>;

constexpr int Inf = 1000000000;

template<typename T>
void simpleAdd(vector<pair<int, T>>& seq, int capacity, const pair<int, T>& p) {
    for (int i = 0; i < seq.size(); i++)
        if (seq[i].second == p.second) {
            if (seq[i].first >= p.first)
                return;
            seq[i].first = p.first;
            while (i > 0 && seq[i - 1].first < seq[i].first) {
                swap(seq[i - 1], seq[i]);
                i--;
            }
            return;
        }
    auto it = ranges::partition_point(seq, [&](const auto& val) {
        return val.first >= p.first;
    });
    seq.insert(it, p);
    if (seq.size() > capacity)
        seq.pop_back();
}

bool writeSafe(vector<int>& deg, const ii& p) {
    if (deg[p.first] > 4 || deg[p.second] > 4)
        return false;
    deg[p.first]++;
    deg[p.second]++;
    return true;
}

void degreeAdd(vector<iii>& seq, int capacity, iii p, vector<int>& deg) {
    for (int i = 0; i < seq.size(); i++)
        if (seq[i].second == p.second) {
            if (seq[i].first >= p.first)
                return;
            seq[i].first = p.first;
            while (i > 0 && seq[i - 1].first < seq[i].first) {
                swap(seq[i - 1], seq[i]);
                i--;
            }
            return;
        }
    int rlen = 0, pnt = 0;
    while (pnt < seq.size() && seq[pnt].first >= p.first) {
        writeSafe(deg, seq[pnt].second);
        pnt++;
        rlen++;
    }
    while (pnt < seq.size()) {
        auto nxt = seq[pnt++];
        if (writeSafe(deg, p.second))
            seq[rlen++] = p;
        p = std::move(nxt);
    }
    while (seq.size() > rlen)
        seq.pop_back();
    if (seq.size() < capacity && writeSafe(deg, p.second))
        seq.push_back(p);
    for (auto& x : seq | views::values)
        deg[x.first] = deg[x.second] = 0;
}

ii Fix(const ii& p) { return p.first < p.second ? p : ii{p.second, p.first}; }

bool Contains(const ii& p, int x) {
    return p.first == x || p.second == x;
}

int getBest(const vector<iii>& seq, const ii& p) {
    for (auto& x : seq)
        if (!Contains(x.second, p.first) && !Contains(x.second, p.second))
            return x.first;
    return -Inf;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), c(n);
    for (auto& x : a)
        cin >> x;
    for (auto& x : b)
        cin >> x;
    for (auto& x : c)
        cin >> x;
    if (m == 1) {
        cout << *ranges::max_element(c) << "\n";
        return 0;
    }
    vector has2(n, vector<iii>());
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[j] <= a[i] && b[j] != b[i])
                simpleAdd(has2[i], 5, {c[j] + c[i],
                    Fix({b[j], b[i]})});
    if (m == 2) {
        int res = -1;
        for (auto& V : has2)
            if (!V.empty())
                res = max(res, V[0].first);
        cout << res << "\n";
        return 0;
    }
    vector has3(n, vector<iii>());
    vector deg(n + 1, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[j] <= a[i] && b[j] != b[i])
                for (auto& x : has2[j])
                    if (!Contains(x.second, b[i]))
                        degreeAdd(has3[i], 50, {x.first + c[i], x.second},
                            deg);
    if (m == 3) {
        int res = -1;
        for (auto& V : has3)
            if (!V.empty())
                res = max(res, V[0].first);
        cout << res << "\n";
        return 0;
    }
    if (m == 4) {
        int res = -1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                if (a[j] <= a[i] && b[j] != b[i])
                    res = max(res, getBest(has3[j], {b[i], 0}) + c[i]);
        cout << res << "\n";
        return 0;
    }
    int res = -1;
    for (int i = n - 1; i >= 0; i--) {
        vector<ii> my;
        for (int j = i + 1; j < n; j++)
            if (a[i] <= a[j] && b[i] != b[j])
                simpleAdd(my, 5, {c[i] + c[j], b[j]});
        for (int j = 0; j < i; j++)
            if (a[j] <= a[i] && b[j] != b[i])
                for (auto& x : my)
                    if (x.second != b[j])
                        res = max(res, getBest(has3[j], {b[i], x.second}) + x.first);
    }
    cout << res << "\n";
    return 0;
}