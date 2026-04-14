#include <bits/stdc++.h>
using namespace std;

constexpr int Maxm = 1000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector prime(Maxm, true);
    vector<long long> primes;
    for (int i = 2; i < Maxm; i++)
        if (prime[i]) {
            primes.push_back(i);
            for (int j = i + i; j < Maxm; j += i)
                prime[j] = false;
        }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cout << primes[i] * primes[i + 1] << (i + 1 < n ? ' ' : '\n');
    }
    return 0;
}
