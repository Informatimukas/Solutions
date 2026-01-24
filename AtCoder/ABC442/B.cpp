#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    bool playing = false;
    int vol = 0;
    while (T--) {
        int a;
        cin >> a;
        if (a == 1)
            ++vol;
        else if (a == 2)
            vol = max(vol - 1, 0);
        else playing = !playing;
        if (playing && vol >= 3)
            cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
