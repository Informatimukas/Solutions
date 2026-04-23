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
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        for (int i = 0; i < n; i++) {
            int smaller = 0, bigger = 0;
            for (int j = i + 1; j < n; j++)
                if (a[i] < a[j])
                    smaller++;
                else if (a[i] > a[j])
                    bigger++;
            cout << max(smaller, bigger) << (i + 1 < n ? ' ' : '\n');
        }
    }
    return 0;
}