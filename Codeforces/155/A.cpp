#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a;
    cin >> a;
    int mn = a, mx = a;
    int res = 0;
    for (int i = 1; i < n; i++) {
        cin >> a;
        if (a < mn) {
            mn = a;
            res++;
        }
        if (a > mx) {
            mx = a;
            res++;
        }
    }
    cout << res << "\n";
    return 0;
}