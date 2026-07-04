#include <bits/stdc++.h>
using namespace std;

template<typename Compare>
int Solve(const vector<int>& a, int m) {
    priority_queue<int, vector<int>, Compare> Q;
    for (auto x : a)
        Q.push(x);
    int res = 0;
    while (m > 0 && !Q.empty()) {
        int val = Q.top();
        Q.pop();
        res += val;
        m--;
        if (--val > 0)
            Q.push(val);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> m >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    cout << Solve<less<int>>(a, m) << " " << Solve<greater<int>>(a, m) << "\n";
    return 0;
}
