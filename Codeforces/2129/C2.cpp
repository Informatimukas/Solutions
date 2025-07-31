#include <bits/stdc++.h>
using namespace std;

int Ask(const vector<int>& seq) {
    cout << "? " << seq.size();
    for (auto &el: seq)
        cout << " " << el + 1;
    cout << endl;
    int res;
    cin >> res;
    return res;
}

int getInd(int L, int R) {
    int lef = L + 1, rig = R;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        vector<int> seq;
        for (int i = L; i <= mid; i++)
            seq.push_back(i);
        for (int i = L; i <= mid; i++)
            seq.push_back(i);
        if (Ask(seq) > 0)
            rig = mid - 1;
        else lef = mid + 1;
    }
    return lef > R? -1: lef;
}

int Count(const string &s) {
    int res = 0;
    for (int i = 0; i < s.length(); i++) if (s[i] == '(') {
        int st = 1;
        for (int j = i + 1; j < s.length(); j++) {
            st += s[j] == '('? 1: -1;
            if (st < 0) break;
            if (st == 0) res++;
        }
    }
    return res;
}

map<int, int> Experiment(int fir, const vector<int>& seq) {
    map<int, int> M;
    for (int i = 0; i < 1 << seq.size(); i++) {
        string s(fir, '(');
        for (int j = 0; j < seq.size(); j++) {
            char wh = (i & 1 << j)? '(': ')';
            s += string(seq[j], wh);
        }
        int got = Count(s);
        auto it = M.find(got);
        if (it != M.end()) {
            //cout << "same " << i << " " << it->second << " with " << got << endl;
            return M;
        }
        M.insert({got, i});
    }
    return M;
    //cout << "Passed" << endl;
}

constexpr int fir = 400;
vector spec = {1, 3, 9, 27, 81, 243};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<int, int> M = Experiment(400, {1, 3, 9, 27, 81, 243});
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int lef = getInd(0, min(n - 1, 499));
        if (lef == -1) {
            lef = getInd(500, n - 1);
            if (lef == -1)
                lef = 500;
        }
        if (Ask({lef - 1, lef}) > 0)
            lef--;
        string res(n, '?');
        for (int i = 0; i < n; i += spec.size()) {
            vector<int> toask;
            for (int j = 0; j < fir; j++)
                toask.push_back(lef);
            for (int j = 0; j < spec.size(); j++) {
                int ind = (i + j) % n;
                for (int k = 0; k < spec[j]; k++)
                    toask.push_back(ind);
            }
            int mask = M[Ask(toask)];
            for (int j = 0; j < spec.size(); j++) {
                int ind = (i + j) % n;
                if (mask & 1 << j)
                    res[ind] = '(';
                else res[ind] = ')';
            }
        }
        cout << "! " << res << endl;
    }
    return 0;
}
