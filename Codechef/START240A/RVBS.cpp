#include <bits/stdc++.h>
using namespace std;

vector<int> getOnes(const string& s) {
    vector<int> res;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '1')
            res.push_back(i);
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
        string a, b;
        cin >> n >> a >> b;
        auto A = getOnes(a);
        auto B = getOnes(b);
        if (A.size() != B.size()) {
            cout << "-1\n";
            continue;
        }
        int res = 0;
        for (int i = 0; i < A.size(); i++)
            res += A[i] != B[i];
        cout << res << "\n";
    }
    return 0;
}
