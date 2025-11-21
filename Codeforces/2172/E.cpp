#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        vector<string> seq;
        do seq.push_back(s);
        while (ranges::next_permutation(s).found);
        int j, k;
        cin >> j >> k;
        string a = seq[j - 1];
        string b = seq[k - 1];
        int sam = 0;
        for (int z = 0; z < a.length(); z++)
            sam += a[z] == b[z];
        cout << sam << "A" << s.length() - sam << "B\n";
    }
    return 0;
}
