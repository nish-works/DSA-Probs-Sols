
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n == 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

// Naive solution: TC: O(n^3/2logn)
void solve()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))
        {
            while (n % i == 0)
            {
                cout << i << " ";
                n = n / i;
            }
        }
    }
}

// Optimised solution: TC: O()
void solve1()
{
    int n;
    cin >> n;
    if (n <= 1)
        return;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n = n / i;
        }
    }
    if (n > 1)
        cout << n;
}

// Effective solution: TC: O(n^1/2)
void solve2()
{
    int n;
    cin >> n;
    if (n <= 1)
        return;
    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n = n / 2;
    }
    while (n % 3 == 0)
    {
        cout << 3 << " ";
        n = n / 3;
    }
    for (int i = 5; i <= sqrt(n); i += 6)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n = n / i;
        }
        while (n % (i + 2) == 0)
        {
            cout << i + 2 << " ";
            n = n / (i + 2);
        }
    }
    if (n > 3)
        cout << n;
}

int main()
{
    ios_base::sync_with_stdio(0); // fast IO
    cin.tie(0);
    cout.tie(0);
    solve2();
    return 0;
}
