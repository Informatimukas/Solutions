#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> S(n);
    for (auto& x : S)
        cin >> x;
    vector<int> res(n), seq;
    for (int j = 0; j < m; j++) {
        int zer = 0, one = 0;
        for (int i = 0; i < n; i++)
            if (S[i][j] == '0') zer++;
            else one++;
        char good = zer < one? '0': '1';
        for (int i = 0; i < n; i++)
            if (S[i][j] == good)
                res[i]++;
    }
    int best = 0;
    for (int i = 0; i < n; i++) {
        if (res[i] > best) {
            best = res[i];
            seq.clear();
        }
        if (res[i] == best)
            seq.push_back(i);
    }
    for (int i = 0; i < seq.size(); i++)
        cout << seq[i] + 1 << (i + 1 < seq.size()? ' ': '\n');
    return 0;
}
