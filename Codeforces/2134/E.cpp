#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

void Swap(int x, vector<int>& seq) {
    swap(seq[x], seq[x + 1]);
    cout << "swap " << x + 1 << endl;
}

int Throw(int x) {
    cout << "throw " << x + 1 << endl;
    int res;
    cin >> res;
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
        vector<int> seq(n);
        iota(seq.begin(), seq.end(), 0);
        vector<int> res(n);
        int a = 0, b = 0;
        for (int i = n - 1; i > 0; i--)
            if (a == b) {
                res[seq[i - 1]] = Throw(i - 1) == a + 2? 1: 2;
                Swap(i - 1, seq);
                a++;
            } else if (Throw(i) == a + 1) {
                res[seq[i]] = 1;
                a++; b++;
            } else {
                res[seq[i]] = 2;
                b++;
            }
        if (a == b) {
            Swap(0, seq);
            res[seq[1]] = Throw(1) == a + 1? 1: 2;
        } else res[seq[0]] = Throw(0) == a + 1? 1: 2;
        cout << "!";
        for (auto& x : res)
            cout << " " << x;
        cout << endl;
    }
    return 0;
}
