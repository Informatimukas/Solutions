#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int fives = 0, zeroes = 0;
    while (n--) {
        int a;
        cin >> a;
        if (a == 0)
            zeroes++;
        else fives++;
    }
    if (!zeroes) {
        cout << "-1\n";
        return 0;
    }
    for (int i = fives; i >= 0; i--)
        if (i * 5 % 9 == 0) {
            if (i == 0)
                cout << "0\n";
            else cout << string(i, '5') << string(zeroes, '0') << "\n";
            break;
        }
    return 0;
}
