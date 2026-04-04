#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int lst = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (lst + 15 < a) {
            cout << lst + 15 << "\n";
            return 0;
        }
        lst = a;
    }
    cout << min(90, lst + 15) << "\n";
    return 0;
}
