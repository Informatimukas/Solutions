#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    set<int> was;
    int n;
    cin >> n;
    while (n != 1 && !was.contains(n)) {
        was.insert(n);
        int m = 0;
        while (n) {
            int d = n % 10;
            m += d * d;
            n /= 10;
        }
        n = m;
    }
    cout << (n == 1 ? "Yes" : "No") << "\n";
    return 0;
}
