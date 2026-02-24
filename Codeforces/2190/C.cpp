#include <bits/stdc++.h>
using namespace std;

int Ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    int res;
    cin >> res;
    return res;
}

vector<int> Solve(int n) {
    deque<int> A, B;
    B.push_back(n);
    for (int i = n - 1; i > 0; i--) {
        if (!A.empty() && Ask(i, A.back())) {
            vector<int> res;
            for (int j = 1; j < i; j++)
                res.push_back(j);
            int pnt = 0;
            while (pnt < A.size() && !Ask(i, A[pnt]))
                ++pnt;
            swap(A[pnt], i);
            res.push_back(i);
            for (auto el : A)
                res.push_back(el);
            for (auto el : B)
                res.push_back(el);
            return res;
        }
        while (!B.empty() && Ask(B.front(), i)) {
            A.push_back(B.front());
            B.pop_front();
        }
        if (A.empty())
            B.push_front(i);
        else A.push_back(i);
    }
    return {-1};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        auto res = Solve(n);
        cout << "!";
        for (auto el : res)
            cout << " " << el;
        cout << endl;
    }
    return 0;
}
