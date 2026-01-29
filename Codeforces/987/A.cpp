#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<string, string>> seq = {
        {"Power", "purple"}, {"Time", "green"}, {"Space", "blue"},
        {"Soul", "orange"}, {"Reality", "red"}, {"Mind", "yellow"}
    };
    set<string> S;
    for (auto& key : seq | views::keys)
        S.insert(key);
    int n;
    cin >> n;
    while (n--) {
        string value;
        cin >> value;
        for (auto& [k, v] : seq)
            if (value == v)
                S.erase(k);
    }
    cout << S.size() << "\n";
    for (auto& x : S)
        cout << x << "\n";
    return 0;
}
