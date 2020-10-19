#include <bits/stdc++.h>
using namespace std;

// Non Tail recursive solution
// TC: Theta(n), AS: Theta(n)
int nsum(int n)
{
    if (n == 0)
        return 0;
    else
        return n + nsum(n - 1);
}

// Tail recursive solution
// TC: Theta(n), AS: Theta(1)
int nsum_t(int n, int k)
{
    if (n == 0)
        return k;
    return nsum_t(n - 1, n + k);
}

int main()
{
    int n, k = 0;
    cin >> n;
    int res = nsum_t(n, k);
    cout << res;
    return 0;
}
