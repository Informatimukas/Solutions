#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    set<int> S;
    while (n--) {
        int a;
        cin >> a;
        if (a > 0)
            S.insert(a);
    }
    cout << S.size() << "\n";
    return 0;
}
