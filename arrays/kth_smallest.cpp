#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n, k;
    cin >> n;
    vector<int> vt(n);

    for (int i = 0; i < n; i++)
        cin >> vt[i];
    cin >> k;

    sort(vt.begin(), vt.end());
    cout << vt[k - 1];
}

int main()
{
    ios_base::sync_with_stdio(0); // fast IO
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }

    return 0;
}
