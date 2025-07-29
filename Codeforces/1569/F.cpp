#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

bool hasEqual(int lvl, const vector<int>& my, vector<bool>& tk, vector<ii>& seq,
    const set<vector<ii>>& S) {
    if (lvl >= my.size())
        return S.contains(seq);
    if (tk[lvl])
        return hasEqual(lvl + 1, my, tk, seq, S);
    for (int i = lvl + 1; i < my.size(); i++)
        if (my[lvl] == my[i] && !tk[i]) {
            tk[i] = true;
            seq.emplace_back(lvl, i);
            if (hasEqual(lvl + 1, my, tk, seq, S))
                return true;
            seq.pop_back();
            tk[i] = false;
        }
    return false;
}

ll countAll(int lvl, vector<int>& cnt, vector<int>& my, ll ways, int k,
    const set<vector<ii>>& S) {
    if (lvl >= my.size()) {
        if (ranges::all_of(cnt, [](int x) {
            return x % 2 == 0;
        })) {
            vector<bool> tk(my.size());
            vector<ii> seq;
            return hasEqual(0, my, tk, seq, S)? ways: 0;
        }
        return 0;
    }
    ll res = 0;
    for (int i = 0; i < cnt.size(); i++) {
        cnt[i]++;
        my[lvl] = i;
        res += countAll(lvl + 1, cnt, my, ways, k, S);
        cnt[i]--;
    }
    ways *= k - static_cast<ll>(cnt.size());
    my[lvl] = cnt.size();
    cnt.push_back(1);
    res += countAll(lvl + 1, cnt, my, ways, k, S);
    cnt.pop_back();
    return res;
}

bool checkPairing(const vector<ii>& seq, const vector<vector<bool>>& adj) {
    vector<int> in(seq.size());
    iota(in.begin(), in.end(), 0);
    do {
        bool ok = true;
        for (int i = 1; i < in.size(); i++) {
            auto& [a, b] = seq[in[i - 1]];
            auto& [c, d] = seq[in[i]];
            bool hasEdges = adj[a][c] && adj[b][d] ||
                adj[a][d] && adj[b][c];
            if (!hasEdges) {
                ok = false;
                break;
            }
        }
        auto& [a, b] = seq[in.back()];
        if (!adj[a][b])
            ok = false;
        if (ok)
            return true;
    } while (ranges::next_permutation(in).found);
    return false;
}

void getCorrectPairings(int lvl, vector<bool> &tk, vector<ii>& seq, set<vector<ii>>& S,
    const vector<vector<bool>>& adj) {
    if (lvl >= tk.size()) {
        if (checkPairing(seq, adj))
            S.insert(seq);
        return;
    }
    if (tk[lvl]) {
        getCorrectPairings(lvl + 1, tk, seq, S, adj);
        return;
    }
    for (int i = lvl + 1; i < tk.size(); i++)
        if (!tk[i]) {
            tk[i] = true;
            seq.emplace_back(lvl, i);
            getCorrectPairings(lvl + 1, tk, seq, S, adj);
            seq.pop_back();
            tk[i] = false;
        }
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector adj(n, vector(n, false));
    while (m--) {
        int v, u; scanf("%d %d", &v, &u);
        v--; u--;
        adj[v][u] = adj[u][v] = true;
    }
    vector<ii> seq;
    vector<bool> tk(n);
    set<vector<ii>> S;
    getCorrectPairings(0, tk, seq, S, adj);
    vector<int> cnt;
    vector<int> my(n);
    printf("%lld\n", countAll(0, cnt, my, 1, k, S));
    return 0;
}