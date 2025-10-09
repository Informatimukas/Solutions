#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    map<string, string> M;
    while (T--) {
        string key, val;
        cin >> key >> val;
        if (!M.contains(key))
            M[key] = key;
        auto p = M[key];
        M.erase(key);
        M[val] = p;
    }
    cout << M.size() << "\n";
    for (auto& p : M)
        cout << p.second << " " << p.first << "\n";
    return 0;
}
