#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> A, B;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a % 3 == 0)
            A.push_back(i);
        else B.push_back(i);
    }
    string s(n, '0');
    int z;
    if (A.size() >= B.size()) {
        z = 2;
        for (int i = n / 2; i < A.size(); i++)
            s[A[i]] = '1';
        for (auto x : B)
            s[x] = '1';
    } else {
        z = 0;
        for (int i = 0; i < n / 2; i++)
            s[B[i]] = '1';
    }
    cout << z << "\n";
    cout << s << "\n";
    return 0;
}
