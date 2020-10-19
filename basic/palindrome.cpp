
#include <bits/stdc++.h>
using namespace std;

void solve() // Theta(d) // d=no. of digits
{
    int n, flag = 0, rev, rem, temp;
    cin >> n;
    temp = n;

    if (n == 0)
        flag = 1;

    while (temp != 0)
    {
        rem = temp % 10;
        temp = temp / 10;
        rev = rev * 10 + rem;
    }
    if (n == rev)
        flag = 1;

    flag == 1 ? cout << "YES" : cout << "NO";
}

int main()
{
    ios_base::sync_with_stdio(0); // fast IO
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
