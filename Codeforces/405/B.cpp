#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> seq;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
        if (s[i] != '.')
            seq.push_back(i);
    if (seq.empty()) {
        cout << n << "\n";
        return 0;
    }
    int res = 0;
    if (s[seq[0]] == 'R')
        res += seq[0];
    if (s[seq.back()] == 'L')
        res += n - 1 - seq.back();
    for (int i = 0; i + 1 < seq.size(); i++)
        if (s[seq[i]] == 'L')
            res += seq[i + 1] - seq[i] - 1;
        else if ((seq[i + 1] - seq[i] - 1) % 2)
            res++;
    cout << res << "\n";
    return 0;
}