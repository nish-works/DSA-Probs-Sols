#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void solve()
{
    ll n, d, x;
    cin >> n >> d;
    vector<int> vt(n);
    vector<int> sub_vt(d);

    // Right rotation
    for (int i = 0; i < n; i++)
        cin >> vt[(n - d + i) % n];

    // Left rotation
    for (int i = 0; i < n; i++)
        cin >> vt[(i + d) % n];

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
