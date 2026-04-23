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
        int pnt = 0;
        while (a[pnt] != n)
            pnt++;
        swap(a[0], a[pnt]);
        for (int i = 0; i < n; i++)
            cout << a[i] << (i + 1 < n ? ' ' : '\n');
    }
    return 0;
}
