#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

ii getM(const vector<int> &a) {
    int c = -1, mc = -1;
    for (int i = 0; i + 1 < a.size(); i++) {
        int val = a[i + 1] - a[i];
        if (val >= 0)
            if (c == -1 || c == val)
                c = val;
            else return {-1, -1};
        else {
            val = -val;
            if (mc == -1 || mc == val)
                mc = val;
            else return {-1, -1};
        }
    }
    if (c == -1 || mc == -1)
        return {0, -1};
    int m = c + mc;
    if (a[0] >= m)
        return {-1, -1};
    for (int i = 0; i + 1 < a.size(); i++)
        if ((a[i] + c) % m != a[i + 1])
            return {-1, -1};
    return {m, c};
}

int main()
{
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& el : a)
            cin >> el;
        auto [m, c] = getM(a);
        cout << m;
        if (c != -1)
            cout << " " << c;
        cout << "\n";
    }
    return 0;
}
