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
        int res = 0, sum = 0;
        vector<int> seq;
        for (int i = 0; i < s.length(); i++) {
            sum += s[i] - '0';
            seq.push_back(s[i] - (i == 0 ? '1' : '0'));
        }
        ranges::sort(seq);
        while (sum >= 10) {
            sum -= seq.back();
            seq.pop_back();
            res++;
        }
        cout << res << "\n";
    }
    return 0;
}
