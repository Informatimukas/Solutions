#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    vector<int> V[2];
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        V[a % 2].push_back(i);
    }
    cout << (V[0].size() == 1? V[0][0]: V[1][0]) << "\n";
    return 0;
}
