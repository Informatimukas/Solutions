#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    if (m % n) {
        cout << "-1\n";
        return 0;
    }
    m /= n;
    int res = 0;
    while (m % 2 == 0) {
        res++;
        m /= 2;
    }
    while (m % 3 == 0) {
        res++;
        m /= 3;
    }
    cout << (m > 1 ? -1 : res) << "\n";
    return 0;
}
