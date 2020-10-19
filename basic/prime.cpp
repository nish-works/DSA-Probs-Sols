
#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
bool solve(int n)
{
    int c = 1;
    cin >> n;

    if (n == 1)
        return false;

    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

// TC: O(n^1/2)
bool solve1(int n)
{
    int c = 1;
    cin >> n;

    if (n == 1)
        return false;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

// TC: 3 times faster than solve1. Most suitable and efficient for larger numbers
bool solve2(int n)
{
    if (n == 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i <= sqrt(n); i = i + 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); // fast IO
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    bool res = solve2(n);
    cout << res;
    return 0;
}
