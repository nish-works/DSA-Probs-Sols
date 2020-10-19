
#include <bits/stdc++.h>
using namespace std;

// Efficient solution: TC: Theta(2^n * n)
void solve(string s)
{
    int sLength = s.length();
    int powerSetSize = pow(2, sLength);
    for (int counter = 0; counter < powerSetSize; counter++)
    {
        for (int j = 0; j < sLength; j++)
        {
            if ((counter & (1 << j)) != 0)
                cout << s[j];
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0); // fast IO
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    vector<string> v;
    solve(s);

    return 0;
}
