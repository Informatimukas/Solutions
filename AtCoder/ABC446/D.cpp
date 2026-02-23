#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<int, int> M;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        M[a] = max(M[a], M[a - 1] + 1);
        res = max(res, M[a]);
    }
    cout << res << "\n";
    return 0;
}
