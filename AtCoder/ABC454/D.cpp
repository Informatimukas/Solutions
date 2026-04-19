#include <bits/stdc++.h>
using namespace std;

string Normalize(const string& s) {
    vector<char> S;
    for (int i = 0; i < s.length(); i++) {
        S.push_back(s[i]);
        if (S.size() >= 4 && S[S.size() - 4] == '(' && S[S.size() - 3] == 'x' &&
            S[S.size() - 2] == 'x' && S[S.size() - 1] == ')') {
            S[S.size() - 4] = 'x';
            S.pop_back();
            S.pop_back();
        }
    }
    string res;
    for (auto x : S)
        res += x;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string a, b;
        cin >> a >> b;
        cout << (Normalize(a) == Normalize(b) ? "Yes" : "No") << "\n";
    }
    return 0;
}
