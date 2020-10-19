#include <bits/stdc++.h>
using namespace std;

// TC: O(log n), Aux Space: O(1)
int solve(int n)
{
    n++;
    int count = 0;
    for (int i = 2; i / 2 < n; i = i * 2)
    {
        int quotient = n / i;
        count += (quotient * i) / 2;

        int remainder = n % i;
        if (remainder > i / 2)
            count += remainder - i / 2;
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(0); // fast IO
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int res = solve(n);
    cout << res;
    return 0;
}