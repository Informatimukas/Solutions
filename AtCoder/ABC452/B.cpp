#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            if (i == 0 || j == 0 || i == r - 1 || j == c - 1)
                cout << "#";
            else cout << ".";
        cout << "\n";
    }
    return 0;
}
