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
        vector<int> seq(n + 1), inseq(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> seq[i];
            inseq[seq[i]] = i;
        }
        for (int i = 1; i <= n; i++)
            while (seq[i] >= 3 && inseq[seq[i] - 1] > i && inseq[seq[i] - 2] > i) {
                int a = i, b = inseq[seq[i] - 1], c = inseq[seq[i] - 2];
                seq[a] -= 2;
                seq[b]++;
                seq[c]++;
                inseq[seq[a]] = a;
                inseq[seq[b]] = b;
                inseq[seq[c]] = c;
            }
        for (int i = 1; i <= n; i++)
            cout << seq[i] << (i + 1 <= n? ' ' : '\n');
    }
    return 0;
}
