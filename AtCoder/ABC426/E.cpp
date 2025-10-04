#include <bits/stdc++.h>
using namespace std;

using ld = long double;

struct point {
    ld x, y;
    ld Len() { return sqrt(x * x + y * y); }
    point operator-(const point& oth) const {
        return {x - oth.x, y - oth.y};
    }
    point operator+(const point& oth) const {
        return {x + oth.x, y + oth.y};
    }
    ld operator*(const point& oth) const {
        return x * oth.x + y * oth.y;
    }
    ld operator^(const point& oth) const {
        return x * oth.y - y * oth.x;
    }
    point operator/(ld val) const {
        return {x / val, y / val};
    }
    point operator*(ld val) const {
        return {x * val, y * val};
    }
};

void Read(point& p) {
    cin >> p.x >> p.y;
}

ld minDist(point a, point b, point c) {
    if ((c - a) * (b - a) <= 0)
        return (c - a).Len();
    if ((c - b) * (a - b) <= 0)
        return (c - b).Len();
    return fabs((b - a) ^ (c - a)) / (a - b).Len();
}

ld Solve(point a, point b, point c, point d) {
    point A = b - a;
    point B = d - c;
    if (A.Len() > B.Len()) {
        swap(a, c);
        swap(b, d);
        swap(A, B);
    }
    ld lim = A.Len();
    point uA = A / A.Len();
    point uB = B / B.Len();
    point st = c - a;
    point en = c - a + uB * lim - uA * lim;
    return min(minDist(st, en, {0, 0}), minDist(c + uB * lim, d, b));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        array<point, 4> a;
        for (auto& p : a)
            Read(p);
        cout << fixed << setprecision(10) << Solve(a[0], a[1], a[2], a[3]) << "\n";
    }
    return 0;
}
