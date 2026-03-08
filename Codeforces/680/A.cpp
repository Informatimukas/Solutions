#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    array<int, 5> arr;
    int sum = 0;
    for (auto& x : arr) {
        cin >> x;
        sum += x;
    }
    int res = sum;
    for (int i = 0; i < arr.size(); i++)
        for (int j = i + 1; j < arr.size(); j++)
            if (arr[i] == arr[j]) {
                res = min(res, sum - 2 * arr[i]);
                for (int k = j + 1; k < arr.size(); k++)
                    if (arr[j] == arr[k])
                        res = min(res, sum - 3 * arr[i]);
            }
    cout << res << "\n";
    return 0;
}
