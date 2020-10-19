

#include <bits/stdc++.h>
using namespace std;

// Iterative: TC: O(n) SC: O(1)
// But this is not recommended bc factorial of 20 is some 19 digits and storing
// it causes overflow problems, wrong answers.
void solve()
{
    unsigned long long n, fact = 1, c = 0;
    cin >> n;
    if (n == 0)
        fact = 1;
    for (int i = 1; i <= n; i++)
        fact = fact * i;
    cout << fact;
    unsigned long long temp = fact;
    while (temp % 10 == 0)
    {
        c++;
        temp = temp / 10;
    }
    cout << c;
}

// T.C: Theta(logn) SC: Theta(1)
void solve2()
{
    int n, c = 0;
    cin >> n;
    for (int i = 5; i <= n; i *= 5)
    {
        c = c + n / i;
    }
    cout << c;
}

int main()
{
    ios_base::sync_with_stdio(0); // fast IO
    cin.tie(0);
    cout.tie(0);
    solve2();
    return 0;
}
