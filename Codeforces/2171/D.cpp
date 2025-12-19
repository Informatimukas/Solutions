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
        deque<int> D;
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            if (D.empty() || D.back() > a)
                D.push_back(a);
            else while (D.size() > 1 && D.front() < a)
                D.pop_front();
        }
        cout << (D.size() == 1 ? "Yes" : "No") << "\n";
    }
    return 0;
}
