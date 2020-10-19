#include <bits/stdc++.h>
using namespace std;

// Naive solution
// TC: O(n^2)
void solve1(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }
        if (count % 2 != 0)
        {
            cout << arr[i];
            return;
        }
    }
}

// TC: O(n), Auxiliary space: O(1)
int solve2(vector<int> &arr, int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
        res = res ^ arr[i];
    return res;
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
    int res = solve2(arr, n);
    cout << res;
    return 0;
}
