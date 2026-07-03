#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    if (a.length() != b.length()) {
        cout << "NO\n";
        return 0;
    }
    vector<int> seq;
    for (int i = 0; i < a.length(); i++)
        if (a[i] != b[i])
            seq.push_back(i);
    if (seq.size() == 2 && a[seq[0]] == b[seq[1]] && a[seq[1]] == b[seq[0]])
        cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
