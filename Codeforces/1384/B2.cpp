#include <bits/stdc++.h>
using namespace std;

bool Solve(int n, int k, int l, const vector<int>& d) {
    int lef = 
    for (int i = n; i >= 1; i--) {
        if (d[i] > l)
            return false;
        if (d[i] )
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k, l;
        cin >> n >> k >> l;
        vector<int> d(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> d[i];

    }
    return 0;
}
