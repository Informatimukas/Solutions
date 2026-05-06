#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int res = 0;
    int lst = 0;
    for (int i = 0; i < n; i++) {
        int s, d;
        cin >> s >> d;
        if (lst < s)
            lst = s;
        else {
            ++lst;
            while ((lst - s) % d)
                lst++;
        }
    }
    cout << lst << "\n";
    return 0;
}
