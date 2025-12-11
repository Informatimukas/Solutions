#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct pos {
    string s;
    bool dac{false}, fft{false};
    bool operator<(const pos& oth) const {
        if (s != oth.s)
            return s < oth.s;
        if (dac != oth.dac)
            return dac < oth.dac;
        return fft < oth.fft;
    }
};

ll getWays(pos p, const map<string, vector<string>>& neigh, map<pos, ll>& ways) {
    if (p.s == "out")
        return p.dac && p.fft;
    if (p.s == "dac")
        p.dac = true;
    if (p.s == "fft")
        p.fft = true;
    auto it = ways.find(p);
    if (it != ways.end())
        return it->second;
    ll res = 0;
    auto nit = neigh.find(p.s);
    if (nit != neigh.end())
        for (auto& u : nit->second)
            res += getWays({u, p.dac, p.fft}, neigh, ways);
    ways.emplace(p, res);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    map<string, vector<string>> neigh;
    map<pos, ll> ways;
    string s;
    while (getline(cin, s)) {
        stringstream ss(s);
        ss >> s;
        string v = s.substr(0, s.length() - 1);
        while (ss >> s)
            neigh[v].push_back(s);
    }
    cout << getWays({"svr", false, false}, neigh, ways) << endl;
    return 0;
}
