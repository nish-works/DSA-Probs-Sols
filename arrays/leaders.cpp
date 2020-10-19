#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin >> n;
    vector<int> vt(n);

    for (int i = 0; i < n; i++)
        cin >> vt[i];

    auto curr = vt.end() - 1;
    auto nxt = curr - 1;
    vector<int> leaders;
    leaders.push_back(*curr);
    while (curr != vt.begin())
    {
        if (*nxt >= *curr && *nxt >= leaders[leaders.size() - 1]) // O(1)
        {
            leaders.push_back(*nxt);
            nxt--;
            curr--;
        }
        else
        {
            nxt--;
            curr--;
        }
    }
    for (auto i = vt.end() - 1; i >= vt.begin(); i--) // or for(auto i=vt.rbegin(); i!=vt.rend(); i--)
        cout << *i << " ";
}

// O(n)

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
