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
        string s;
        cin >> n >> s;
        string srt = s;
        ranges::sort(srt);
        vector<int> seq;
        for (int i = 0; i < n; i++)
            if (s[i] != srt[i])
                seq.push_back(i);
        if (seq.empty())
            cout << "Bob\n";
        else {
            cout << "Alice\n";
            cout << seq.size() << "\n";
            for (int i = 0; i < seq.size(); i++)
                cout << seq[i] + 1 << (i + 1 < seq.size() ? ' ' : '\n');
        }
    }
    return 0;
}
