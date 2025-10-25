#include <bits/stdc++.h>
using namespace std;

vector<int> Ask(const vector<int>& seq) {
    cout << "? " << seq.size();
    for (auto& x : seq)
        cout << " " << x + 1;
    cout << endl;
    vector<int> res;
    int c;
    cin >> c;
    res.resize(c);
    for (auto& x : res) {
        cin >> x;
        x--;
    }
    return res;
}

void Print(const vector<int>& seq, int n) {
    cout << "!";
    for (int i = 0; i <= n; i++)
        cout << " " << seq[i] + 1;
    cout << endl;
}

void Solve(int n) {
    vector seq(n * n + 1, n + 1);
    for (int i = 1; i <= n; i++) {
        vector<int> ask;
        for (int j = 0; j < seq.size(); j++)
            if (seq[j] == n + 1)
                ask.push_back(j);
        auto got = Ask(ask);
        if (got.size() > n) {
            Print(got, n);
            return;
        }
        for (auto& x : got)
            seq[x] = i;
    }
    int col = n + 1;
    vector<int> res;
    for (int i = seq.size() - 1; i >= 0; i--)
        if (seq[i] == col) {
            res.push_back(i);
            col--;
        }
    ranges::reverse(res);
    Print(res, n);
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
        Solve(n);
    }
    return 0;
}
