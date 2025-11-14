// Next steps: fix the solution. There exists an unsolvable test case.
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void Add(int ind, int n, const vector<array<int, 2>>& ch, vector<int>& resA, vector<int>& resB) {
    if (ind < n)
        resA.push_back(ind + 1);
    else if (ind < 2 * n)
        resB.push_back(ind - n + 1);
    else for (auto& x : ch[ind])
        Add(x, n, ch, resA, resB);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector A(n + 1, vector<int>());
    vector B(n + 1, vector<int>());
    ll sumA = 0, sumB = 0;
    vector ch(2 * n, array<int, 2>());
    for (int i = 0; i < ch.size(); i++)
        ch[i] = {i};
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        A[a].push_back(i);
        sumA += a;
    }
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        B[b].push_back(n + i);
        sumB += b;
    }
    vector<int> resA, resB;
    int i = n, j = n;
    while (true)
        if (A[i].empty())
            i--;
        else if (B[j].empty())
            j--;
        else if (i == j) {
            Add(A[i][0], n, ch, resA, resB);
            Add(B[j][0], n, ch, resA, resB);
            break;
        } else if (i > j)
            if (i <= sumB) {
                int nw = ch.size();
                sumA -= j;
                sumB -= j;
                ch.push_back({A[i].back(), B[j].back()});
                A[i].pop_back();
                B[j].pop_back();
                A[i - j].push_back(nw);
            } else {
                sumA -= static_cast<ll>(i) * A[i].size();
                i--;
            }
        else if (j <= sumA) {
            int nw = ch.size();
            sumA -= i;
            sumB -= i;
            ch.push_back({A[i].back(), B[j].back()});
            A[i].pop_back();
            B[j].pop_back();
            B[j - i].push_back(nw);
        } else {
            sumB -= static_cast<ll>(j) * B[j].size();
            j--;
        }
    for (auto& x : {resA, resB}) {
        cout << x.size() << "\n";
        for (int z = 0; z < x.size(); z++)
            cout << x[z] << (z + 1 < x.size() ? ' ' : '\n');
    }
    return 0;
}
