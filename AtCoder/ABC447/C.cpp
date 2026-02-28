#include <bits/stdc++.h>
using namespace std;

int Solve(const string& a, const string& b) {
    int i = 0, j = 0, res = 0;
    while (i < a.length() || j < b.length())
        if (i < a.length() && j < b.length() && a[i] == b[j]) {
            ++i;
            ++j;
        } else if (i < a.length() && a[i] == 'A') {
            ++res;
            ++i;
        } else if (j < b.length() && b[j] == 'A') {
            ++res;
            ++j;
        } else return -1;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    cout << Solve(a, b) << "\n";
    return 0;
}
