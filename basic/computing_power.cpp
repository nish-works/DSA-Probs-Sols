
#include <bits/stdc++.h>
using namespace std;

// Naive solution: TC: Theta(n)
void solve()
{
    int n, x, res = 1;
    cin >> n >> x;
    for (int i = 1; i <= x; i++)
        res = res * n;
    cout << res;
    // or cout << pow(n, x);
}

// Recursive
// T(n) = T(n/2) + c => c+c+.. logn times => Theta(c*logn) => Theta(logn)
// Auxiliary space: ht of the recursion tree = ht of the recursive call stack => Theta(logn)
int power_r(int n, int x)
{
    if (x == 0)
    {
        return 1;
    }
    int temp = power_r(n, x / 2);
    temp = temp * temp;
    if (x % 2 == 0)
        return temp;
    else
        return temp * n;
}

// Iterative
// int power_i(int n, int x)
// {
//     int temp = 1, res = 0;
//     while (x >= 0)
//     {
//         // temp = temp * temp;
//         if (x == 0)
//             res += 1;
//         if (x % 2 == 0)
//             res += temp * temp;
//         else
//             res += temp * n;
//         x = x / 2;
//     }
// }

// Optimized solution: TC: Theta(logn)
void solve1()
{
    int n, x;
    cin >> n >> x;
    cout << power_r(n, x);
}

int main()
{
    ios_base::sync_with_stdio(0); // fast IO
    cin.tie(0);
    cout.tie(0);
    solve1();
    return 0;
}
