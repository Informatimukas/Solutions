#include <bits/stdc++.h>
using namespace std;

constexpr int Maxt = 3;

int getType(const string& s) {
    vector<char> seq;
    for (auto& ch : s | views::reverse)
        if (isdigit(ch))
            seq.push_back(ch);
    bool eq = false;
    for (int i = 0; i + 1 < seq.size(); i++) {
        if (seq[i] > seq[i + 1])
            return 2;
        if (seq[i] == seq[i + 1])
            eq = true;
    }
    if (!eq)
        return 1;
    if (seq[0] == seq.back())
        return 0;
    return 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    array<map<int, vector<string>>, Maxt> M{};
    for (int i = 0; i < n; i++) {
        int s;
        string name;
        cin >> s >> name;
        array<int, Maxt> cnt{};
        for (int j = 0; j < s; j++) {
            string number;
            cin >> number;
            cnt[getType(number)]++;
        }
        for (int j = 0; j < Maxt; j++)
            M[j][cnt[j]].push_back(name);
    }
    const vector<string> outp = {"call a taxi", "order a pizza",
        "go to a cafe with a wonderful girl"};
    for (int i = 0; i < Maxt; i++) {
        cout << "If you want to " << outp[i] << ", you should call: ";
        auto& V = M[i].rbegin()->second;
        for (int j = 0; j < V.size(); j++)
            cout << V[j] << (j + 1 < V.size() ? ", " : ".\n");
    }
    return 0;
}
