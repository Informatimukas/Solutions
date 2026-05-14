#include <bits/stdc++.h>
using namespace std;

constexpr int Maxm = 1000000;
constexpr int Maxd = 10;

int digSum(int x) {
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<array<int, Maxd>> needed(Maxm);
    vector<string> str(Maxm);
    for (int i = 0; i < Maxm; i++)
        if (i < Maxd) {
            needed[i][i]++;
            str[i] = string(1, '0' + i);
        } else {
            int dsum = digSum(i);
            needed[i] = needed[dsum];
            str[i] = to_string(i) + str[dsum];
            int num = i;
            while (num) {
                needed[i][num % 10]++;
                num /= 10;
            }
        }
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        array<int, Maxd> cnt{};
        for (auto ch : s)
            cnt[ch - '0']++;
        for (int i = 0; i < Maxm; i++) {
            int sum = 0, lft = 0;
            bool ok = true;
            for (int j = 0; j < Maxd; j++) {
                if (cnt[j] < needed[i][j]) {
                    ok = false;
                    break;
                }
                lft += cnt[j] - needed[i][j];
                sum += j * (cnt[j] - needed[i][j]);
            }
            if (ok && (lft == 0 && sum == 0 || sum > 0 && sum == i)) {
                for (int j = Maxd - 1; j >= 0; j--)
                    for (int k = cnt[j] - needed[i][j]; k > 0; k--)
                        cout << j;
                cout << str[i] << "\n";
                break;
            }
        }
    }
    return 0;
}
