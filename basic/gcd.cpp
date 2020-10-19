
#include <bits/stdc++.h>
using namespace std;

// Naive solution TC: O(min(a,b))
void solve()
{
    int a, b;
    cin >> a >> b;
    int res = min(a, b);
    while (res > 0)
    {
        if (a % res == 0 && b % res == 0)
            break;
        res--;
    }
    cout << res;
}

// Iterative - Euclidean algorithm - TC: O()
int gcd(int a, int b)
{
    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a;
}

// Recursive - Euclidean algorithm // OPTIMISED bc we are not doing repeated subtraction, we are using %
// TC: O(log(min(a,b))) since we are using mod.
int gcd1(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

void solve1()
{
    int a, b;
    cin >> a >> b;
    // int res = gcd(a, b);
    int res = gcd1(a, b);
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
