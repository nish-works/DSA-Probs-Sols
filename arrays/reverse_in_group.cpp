#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n, d, c = 0, x;
    cin >> n >> d;
    stack<int> st;
    vector<int> vt(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vt[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (st.size() < d)
        {
            st.push(vt[i]);
        }
        else
        {
            while (!st.empty())
            {
                cout << st.top() << " ";
                st.pop();
            }
            st.push(vt[i]);
        }
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
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
