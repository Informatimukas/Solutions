#include <bits/stdc++.h>
using namespace std;

int Ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    int res;
    cin >> res;
    return res;
}

void Answer(int x) {
    cout << "! " << x << endl;
}

void Solve(int n) {
    for (int i = 1; i <= 2 * n - 2; i += 2)
        if (Ask(i, i + 1) == 1) {
            Answer(i);
            return;
        }
    if (Ask(1, 2 * n) == 1) {
        Answer(1);
        return;
    }
    if (Ask(2, 2 * n) == 1) {
        Answer(2);
        return;
    }
    Answer(2 * n - 1);
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
        Solve(n);
    }
    return 0;
}
