#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll Count(int lvl, int lft) {
    if (lvl >= 20) return 1;
    ll res = 0;
    if (lft) res += Count(lvl + 1, lft - 1);
    res += 2 * Count(lvl + 1, lft);
    return res;
}

int main() {
    cout << Count(0, 5) << "\n";
    return 0;
}