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
        vector<char> seq;
        for (auto ch : s | views::reverse) {
            seq.push_back(ch);
            if (seq.back() == 'A') {
                if (seq.size() >= 2 && seq[seq.size() - 2] == 'B') {
                    if (seq.size() >= 3 && seq[seq.size() - 3] == 'C')
                        seq.pop_back();
                    seq.pop_back();
                }
                seq.pop_back();
            }
        }
        cout << seq.size() << "\n";
    }
    return 0;
}
