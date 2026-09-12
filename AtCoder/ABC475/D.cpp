#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 10000000;

array<char, 26> maps;
array<char, 10> mapp;

bool Check(const string& s, int x) {
    string p = to_string(x);
    if (s.length() != p.length())
        return false;
    ranges::fill(maps, '?');
    ranges::fill(mapp, '?');
    for (int i = 0; i < s.length(); i++) {
        int inds = s[i] - 'a';
        if (maps[inds] != '?' && maps[inds] != p[i])
            return false;
        maps[inds] = p[i];
        int indp = p[i] - '0';
        if (mapp[indp] != '?' && mapp[indp] != s[i])
            return false;
        mapp[indp] = s[i];
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector prime(Maxn, true);
    string s;
    cin >> s;
    for (int i = 2; i < Maxn; i++)
        if (prime[i]) {
            if (Check(s, i)) {
                cout << i << "\n";
                return 0;
            }
            for (int j = i + i; j < Maxn; j += i)
                prime[j] = false;
        }
    cout << "-1\n";
    return 0;
}
