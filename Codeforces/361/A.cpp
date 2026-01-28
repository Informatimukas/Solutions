#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int got = i == j ? k : 0;
            cout << got << (j + 1 < n ? ' ' : '\n');
        }
    return 0;
}
