#include <bits/stdc++.h>
using namespace std;

// TC: log(n)
// Works for all cases x=2, n=-2134545657 or x=2, n=10 or ...
double myPow(double x, int n)
{
    double ans = 1;
    long absN = n;
    if (n < 0)
        absN = -1 * (long)n;
    while (absN > 0)
    {
        if ((absN & 1) == 1)
            ans *= x;
        absN >>= 1;
        x *= x;
    }
    return n < 0 ? 1 / ans : ans;
}
