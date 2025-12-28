#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

optional<string> checkOne(const string& s, const string& need) {
    string res(need.length(), 'A');
    int has = -1;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '0' && need[i] == '0') {
            if (has == -1)
                has = i;
            res[i] = 'B';
        }
    if (has == -1) {
        for (int i = 0; i < s.length(); i++)
            if (s[i] == '1' && need[i] == '1')
                res[i] = 'B';
        return res;
    }
    int pnt = 0;
    for (int i = 0; i < has; i++) {
        res[i] = 'B';
        while (s[pnt] == '1' || need[pnt] == '0')
            ++pnt;
        res[pnt++] = 'B';
    }
    int l = 0, r = s.length();
    while (l < r) {
        if (res[l] == 'B') {
            ++l;
            continue;
        }
        if (res[r - 1] == 'B') {
            --r;
            continue;
        }
        if (s[l] != need[r - 1] || need[l] != s[r - 1])
            return {};
        ++l;
        --r;
    }
    return res;
}

string Reverse(string s, const array<vector<int>, 2>& seq) {
    for (auto& V : seq) {
        int l = 0, r = V.size();
        while (l < r) {
            int ind1 = V[l], ind2 = V[r - 1];
            swap(s[ind1], s[ind2]);
            ++l;
            --r;
        }
    }
    return s;
}

vector<string> Solve(const string& s) {
    string need = s;
    ranges::sort(need);
    if (s == need)
        return {};
    auto got = checkOne(s, need);
    if (got)
        return {*got};
    array<vector<int>, 2> arr{};
    string tmp = s;
    ranges::reverse(tmp);
    return {string(s.length(), 'A'), *checkOne(tmp, need)};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s(n, '?');
        for (auto& ch : s)
            cin >> ch;
        auto res = Solve(s);
        cout << res.size() << "\n";
        for (auto& s : res)
            cout << s << "\n";
    }
    return 0;
}
