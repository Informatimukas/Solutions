#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<string> seq;
    string cur = "ogo";
    for (int i = 0; i < 100; i++) {
        seq.push_back(cur);
        cur += "go";
    }
    for (auto& t : seq | views::reverse) {
        int p;
        while ((p = s.find(t)) != string::npos)
            s.replace(p, t.length(), "***");
    }
    cout << s << "\n";
    return 0;
}
