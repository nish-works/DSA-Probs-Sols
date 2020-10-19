

#include <bits/stdc++.h>
using namespace std;

// Naive solution: TC: Theta(n) Auxiliary space: theta(1)
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }
}

// Efficient solution: It prints all divisors but not in order.
// TC: Theta(n^1/2)
void solve1()
{
    int n;
    cin >> n;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
            if (n / i != i)
                cout << n / i << " ";
        }
    }
}

// Efficient solution: It prints all divisors in order also
// TC: Theta(n^1/2), Auxiliary space: Theta(1)
void solve2()
{
    int n, i;
    cin >> n;
    for (i = 1; i * i < n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }
    for (; i >= 1; i--) // or for(i=sqrt(n); i>=1; i--)
    {
        if (n % i == 0)
        {
            cout << n / i << " ";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); // fast IO
    cin.tie(0);
    cout.tie(0);
    solve2();
    return 0;
}
