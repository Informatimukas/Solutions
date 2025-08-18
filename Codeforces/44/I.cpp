#include <bits/stdc++.h>
using namespace std;

struct pos {
    vector<vector<int>> seq;
    int moved;
    vector<int> in;
    pos Add(int ind, int n, int newMoved) const {
        pos res = *this;
        res.moved = newMoved;
        if (ind < res.seq.size())
            res.seq[ind].push_back(n);
        else res.seq.push_back({n});
        res.in.push_back(ind);
        return res;
    }
};

vector<pos> getNew(const vector<pos>& old, int n) {
    vector<pos> nw;
    for (int i = 0; i < old.size(); i++) {
        int my = old[i].seq.size();
        if (i) {
            int ind = nw.back().in[n];
            for (auto& el : nw.back().seq[ind])
                if (el != n && el != old[i].moved) {
                    my = old[i].in[el];
                    break;
                }
        }
        nw.push_back(old[i].Add(my, n, old[i].moved));
        for (int j = 0; j <= old[i].seq.size(); j++)
            if (j != my)
                nw.push_back(old[i].Add(j, n, n));
    }
    return nw;
}

void printVector(const vector<int>& res) {
    cout << "{";
    for (int i = 0; i < res.size(); i++)
        cout << res[i] + 1 << (i + 1 < res.size()? ',': '}');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pos> cur = {{{{0}}, 0, {0}}};
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
        cur = getNew(cur, i);
    cout << cur.size() << "\n";
    ranges::reverse(cur);
    for (auto& p : cur)
        for (int i = 0; i < p.seq.size(); i++) {
            printVector(p.seq[i]);
            cout << (i + 1 < p.seq.size()? ',': '\n');
        }
    return 0;
}