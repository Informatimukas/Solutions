#include <bits/stdc++.h>
using namespace std;

map<int, int> getMap(const string& s) {
    map<int, int> res;
    vector<int> seq;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '(')
            seq.push_back(i);
        else if (seq.empty())
            return {};
        else {
            res.emplace(seq.back(), i);
            seq.pop_back();
        }
    if (!seq.empty())
        return {};
    return res;
}

bool Check(map<int, int>& M, int n, int k) {
    auto it = M.begin();
    while (it != M.end() && it->second == n) {
        M.erase(it++);
        n--;
    }
    while (it != M.end() && it->first + 1 == it->second)
        ++it;
    if (it == M.end())
        return k % 2;
    if (n - it->first + 1 > k)
        return true;
    it = M.end();
    while (it != M.begin() && prev(it)->first + 1 == n) {
        --it;
        n -= 2;
    }
    if (n - M.begin()->first + 1 > k)
        return true;
    return k % 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string s;
        int k;
        cin >> s >> k;
        auto got = getMap(s);
        if (got.empty()) {
            cout << "First\n";
            continue;
        }
        cout << (Check(got, s.length() - 1, k) ? "First" : "Second") << "\n";
    }
    return 0;
}
