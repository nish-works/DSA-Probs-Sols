#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, trapped_water = 0;
    cin >> n;
    vector<int> vt(n);

    for (int i = 0; i < n; i++)
        cin >> vt[i];

    vector<int> max_so_far_from_begin, max_so_far_from_end(n, 0);
    max_so_far_from_begin.push_back(vt[0]);

    for (int i = 1; i < n; i++)
    {
        if (vt[i] > max_so_far_from_begin[i - 1])
            max_so_far_from_begin.push_back(vt[i]);
        else
            max_so_far_from_begin.push_back(max_so_far_from_begin[i - 1]);
    }

    max_so_far_from_end[n - 1] = vt[n - 1];
    int max = max_so_far_from_end[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (vt[i] >= max)
        {
            max_so_far_from_end[i] = vt[i];
            max = max_so_far_from_end[i];
        }
        else
        {
            max_so_far_from_end[i] = max_so_far_from_end[i + 1];
        }
    }

    // for (auto i : max_so_far_from_begin)
    //     cout << i << " ";
    // cout << endl;
    // for (auto i : max_so_far_from_end)
    //     cout << i << " ";

    for (int i = 0; i < n; i++)
        trapped_water += min(max_so_far_from_begin[i], max_so_far_from_end[i]) - vt[i];
    cout << trapped_water;
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