#include <bits/stdc++.h>
using namespace std;

multiset<string> A, B;

void Fix(int m) {
    while (A.size() > m) {
        auto it = prev(A.end());
        B.insert(*it);
        A.erase(it);
    }
    while (A.size() < m) {
        auto it = B.begin();
        A.insert(*it);
        B.erase(it);
    }
}

bool canErase(multiset<string>& S, const string& s) {
    auto it = S.find(s);
    if (it != S.end()) {
        S.erase(it);
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    string T;
    cin >> T;
    vector<string> S(n);
    B.insert(string(k, '1'));
    for (auto& s : S) {
        cin >> s;
        for (int j = 0; j < k; j++)
            s[j] = s[j] == T[j] ? '0' : '1';
        A.insert(s);
    }
    int q;
    cin >> q;
    while (q--) {
        int ind, pos;
        cin >> ind >> pos;
        ind--;
        pos--;
        if (!canErase(A, S[ind]))
            canErase(B, S[ind]);
        S[ind][pos] = S[ind][pos] == '0' ? '1' : '0';
        if (S[ind] < *B.begin())
            A.insert(S[ind]);
        else B.insert(S[ind]);
        Fix(m);
        cout << (S[ind] < *B.begin() ? "Yes" : "No") << "\n";
    }
    return 0;
}
