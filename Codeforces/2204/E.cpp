#include <bits/stdc++.h>
using namespace std;

constexpr int Maxd = 10;

bool Check(int sum, array<int, Maxd> cnt) {
    if (sum == 0)
        return false;
    while (true) {
        bool cont = sum >= Maxd;
        int nxt = 0;
        while (sum) {
            int dig = sum % 10;
            nxt += dig;
            if (--cnt[dig] < 0)
                return false;
            sum /= 10;
        }
        if (!cont)
            break;
        sum = nxt;
    }
    return ranges::all_of(cnt, [](int x) { return x == 0; });
}

void Print(int sum) {
    while (true) {
        cout << sum;
        bool cont = sum >= Maxd;
        int nxt = 0;
        while (sum) {
            nxt += sum % 10;
            sum /= 10;
        }
        if (!cont)
            break;
        sum = nxt;
    }
}

bool Solve(int d, int lft, array<int, Maxd>& cnt, array<int, Maxd>& my, int sum) {
    if (d >= Maxd) {
        if (Check(sum, my)) {
            for (int i = Maxd - 1; i >= 0; i--)
                for (int j = 0; j < cnt[i] - my[i]; j++)
                    cout << i;
            Print(sum);
            cout << "\n";
            return true;
        }
        return false;
    }
    for (my[d] = 0; my[d] <= lft && my[d] <= cnt[d]; my[d]++)
        if (Solve(d + 1, lft - my[d], cnt, my, sum + (cnt[d] - my[d]) * d))
            return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        if (s.length() == 1) {
            cout << s << "\n";
            continue;
        }
        int lft;
        if (s.length() > 10000)
            lft = 11;
        else if (s.length() > 1000)
            lft = 10;
        else if (s.length() > 100)
            lft = 8;
        else if (s.length() > 10)
            lft = 6;
        else lft = 5;
        array<int, Maxd> cnt{};
        for (auto& ch : s)
            cnt[ch - '0']++;
        array<int, Maxd> my{};
        Solve(0, 10, cnt, my, 0);
    }
    return 0;
}
