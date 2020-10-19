#include <bits/stdc++.h>
using namespace std;

// Tail recursive solution
int factorial(int n, int k)
{
    if (n == 0 || n == 1)
        return k;
    return factorial(n - 1, k * n);
}

int main()
{
    int n, k = 1;
    cin >> n;
    int res = factorial(n, k);
    cout << res;
    return 0;
}
