#include <bits/stdc++.h>
using namespace std;

string toLowercase(string s) {
    for (auto& ch : s)
        ch = tolower(ch);
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    a = toLowercase(a);
    b = toLowercase(b);
    if (a < b)
        cout << "-1\n";
    else if (a > b)
        cout << "1\n";
    else cout << "0\n";
    return 0;
}
