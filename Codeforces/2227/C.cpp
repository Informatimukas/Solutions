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
        vector<int> six, two, three, oth;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a % 6 == 0)
                six.push_back(a);
            else if (a % 2 == 0)
                two.push_back(a);
            else if (a % 3 == 0)
                three.push_back(a);
            else oth.push_back(a);
        }
        vector res = six;
        res.insert(res.end(), two.begin(), two.end());
        res.insert(res.end(), oth.begin(), oth.end());
        res.insert(res.end(), three.begin(), three.end());
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
    }
    return 0;
}
