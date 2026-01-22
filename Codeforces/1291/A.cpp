#include <bits/stdc++.h>
using namespace std;

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
        vector<char> odd;
        for (auto& x : s)
            if ((x - '0') % 2)
                odd.push_back(x);
        if (odd.size() >= 2)
            cout << odd[0] << odd[1] << "\n";
        else cout << "-1\n";
    }
    return 0;
}
