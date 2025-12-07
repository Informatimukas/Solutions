#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    while (true) {
        int p = s.find("WUB");
        if (p != string::npos)
            s[p] = s[p + 1] = s[p + 2] = ' ';
        else break;
    }
    stringstream ss(s);
    bool pr = false;
    while (ss >> s) {
        if (pr)
            cout << " ";
        else pr = true;
        cout << s;
    }
    cout << "\n";
    return 0;
}