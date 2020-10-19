#include <bits/stdc++.h>
using namespace std;

// Naive: Theta(sqrt(n))=Theta(x^1/2)
int squareroot(int n)
{
    int i = 1;
    while (i * i <= n)
        i++;
    return i - 1;
}

// Optimized: O(logn) Recursivew
int squareroot1(int n, int low, int high)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (mid * mid == n || ((mid * mid < n) && ((mid + 1) * (mid + 1)) > n))
        return mid;
    if (mid * mid > n)
        return squareroot1(n, low, mid - 1);
    else
    {
        return squareroot1(n, mid + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;

    int res = squareroot1(n, 1, n);
    cout << res;

    return 0;
}
