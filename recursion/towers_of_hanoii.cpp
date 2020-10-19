#include <bits/stdc++.h>
using namespace std;

void toh(int n, int a = 1, int b = 2, int c = 3)
{
    if (n == 0)
        return;
    toh(n - 1, a, c, b);
    cout << "Move disk-" << n << " from " << a << " to " << c << "\n";
    toh(n - 1, b, a, c);
}

int main()
{
    int n;
    cin >> n;
    toh(n);
    return 0;
}
