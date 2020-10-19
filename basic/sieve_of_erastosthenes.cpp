
#include <bits/stdc++.h>
using namespace std;

// Input: n
// Output: All the prime numbers smaller than or equal to n

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i <= sqrt(n); i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

// Naive solution: O(n*n^1/2)
void solve()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))
            cout << i << " ";
    }
}

//Optimized solution: Sieve of erastosthenes: bool arr initialized to 1's, 0's are marked next acc to the divisibility
// TC: O(n)
void solve1()
{
    int n;
    cin >> n;
    vector<bool> sieveisPrime(n + 1, 1);
    for (int i = 2; i * i <= n; i++)
    {
        if (sieveisPrime[i])
        {
            for (int j = 2 * i; j <= n; j = j + i)
                sieveisPrime[j] = 0;
        }
    }
    for (int i = 2; i <= sieveisPrime.size(); i++)
    {
        if (sieveisPrime[i])
            cout << i << " ";
    }
}

// Much optimized: Reduced repeated check: TC: O(nloglogn)
void solve2()
{
    int n;
    cin >> n;
    vector<bool> sieveisPrime(n + 1, 1);
    for (int i = 2; i * i <= n; i++)
    {
        if (sieveisPrime[i])
        {
            for (int j = i * i; j <= n; j = j + i)
                sieveisPrime[j] = 0;
        }
    }
    for (int i = 2; i <= sieveisPrime.size(); i++)
    {
        if (sieveisPrime[i])
            cout << i << " ";
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
