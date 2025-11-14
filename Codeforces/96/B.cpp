#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void genLucky(ll cur, int lft4, int lft7, vector<ll>& seq) {
    if (lft4 == lft7)
        seq.push_back(cur);
    if (lft4)
        genLucky(10 * cur + 4, lft4 - 1, lft7, seq);
    if (lft7)
        genLucky(10 * cur + 7, lft4, lft7 - 1, seq);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<ll> seq;
    genLucky(0, 5, 5, seq);
    ranges::sort(seq);
    int n;
    cin >> n;
    cout << *ranges::lower_bound(seq, n) << "\n";
    return 0;
}