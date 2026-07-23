#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    bool fir = false;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a % 2) {
            fir = true;
            break;
        }
    }
    cout << (fir ? "First" : "Second") << "\n";
    return 0;
}
