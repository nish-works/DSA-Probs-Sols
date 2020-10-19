
#include <bits/stdc++.h>
using namespace std;

// input: sorted array
// TC: O(logn) AS: O(logn)
int getLastIndex(vector<int> arr, int x, int low, int high)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;
    if (arr[mid] == x)
    {
        if (mid == arr.size() - 1 || arr[mid + 1] != x)
            return mid;
        else
            return getLastIndex(arr, x, mid + 1, high);
    }
    else if (arr[mid] > x)
        return getLastIndex(arr, x, low, mid - 1);
    else
        return getLastIndex(arr, x, mid + 1, high);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int x;
    cin >> x;
    int res = getLastIndex(v, x, 0, n - 1);
    cout << res;

    return 0;
}
