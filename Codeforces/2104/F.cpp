#include <bits/stdc++.h>
using namespace std;

constexpr int Maxd = 10;

optional<int> Try1(const array<int, Maxd>& arr) {
    int dig = 1;
    while (dig < 9 && arr[dig] == 0)
        dig++;
    if (dig >= 9)
        return {};
    int res = dig;
    for (int i = 0; i < Maxd; i++) {
        int lft = i == dig ? arr[i] - 1 : arr[i];
        while (lft--)
            res = 10 * res + i;
    }
    return {res};
}

optional<int> Try2(int got, const array<int, Maxd>& arr) {
    if (arr[0] != arr[9])
        return {};
    for (int i = 0; i < arr[0]; i++)
        got = 100 * got + 99;
    return {got};
}

optional<int> Try3(const array<int, Maxd>& arr) {
    if (arr[9] == 0)
        return {};
    int res = 9;
    for (int i = 0; i < arr[0]; i++)
        res = 10 * res;
    for (int i = 0; i < arr[9] - 1; i++)
        res = 10 * res + 9;
    return {res};
}

optional<int> Get(array<int, Maxd> arr, int a, int b, bool odd) {
    if (a == 9 && b == 1) {
        if (arr[0] == 0)
            return {};
        arr[0]--;
        if (auto res1 = Try1(arr))
            return {*res1 * 100 + 9};
        if (auto res3 = Try3(arr))
            return {*res3 * 100 + 9};
        return {};
    }
    if (a == 8 && b == 0) {
        if (arr[9] == 0)
            return {};
        arr[9]--;
        if (auto res1 = Try1(arr))
            return {*res1 * 100 + 89};
        if (auto res2 = Try2(89, arr))
            return res2;
        if (auto res3 = Try3(arr))
            return {*res3 * 100 + 89};
        return {};
    }
    if (odd) {
        int num = 10 * a + 9;
        if (auto res1 = Try1(arr))
            return {*res1 * 100 + num};
        if (auto res2 = Try2(num, arr))
            return res2;
        if (auto res3 = Try3(arr))
            return {*res3 * 100 + num};
        return {};
    }
    if (auto res1 = Try1(arr))
        return {*res1 * 10 + a};
    if (a != 0)
        if (auto res2 = Try2(a, arr))
            return res2;
    if (auto res3 = Try3(arr))
        return {*res3 * 10 + a};
    return {};
}

void Solve(const array<int, Maxd>& arr, int has, vector<int>& res) {
    for (int i = 0; i < 9; i++)
        if (auto got = Get(arr, i, i + 1, false))
            res.push_back(*got);
    if (auto got = Get(arr, 8, 0, false))
        res.push_back(*got);
    if (auto got = Get(arr, 9, 1, false))
        res.push_back(*got);
    if (has)
        for (int i = 1; i <= 7; i++)
            if (auto got = Get(arr, i, i + 1, true))
                res.push_back(*got);
}

void Solve(int lvl, int has, array<int, Maxd>& cnt, vector<int>& res) {
    if (lvl >= Maxd)
        Solve(cnt, has, res);
    else for (int i = 0; i <= has; i++) {
        cnt[lvl] = i;
        Solve(lvl + 1, has - i, cnt, res);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> res;
    int cur = 9;
    while (cur < 999999999) {
        res.push_back(cur);
        cur = 10 * cur + 9;
    }
    array<int, Maxd> cnt{};
    Solve(0, 8, cnt, res);
    ranges::sort(res);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << distance(res.begin(), ranges::upper_bound(res, n)) << "\n";
    }
    return 0;
}