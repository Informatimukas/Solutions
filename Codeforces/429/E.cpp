#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

struct pos {
    ii lr;
    int ind;
    bool rev{false};
    bool value{false};
};

void Join(int ind1, int ind2, map<int, vector<int>>& M, vector<pos>& seq) {
    if (ind1 == ind2)
        return;
    if (seq[ind1].lr.second == seq[ind2].lr.second) {
        seq[ind1].value = true;
        seq[ind2].value = false;
        return;
    }
    int lef = min(seq[ind1].lr.second, seq[ind2].lr.second) + 1;
    int rig = max(seq[ind1].lr.second, seq[ind2].lr.second);
    if (lef <= rig) {
        pos nw;
        nw.lr = {lef, rig};
        nw.ind = seq.size();
        seq.push_back(nw);
        seq[ind1].ind = seq[ind2].ind = nw.ind;
        seq[ind1].rev = seq[ind1].lr.second < seq[ind2].lr.second;
        seq[ind2].rev = seq[ind2].lr.second < seq[ind1].lr.second;
        M[nw.lr.first].push_back(nw.ind);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pos> seq(n);
    map<int, vector<int>> M;
    for (int i = 0; i < n; i++) {
        cin >> seq[i].lr.first >> seq[i].lr.second;
        seq[i].ind = i;
        M[seq[i].lr.first].push_back(i);
    }
    int ind = -1;
    for (auto it = M.begin(); it != M.end(); ++it) {
        auto& V = it->second;
        while (V.size() > 1) {
            int ind1 = V.back();
            V.pop_back();
            int ind2 = V.back();
            V.pop_back();
            Join(ind1, ind2, M, seq);
        }
        if (V.empty()) continue;
        if (ind != -1 && seq[ind].lr.second < it->first)
            ind = -1;
        if (ind == -1 || seq[ind].lr.second < seq[V[0]].lr.first) {
            ind = V[0];
            continue;
        }
        if (V[0] != ind) {
            Join(ind, V[0], M, seq);
            ind = -1;
        }
    }
    for (int i = seq.size() - 1; i >= 0; i--)
        if (seq[i].ind != i)
            seq[i].value = seq[seq[i].ind].value ^ seq[i].rev;
    for (int i = 0; i < n; i++)
        cout << seq[i].value << (i + 1 < n ? ' ' : '\n');
    return 0;
}
