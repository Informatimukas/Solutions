#include <bits/stdc++.h>
using namespace std;

bool Check(const vector<char>& seq, int st) {
    for (char ch : seq) {
        if (ch == '(') st++;
        else st--;
        if (st < 0)
            return false;
    }
    return true;
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
        string s;
        cin >> s;
        int cnt = 0;
        vector<char> S;
        for (int i = 0; i < n; i++)
            if (!S.empty() && S.back() == s[i]) {
                S.pop_back();
                cnt++;
            } else S.push_back(s[i]);
        if (cnt % 2 || S.size() % 2 || !Check(S, cnt / 2)) {
            cout << "-1\n";
            continue;
        }
        for (int i = 0; i < cnt / 2; i++)
            cout << "((";
        for (auto& ch : S)
            cout << ch;
        for (int i = 0; i < cnt / 2; i++)
            cout << "))";
        cout << "\n";
    }
    return 0;
}
