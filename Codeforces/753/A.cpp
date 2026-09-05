#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> seq;
    int nxt = 1;
    while (nxt <= n) {
        n -= nxt;
        seq.push_back(nxt++);
    }
    seq.back() += n;
    cout << seq.size() << "\n";
    for (int i = 0; i < seq.size(); i++)
        cout << seq[i] << (i + 1 < seq.size() ? ' ' : '\n');
    return 0;
}
