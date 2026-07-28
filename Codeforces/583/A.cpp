#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    set<int> R, C;
    bool was = false;
    for (int i = 1; i <= n * n; i++) {
        int r, c;
        cin >> r >> c;
        if (!R.contains(r) && !C.contains(c)) {
            R.insert(r);
            C.insert(c);
            if (was)
                cout << " ";
            else was = true;
            cout << i;
        }
    }
    cout << "\n";
    return 0;
}
