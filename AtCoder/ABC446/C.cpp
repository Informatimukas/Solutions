#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, d;
        cin >> n >> d;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector<int> b(n);
        for (auto& x : b)
            cin >> x;
        queue<int> Q;
        for (int i = 0; i < n; i++) {
            while (a[i]--)
                Q.push(i);
            while (b[i]--)
                Q.pop();
            while (!Q.empty() && Q.front() <= i - d)
                Q.pop();
        }
        cout << Q.size() << "\n";
    }
    return 0;
}
