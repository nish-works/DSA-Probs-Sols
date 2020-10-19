
#include <bits/stdc++.h>
using namespace std;

bool solve()
{
    int n, x;
    cin >> n;
    vector<int> vt(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        vt[i] = x * x;
    }

    if (vt.size() < 3)
        return false;

    int flag = 0;
    sort(vt.begin(), vt.end());
    for (int i = n - 1; i >= 2; i--)
    {
        int j = 0;
        int k = i - 1;
        while (j < k)
        {
            if (vt[j] + vt[k] > vt[i])
                k--;
            else if (vt[j] + vt[k] < vt[i])
                j++;
            else
                return true;
        }
    }
    return false;
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
        bool res = solve();
        if (res)
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }

    return 0;
}
