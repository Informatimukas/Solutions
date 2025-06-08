#include <bits/stdc++.h>
using namespace std;

const int Maxn = 52;

int n, m;
string B[Maxn];

int main()
{
    int mnr = Maxn, mxr = -Maxn;
    int mnc = Maxn, mxc = -Maxn;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> B[i];
        for (int j = 0; j < m; j++)
            if (B[i][j] == '*') {
                mnr = min(mnr, i);
                mxr = max(mxr, i);
                mnc = min(mnc, j);
                mxc = max(mxc, j);
            }
    }
    for (int i = mnr; i <= mxr; i++) {
        for (int j = mnc; j <= mxc; j++)
            printf("%c", B[i][j]);
        printf("\n");
    }
    return 0;
}
