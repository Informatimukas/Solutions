#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> B(n);
    for (auto& x : B)
        cin >> x;
    int rise = 0, des = 0;
    int lst = -1;
    for (int j = 0; j < m; j++) {
        int i = 0;
        while (B[i][j] == '.')
            i++;
        if (j) {
            rise = max(rise, lst - i);
            des = max(des, i - lst);
        }
        lst = i;
    }
    cout << rise << " " << des << "\n";
    return 0;
}
