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
        int winners = n, losers = 0;
        int res = 0;
        while (winners != 1 || losers != 1) {
            res += losers / 2;
            losers -= losers / 2;
            res += winners / 2;
            losers += winners / 2;
            winners -= winners / 2;
        }
        res++;
        cout << res << "\n";
    }
    return 0;
}