#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;

int main()
{
    cin >> n;
    if (n == 1)
        cout << 3 << "\n";
    else if (n == 2)
        cout << 5 << "\n";
    else cout << (n - 3) / 3 * 4 + 7 + n % 3 << "\n";
	return 0;
}
