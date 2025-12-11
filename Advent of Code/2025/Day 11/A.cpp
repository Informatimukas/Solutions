#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll getWays(const string& s, const map<string, vector<string>>& neigh, map<string, ll>& ways) {
    if (s == "out")
        return 1;
    auto it = ways.find(s);
    if (it != ways.end())
        return it->second;
    ll res = 0;
    auto nit = neigh.find(s);
    if (nit != neigh.end())
        for (auto& u : nit->second)
            res += getWays(u, neigh, ways);
    ways.emplace(s, res);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    map<string, vector<string>> neigh;
    map<string, ll> ways;
    string s;
    while (getline(cin, s)) {
        stringstream ss(s);
        ss >> s;
        string v = s.substr(0, s.length() - 1);
        while (ss >> s)
            neigh[v].push_back(s);
    }
    cout << getWays("you", neigh, ways) << endl;
    return 0;
}
