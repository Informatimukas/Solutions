#include <bits/stdc++.h>
using namespace std;

bool Match(char a, char b) {
    return a == '-' || b == '-' || a == b;
}

char getCharacter(string_view a, string_view b, int index) {
    if (index < a.length())
        return a[index];
    return b[index - a.length()];
}

bool realCheck(string_view a, string_view b) {
    for (int i = 0; i < a.length(); i++)
        if (!Match(a[i], b[i]))
            return false;
    return true;
}

bool canMatch(string_view a, string_view& b) {
    vector<int> Z(a.length());
    int l = -1, r = -1;
    for (int i = 1; i < a.length() + b.length(); i++) {
        if (i >= Z.size())
            Z.push_back(0);
        if (i <= r)
            Z[i] = min(r - i, Z[i - l]);
        while (i + Z[i] < a.length() + b.length() && Z[i] < a.length() &&
            Match(getCharacter(a, b, Z[i]), getCharacter(a, b, i + Z[i])))
            Z[i]++;
        if (i >= a.length() && Z[i] >= a.length() &&
            realCheck(a, b.substr(i - a.length(), a.length()))) {
            b.remove_prefix(i);
            return true;
        }
        if (i + Z[i] - 1 > r) {
            l = i;
            r = i + Z[i] - 1;
        }
    }
    return false;
}

bool easySolve(string_view a, string_view b) {
    if (b[0] != '*' || b[b.length() - 1] != '*')
        return false;
    vector<string_view> seq;
    int lst = 0;
    for (int i = 1; i < b.length(); i++)
        if (b[i] == '*') {
            if (i > lst + 1)
                seq.push_back(b.substr(lst + 1, i - lst - 1));
            lst = i;
        }
    for (auto x : seq)
        if (!canMatch(x, a))
            return false;
    return true;
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
