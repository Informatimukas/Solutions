#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> p(n + 1), inp(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            inp[p[i]] = i;
        }
        int cand = 0, res = 0;
        for (int i = 1; i <= n; i++) {
            if (inp[i] < i)
                cand--;
            cand++;
            res = max(res, cand);
        }
        cout << res << "\n";
    }
    return 0;
}
