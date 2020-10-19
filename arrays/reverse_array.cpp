#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin >> n;
    vector<int> vt(n, 0);

    for (int i = 0; i < n; i++)
        cin >> vt[n - i - 1];

    for (int i = 0; i < n; i++)
        cout << vt[i] << " ";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }

    return 0;
}
