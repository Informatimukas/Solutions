#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    string lin;
    getline(cin, lin);
    while (T--) {
        getline(cin, lin);
        bool en = lin.size() >= 5 && lin.substr(lin.length() - 5, 5) == "lala.";
        bool st = lin.size() >= 5 && lin.substr(0, 5) == "miao.";
        if (en && !st)
            cout << "Freda's\n";
        else if (st && !en)
            cout << "Rainbow's\n";
        else cout << "OMG>.< I don't know!\n";
    }
    return 0;
}
