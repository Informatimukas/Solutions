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
        vector<int> seq(n + 1);
        vector<int> inseq(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> seq[i];
            inseq[seq[i]] = i;
        }
        for (int i = 1; i <= n; i++) {
            int lst = n;
            if (i % 2 != lst % 2)
                lst--;
            for (int j = lst - 2; j >= i; j -= 2) {
                int ind1 = inseq[j + 2], ind2 = inseq[j + 1], ind3 = inseq[j];
                if (ind1 < ind2 && ind1 < ind3) {
                    seq[ind1] -= 2;
                    seq[ind2]++;
                    seq[ind3]++;
                    inseq[seq[ind1]] = ind1;
                    inseq[seq[ind2]] = ind2;
                    inseq[seq[ind3]] = ind3;
                }
            }
        }
        for (int i = 1; i <= n; i++)
            cout << seq[i] << (i + 1 <= n ? ' ' : '\n');
    }
    return 0;
}
