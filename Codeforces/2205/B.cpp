#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int res = 1;
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0) {
                res *= i;
                while (n % i == 0)
                    n /= i;
            }
        if (n > 1)
            res *= n;
        cout << res << "\n";
    }
    return 0;
}