#include <bits/stdc++.h>
using namespace std;

int Insert(vector<int>& seq, int val) {
    int ind = distance(seq.begin(), ranges::lower_bound(seq, val));
    if (ind < seq.size())
        seq[ind] = val;
    else seq.push_back(val);
    return ind;
}

int getCount(const vector<int>& seq) {
    vector<int> in, de;
    for (auto& x : seq) {
        Insert(in, x);
        Insert(de, -x);
    }
    int totinc = in.size(), totdec = de.size();
    vector lens(seq.size(), array<int, 4>());
    in.clear();
    de.clear();
    for (int i = 0; i < seq.size(); i++) {
        lens[i][0] = Insert(de, -seq[i]);
        lens[i][1] = Insert(in, seq[i]);
    }
    in.clear();
    de.clear();
    int res = 0;
    for (int i = seq.size() - 1; i >= 0; i--) {
        lens[i][2] = Insert(de, -seq[i]);
        lens[i][3] = Insert(in, seq[i]);
        if (lens[i][0] + lens[i][3] + 1 == totdec &&
            lens[i][1] + lens[i][2] + 1 == totinc)
            res++;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        if (n == 1) {
            if (k == 1)
                cout << "1\n";
            else cout << "-1\n";
            continue;
        }
        if (n == k) {
            for (int i = 1; i <= n; i++)
                cout << i << (i + 1 <= n? ' ': '\n');
            continue;
        }
        if (k >= 2) {
            for (int i = 1; i <= n - k; i++)
                cout << i << " ";
            for (int i = 0; i < k; i++)
                cout << n - i << (i < k - 1? ' ': '\n');
            continue;
        }
        if (k == 1) {
            if (n < 5) {
                cout << "-1\n";
                continue;
            }
            cout << "2 5 3 1 4";
            for (int i = 6; i <= n; i++)
                cout << " " << i;
            cout << "\n";
            continue;
        }
        if (n < 8) {
            cout << "-1\n";
            continue;
        }
        cout << "3 4 8 7 2 1 5 6";
        for (int i = 9; i <= n; i++)
            cout << " " << i;
        cout << "\n";
    }
    return 0;
}
