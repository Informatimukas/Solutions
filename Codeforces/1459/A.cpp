#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string r;
        cin >> r;
        string b;
        cin >> b;
        int rcnt = 0, bcnt = 0;
        for (int i = 0; i < n; i++)
            if (r[i] > b[i]) rcnt++;
            else if (r[i] < b[i]) bcnt++;
        if (rcnt > bcnt) cout << "RED\n";
        else if (rcnt < bcnt) cout << "BLUE\n";
        else cout << "EQUAL\n";
    }
    return 0;
}