// Find the missing number from 1 to n+1 in the given array

#include <bits/stdc++.h>
using namespace std;

// Efficient solution
// TC: O(n+1)
int solve(vector<int> &arr, int n)
{
    int res1 = 0;
    for (int i = 1; i <= n + 1; i++)
        res1 = res1 ^ i;
    int res2 = 0;
    for (int i = 0; i < n; i++)
        res2 = res2 ^ arr[i];
    return res1 ^ res2;
}

int main()
{
    ios_base::sync_with_stdio(0); // fast IO
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int res = solve(arr, n);
    cout << res;
    return 0;
}
