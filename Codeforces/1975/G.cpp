#include <bits/stdc++.h>
using namespace std;

bool Match(char a, char b) {
    return a == '-' || b == '-' || a == b;
}

vector<int> prefix_function(string_view s) {
    int n = (int) s.length();
    vector<int> pi (n);
    for (int i=1; i<n; ++i) {
        int j = pi[i-1];
        while (j > 0 && !Match(s[i], s[j]))
            j = pi[j-1];
        if (Match(s[i], s[j]))  ++j;
        pi[i] = j;
    }
    return pi;
}

bool easySolve(string_view a, string_view b) {
    vector<string_view> seq;
    int lst = 0;
    for (int i = 1; i < b.length(); i++)
        if (b[i] == '*') {
            if (i > lst + 1)
                seq.push_back(b.substr(lst + 1, i - lst - 1));
            lst = i;
        }
    int done = 0;
    if (done >= seq.size())
        return true;
    auto pi = prefix_function(seq[0]);
    int cur = 0;
    for (auto ch : a) {
        while (cur > 0 && !Match(ch, seq[done][cur]))
            cur = pi[cur - 1];
        if (Match(ch, seq[done][cur]))
            cur++;
        if (cur >= seq[done].size()) {
            if (++done >= seq.size())
                return true;
            pi = prefix_function(seq[done]);
            cur = 0;
        }
    }
    return false;
}

bool Solve(string_view a, string_view b) {
    while (!a.empty() && !b.empty()) {
        if (a[0] != '*' && b[0] != '*') {
            if (Match(a[0], b[0])) {
                a.remove_prefix(1);
                b.remove_prefix(1);
                continue;
            }
            return false;
        }
        if (a[a.length() - 1] != '*' && b[b.length() - 1] != '*') {
            if (Match(a[a.length() - 1], b[b.length() - 1])) {
                a.remove_suffix(1);
                b.remove_suffix(1);
                continue;
            }
            return false;
        }
        break;
    }
    bool hasA = a.find('*') != string_view::npos;
    bool hasB = b.find('*') != string_view::npos;
    if (hasA && hasB)
        return true;
    if (hasA)
        return easySolve(b, a);
    if (hasB)
        return easySolve(a, b);
    return a.empty() && b.empty();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    cout << (Solve(a, b) ? "Yes" : "No") << "\n";
    return 0;
}
