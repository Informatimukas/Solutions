#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    const string dirs = "v<^>";
    char a, b;
    cin >> a >> b;
    int pa = dirs.find(a), pb = dirs.find(b);
    int n;
    cin >> n;
    if ((pa + n) % 4 == pb)
        if ((pa - n % 4 + 4) % 4 == pb)
            cout << "undefined\n";
        else cout << "cw\n";
    else cout << "ccw\n";
    return 0;
}
