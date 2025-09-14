#include <bits/stdc++.h>
using namespace std;

constexpr int Maxk = 20;

struct vertex {
    array<int, Maxk> P{};
    int t;
    int L{0};
    bool inTree{true};
    int lef, rig;
    vector<int> neigh;
    int my{0};
    int nxtUp;
    vector<int> counts;
    int nil{0};
};

void Traverse(int v, vector<vertex>& V) {
    static int cur = 0;
    V[v].lef = ++cur;
    for (auto& u : V[v].neigh) {
        V[u].P[0] = v;
        V[u].L = V[v].L + 1;
        Traverse(u, V);
    }
    V[v].rig = cur;
}

int getLCA(int v, int u, const vector<vertex>& V) {
    if (V[v].L < V[u].L)
        swap(v, u);
    for (int i = Maxk - 1; i >= 0; i--)
        if (V[v].L - (1 << i) >= V[u].L)
            v = V[v].P[i];
    if (v == u)
        return v;
    for (int i = Maxk - 1; i >= 0; i--)
        if (V[v].P[i] != V[u].P[i])
            v = V[v].P[i], u = V[u].P[i];
    return V[v].P[0];
}

void Mark(int a, int b, int val, vector<vertex>& V) {
    while (a != b) {
        V[a].my = val;
        a = V[a].P[0];
    }
}

int Count(vector<vertex>& V, int Maxp) {
    int res = 0;
    for (int i = 1; i < V.size(); i++)
        if (V[i].my && V[i].inTree) {
            if (V[i].t < -Maxp)
                res++;
            else if (V[i].t <= Maxp)
                V[V[i].my].counts[V[i].t + Maxp]++;
        }
    return res;
}

void Propagate(vector<vertex>& V) {
    for (int i = 1; i < V.size(); i++)
        if (V[i].my)
            V[i].t -= V[V[i].my].nil;
}

int Update(int v, int Maxp, vector<vertex>& V) {
    int res = 0;
    V[v].inTree ^= true;
    int a = V[v].my;
    if (V[v].t < -Maxp)
        if (V[v].inTree)
            res++;
        else res--;
    else if (V[v].t <= Maxp) {
        int rl = V[v].t - V[a].nil;
        if (rl < 0)
    }
    if (V[v].inTree)
}

vector<int> Solve(const vector<int>& quer, vector<vertex>& V) {
    int Maxp = quer.size() - 1;
    int siz = 2 * Maxp + 1;
    auto seq = quer;
    seq.push_back(1);
    auto byLef = [&V](int a, int b) {
        return V[a].lef < V[b].lef;
    };
    ranges::sort(seq, byLef);
    seq.erase(ranges::unique(seq).begin(), seq.end());
    int lim = seq.size();
    for (int i = 1; i < lim; i++)
        seq.push_back(getLCA(seq[i - 1], seq[i], V));
    ranges::sort(seq, byLef);
    seq.erase(ranges::unique(seq).begin(), seq.end());
    vector<int> S;
    for (auto& v : seq) {
        while (!S.empty() && V[S.back()].rig < V[v].lef)
            S.pop_back();
        V[v].nxtUp = S.empty() ? 0 : S.back();
        S.push_back(v);
        V[v].counts = vector(siz, 0);
        Mark(v, V[v].nxtUp, v, V);
    }
    vector<int> res;
    int curRes = Count(V, Maxp);
    for (auto& v : quer) {

    }
    Propagate(V);
    for (auto& v : seq) {
        V[v].counts.clear();
        V[v].nil = V[v].my = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vertex> V(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> V[i].P[0];
        V[V[i].P[0]].neigh.push_back(i);
    }
    for (int i = 1; i <= n; i++)
        cin >> V[i].t;
    Traverse(1, V);
    for (int j = 1; j < Maxk; j++)
        for (int i = 1; i <= n; i++)
            V[i].P[j] = V[V[i].P[j - 1]].P[j - 1];
    int Maxp = sqrt(n) + 2;

    return 0;
}