#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int lst = 1000000;
    bool rated = false, unrated = false;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a != b) {
            rated = true;
            break;
        }
        if (a > lst)
            unrated = true;
        lst = a;
    }
    if (rated)
        cout << "rated\n";
    else if (unrated)
        cout << "unrated\n";
    else cout << "maybe\n";
    return 0;
}
