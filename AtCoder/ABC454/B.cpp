#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    set<int> F;
    for (int i = 0; i < n; i++) {
        int f;
        cin >> f;
        F.insert(f);
    }
    cout << (F.size() == n ? "Yes" : "No") << "\n";
    cout << (F.size() == m ? "Yes" : "No") << "\n";
    return 0;
}
