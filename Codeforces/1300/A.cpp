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
        int res = 0, sum = 0;
        while (n--) {
            int a;
            cin >> a;
            if (a == 0) {
                res++;
                a++;
            }
            sum += a;
        }
        if (sum == 0)
            res++;
        cout << res << "\n";
    }
    return 0;
}