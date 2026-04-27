#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

ii Count(const string& s, int& pnt) {
    ii res;
    int my = 0;
    while (pnt < s.length() && s[pnt] != ')') {
        my++;
        pnt++;
        ii got = Count(s, pnt);
        res.first += got.first;
        res.second += got.second;
    }
    pnt++;
    if (my <= 1)
        res.first++;
    else {
        res.first = 0;
        res.second += my - 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string t;
        cin >> t;
        int pnt = 0;
        ii r1 = Count(s, pnt);
        pnt = 0;
        ii r2 = Count(t, pnt);
        cout << (r1 == r2 ? "YES" : "NO") << "\n";
    }
    return 0;
}
