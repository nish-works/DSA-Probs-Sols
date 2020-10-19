#include <bits/stdc++.h>
using namespace std;

// Naive O(n)
int peak(vector<int> arr, int n)
{
    if (n == 1)
        return arr[0];
    if (arr[0] >= arr[1])
        return arr[0];
    if (arr[n - 1] >= arr[n - 2])
        return arr[n - 1];

    for (int i = 1; i < arr.size() - 1; i++)
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
            return arr[i];

    return -1;
}

// TC: O(log n) AS: O(1)
int peak1(vector<int> arr, int n)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid]))
            // if ((mid == 0 && (arr[mid + 1] <= arr[mid])) || (mid == n - 1 && (arr[mid - 1] <= arr[mid])))
            return arr[mid];
        if (mid > 0 && arr[mid - 1] >= arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
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
    int res = peak1(v, n);
    cout << res;

    return 0;
}
