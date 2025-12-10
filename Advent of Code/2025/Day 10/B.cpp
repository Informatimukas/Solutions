#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 1000000000;

int getBest(int lvl, const vector<int>& a, vector<int>& seq) {
    if (lvl + 1 == a.size()) {
        int lft = -1;
        for (int i = 0; i < seq.size(); i++)
            if (a[lvl] & 1 << i) {
                if (lft == -1)
                    lft = seq[i];
                else if (lft != seq[i])
                    return Inf;
            } else if (seq[i] > 0)
                return Inf;
        return lft;
    }
    int res = Inf;
    for (int z = 0; ; z++) {
        bool bad = false;
        for (int i = 0; i < seq.size(); i++)
            if (a[lvl] & 1 << i) {
                if (seq[i] < z) {
                    bad = true;
                    break;
                }
            }
        if (bad) break;
        for (int i = 0; i < seq.size(); i++)
            if (a[lvl] & 1 << i)
                seq[i] -= z;
        res = min(res, getBest(lvl + 1, a, seq) + z);
        for (int i = 0; i < seq.size(); i++)
            if (a[lvl] & 1 << i)
                seq[i] += z;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    string s;
    int res = 0;
    while (getline(cin, s)) {
        cout << "solving " << s << endl;
        stringstream ss(s);
        vector<int> seq;
        vector<int> a;
        while (ss >> s)
            if (s[0] == '{') {
                for (auto& ch : s)
                    if (!isdigit(ch))
                        ch = ' ';
                stringstream ss2(s);
                int num;
                while (ss2 >> num)
                    seq.push_back(num);
            } else if (s[0] == '(') {
                for (auto& ch : s)
                    if (!isdigit(ch))
                        ch = ' ';
                stringstream ss2(s);
                int num, cur = 0;
                while (ss2 >> num)
                    cur |= 1 << num;
                a.push_back(cur);
            }
        ranges::sort(a, [&](int a, int b) {
            vector<int> seqa, seqb;
            for (int i = 0; i < seq.size(); i++) {
                if (a & 1 << i)
                    seqa.push_back(seq[i]);
                if (b & 1 << i)
                    seqb.push_back(seq[i]);
            }
            ranges::sort(seqa);
            ranges::sort(seqb);
            return seq < seqb;
        });
        int got = getBest(0, a, seq);
        cout << got << endl;
        res += got;
    }
    cout << res << endl;
    return 0;
}
