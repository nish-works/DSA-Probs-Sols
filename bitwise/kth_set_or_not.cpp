

#include <bits/stdc++.h>
using namespace std;

// Left shift solution: ignore left
void solve1()
{
    int n, k;
    cin >> n >> k;
    if ((1 << (k - 1)) & n)
        cout << "YES";
    else
        cout << "NO";
}

// Right shift solution: ignore right
// We are trying to get kth bit to the last place
void solve2()
{
    int n, k;
    cin >> n >> k;
    if ((n >> (k - 1)) & 1)
        cout << "YES";
    else
        cout << "NO";
}

int main()
{
    ios_base::sync_with_stdio(0); // fast IO
    cin.tie(0);
    cout.tie(0);
    solve2();
    return 0;
}
