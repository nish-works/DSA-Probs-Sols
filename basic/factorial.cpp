
#include <bits/stdc++.h>
using namespace std;

// Iterative TC: Theta(n), SC: O(1)
void solve()
{
    int n, fact = 1;
    cin >> n;
    if (n == 0)
        fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    cout << fact;
}

//Recursive TC: Theta(n) SC: Theta(n)
int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main()
{
    ios_base::sync_with_stdio(0); // fast IO
    cin.tie(0);
    cout.tie(0);
    // solve();
    int n;
    cin >> n;
    int res = factorial(n);
    cout << res;
    return 0;
}
