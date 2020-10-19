#include <bits/stdc++.h>
using namespace std;

void solve1()
{
    int n;
    cin >> n;
    if (n % 2 == 0)
        cout << "YES";
    else
        cout << "NO";
}

// TC: Theta(no. of bits)
void solve2()
{
    int n, flag = 0;
    cin >> n;
    while (n != 1)
    {
        if (n % 2 != 1)
            n = n / 2;
        else
        {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

// Since 2^x values will have only single set bit, so we count and check the set bits count is 1 or not.
// TC: Theta(set bits count)
void brian_sol()
{
    int n;
    cin >> n;
    //1.  if (n & (n - 1))
    //     cout << "NO";
    // else
    //     cout << "YES";
    // or
    // 2.
    int set_count = 0;
    while (n > 0)
    {
        n = (n & (n - 1));
        set_count++;
    }
    if (set_count == 1)
        cout << "YES";
    else
        cout << "NO";
    // or
    ((n > 0) && (n & (n - 1)) == 0) ? cout << "YES" : cout << "NO";
}

bool one_line_sol(int n)
{
    return ((n > 0) && (n & (n - 1)) == 0);
}

int main()
{
    ios_base::sync_with_stdio(0); // fast IO
    cin.tie(0);
    cout.tie(0);
    brian_sol();
    return 0;
}
