#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string a;
    string b;
    cin >> a >> b;
    ranges::sort(b, greater());
    int pnt = 0;
    for (int i = 0; i < a.length(); i++)
        if (pnt < b.length() && b[pnt] > a[i])
            a[i] = b[pnt++];
    cout << a << "\n";
    return 0;
}