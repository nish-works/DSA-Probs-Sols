
#include <bits/stdc++.h>
using namespace std;

// Naive solution TC: O(a*b-max(a,b)) since a*b is wc 7,3 eg.(7 to 21)
void solve()
{
    int a, b;
    cin >> a >> b;
    int res = max(a, b);
    while (1)
    {
        if (res % a == 0 && res % b == 0)
            break;
        res++;
    }
    cout << res;
}

// Formula: a*b = gcd(a,b) * lcm(a,b)

//TC: O(log(min(a,b)))
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

// Recursive - Optimised solution
// TC: Same as gcd + some constant operations so, O(log(min(a,b)))
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

void solve1()
{
    int a, b;
    cin >> a >> b;
    // int res = gcd(a, b);
    int res = lcm(a, b);
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0); // fast IO
    cin.tie(0);
    cout.tie(0);
    solve1();
    return 0;
}
