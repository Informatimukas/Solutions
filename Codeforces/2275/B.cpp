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
        string s;
        cin >> s;
        set<int> S;
        for (int i = 1; i <= n; i++)
            S.insert(i);
        stack<int> st;
        for (int i = 1; i <= n; i++)
            if (s[i - 1] == '1')
                st.push(i);
            else if (s[i - 1] == '2' && !st.empty()) {
                S.erase(st.top());
                st.pop();
            } else S.erase(i);
        vector res(S.begin(), S.end());
        cout << res.size() << "\n";
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
    }
    return 0;
}
