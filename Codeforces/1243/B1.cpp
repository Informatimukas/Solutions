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
        string a, b;
        cin >> a;
        cin >> b;
        vector<int> seq;
        for (int i = 0; i < n; i++)
            if (a[i] != b[i])
                seq.push_back(i);
        if (seq.empty() || seq.size() == 2 && a[seq[0]] == a[seq[1]] && b[seq[0]] == b[seq[1]])
            cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
