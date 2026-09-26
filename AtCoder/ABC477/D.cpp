#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    char global = 'a';
    map<int, char> tiled, untiled;
    while (q--) {
        int typ;
        cin >> typ;
        if (typ == 1) {
            int x;
            cin >> x;
            if (tiled.contains(x)) {
                untiled[x] = tiled[x];
                tiled.erase(x);
            } else if (untiled.contains(x)) {
                tiled[x] = untiled[x];
                untiled.erase(x);
            } else {
                tiled[x] = global;
                untiled.erase(x);
            }
        } else {
            char ch;
            cin >> ch;
            global = ch;
            untiled.clear();
        }
    }
    for (int i = 1; i <= n; i++) {
        char res;
        if (tiled.contains(i))
            res = tiled[i];
        else if (untiled.contains(i))
            res = untiled[i];
        else res = global;
        cout << res;
    }
    cout << "\n";
    return 0;
}
