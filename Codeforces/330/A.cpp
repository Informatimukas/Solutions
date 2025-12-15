#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, c;
    cin >> r >> c;
    vector rows(r, false);
    vector cols(c, false);
    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++)
            if (s[j] == 'S')
                rows[i] = cols[j] = true;
    }
    int res = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (!rows[i] || !cols[j])
                res++;
    cout << res << "\n";
    return 0;
}
