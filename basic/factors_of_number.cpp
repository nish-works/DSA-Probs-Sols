
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, c = 1;
    cin >> n;
    vector<int> factors;
    int i = 1;
    while (i <= n)
    {
        if (n % i == 0)
        {
            factors.push_back(i);
        }
        i++;
    }
    for (auto i : factors)
        cout << i << " ";
}

int main()
{
    ios_base::sync_with_stdio(0); // fast IO
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
