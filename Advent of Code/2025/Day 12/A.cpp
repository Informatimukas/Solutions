#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    string s;
    int res = 0;
    while (getline(cin, s)) {
        stringstream ss(s);
        ss >> s;
        for (int i = 0; i < s.length(); i++)
            if (!isdigit(s[i]))
                s[i] = ' ';
        stringstream ss2(s);
        int h, w;
        ss2 >> h >> w;
        int has = (h / 3) * (w / 3);
        int num;
        while (ss >> num)
            has -= num;
        res += has >= 0;
    }
    cout << "res = " << res << endl;
    return 0;
}