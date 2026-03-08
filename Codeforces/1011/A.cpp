#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    array<bool, 26> was{};
    string s;
    cin >> s;
    for (auto ch : s)
        was[ch - 'a'] = true;
    int nxt = 0, lft = k, res = 0;
    while (nxt < was.size() && lft > 0)
        if (was[nxt]) {
            res += nxt + 1;
            lft--;
            nxt += 2;
        } else ++nxt;
    cout << (lft ? -1 : res) << "\n";
    return 0;
}
