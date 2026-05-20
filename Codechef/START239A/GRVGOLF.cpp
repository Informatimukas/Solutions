#include <bits/stdc++.h>
using namespace std;

void Mark(vector<string>& B, int n, int r, int c) {
    while (r >= B.size())
        B.emplace_back(n, '0');
    B[r][c] = '1';
}

bool Check(const vector<string>& B, int d) {
    int r = 0, c = 0;
    while (r != B.size() - 1 || c != B[0].length() - 1) {
        int nr = r, nc = c;
        for (int i = 0; i < d && nc + 1 < B[nr].length() && B[nr][nc + 1] == '0'; i++)
            nc++;
        while (nr + 1 < B.size() && B[nr + 1][nc] == '0')
            nr++;
        if (nr == r && nc == c)
            return false;
        r = nr;
        c = nc;
    }
    return true;
}

bool verifyAnswer(const vector<string>& B, int n, const string& s) {
    if (B.size() < 1 || B.size() > (3 * n + 1) / 2 || B[0].length() != n)
        return false;
    for (int i = 1; i <= n - 1; i++)
        if (Check(B, i) != s[i] - '0')
            return false;
    return true;
}

vector<string> Solve(string s, int n) {
    vector<string> B;
    int p = n - 1;
    while (p >= 1 && s[p] == '1')
        p--;
    p++;
    int row = -1;
    if (p < n) {
        row = 1;
        Mark(B, n, row, p);
        p--;
    }
    for (; p > 0; p--)
        if (s[p] == '0') {
            row++;
            Mark(B, n, row, p);
        } else if (s[p + 1] == '0') {
            row += 2;
            Mark(B, n, row, p);
        } else Mark(B, n, row, p);
    return B;
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
        if (s[n - 2] != s[n - 1] || s[n - 2] == '1' && s[n - 3] == '0') {
            cout << "-1\n";
            continue;
        }
        s = " " + s;
        auto B = Solve(s, n);
      /*  if (verifyAnswer(B, n, s))
            cout << "Correct" << endl;
        else {
            cout << "Incorrect" << endl;
            cout << s << endl;
            for (auto x : B)
                cout << x << endl;
        }*/
        cout << B.size() << "\n";
        for (auto& x : B)
            cout << x << "\n";
    }
    return 0;
}
