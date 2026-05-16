#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x;
    cin >> x;
    int q;
    cin >> q;
    multiset<int> A, B;
    int mid = x;
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        if (b < mid) {
            A.insert(a);
            A.insert(b);
            B.insert(mid);
            mid = *A.rbegin();
            A.erase(prev(A.end()));
        } else if (mid < a) {
            B.insert(a);
            B.insert(b);
            A.insert(mid);
            mid = *B.begin();
            B.erase(B.begin());
        } else {
            A.insert(a);
            B.insert(b);
        }
        cout << mid << "\n";
    }
    return 0;
}
