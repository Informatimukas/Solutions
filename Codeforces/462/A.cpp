#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> B(n);
    for (auto& x : B)
        cin >> x;
    for (int i = 0; i < B.size(); i++)
        for (int j = 0; j < B[i].length(); j++) {
            int cnt = 0;
            cnt += i && B[i - 1][j] == 'o';
            cnt += i + 1 < B.size() && B[i + 1][j] == 'o';
            cnt += j && B[i][j - 1] == 'o';
            cnt += j + 1 < B[i].length() && B[i][j + 1] == 'o';
            if (cnt % 2) {
                cout << "NO\n";
                return 0;
            }
        }
    cout << "YES\n";
    return 0;
}
