#include <bits/stdc++.h>
using namespace std;

bool Check(const string& s, int b) {
    for (int i = 0; i < b; i++) {
        bool ok = true;
        for (int j = i; j < s.length(); j += b)
            if (s[j] != 'X') {
                ok = false;
                break;
            }
        if (ok)
            return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        vector<int> seq;
        for (int i = s.length(); i > 0; i--)
            if (s.length() % i == 0 && Check(s, i))
                seq.push_back(i);
        cout << seq.size();
        for (auto b : seq)
            cout << " " << s.length() / b << "x" << b;
        cout << "\n";
    }
    return 0;
}
