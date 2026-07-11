#include <bits/stdc++.h>
using namespace std;

int Solve(const string& s) {
    vector<int> sum(s.length());
    int res = 1000000000, best = 1;
    for (int i = 0; i < s.length(); i++) {
        sum[i] = s[i] == 'T';
        if (i > 0)
            sum[i] += sum[i - 1];
        int cand = 2 * sum[i] - i;
        best = max(best, cand);
        res = min(res, cand - best);
    }
    res += sum.size() - sum.back();
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
        cin >> n;
        string s;
        cin >> s;
        vector<int> seq;
        for (int i = 0; i < n; i++)
            if (s[i] == 'N')
                seq.push_back(i);
        int res = 0;
        for (int i = 0; i <= seq.size(); i++)
            for (int j = i; j <= seq.size(); j++) {
                for (int k = 0; k < i; k++)
                    s[seq[k]] = 'F';
                for (int k = i; k < j; k++)
                    s[seq[k]] = 'T';
                for (int k = j; k < seq.size(); k++)
                    s[seq[k]] = 'F';
                res = max(res, Solve(s));
            }
        cout << res << "\n";
    }
    return 0;
}
