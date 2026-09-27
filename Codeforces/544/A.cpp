#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<int, int> M;
    int k;
    cin >> k;
    string s;
    cin >> s;
    set<char> S;
    S.insert(s[0]);
    vector seq = {0};
    for (int i = 1; i < s.length() && S.size() < k; i++)
        if (!S.contains(s[i])) {
            S.insert(s[i]);
            seq.push_back(i);
        }
    if (S.size() < k) {
        cout << "NO\n";
        return 0;
    }
    seq.push_back(s.length());
    cout << "YES\n";
    for (int i = 0; i + 1 < seq.size(); i++)
        cout << s.substr(seq[i], seq[i + 1] - seq[i]) << "\n";
    return 0;
}
