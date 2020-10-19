
#include <bits/stdc++.h>
using namespace std;

int getFirstIndex(vector<int> arr, int x, int low, int high)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;
    if (arr[mid] == x)
    {
        if (mid == 0 || arr[mid - 1] != x)
            return mid;
        else
            return getFirstIndex(arr, x, low, mid - 1);
    }
    else if (arr[mid] > x)
        return getFirstIndex(arr, x, low, mid - 1);
    else
        return getFirstIndex(arr, x, mid + 1, high);
}

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

// input: sorted array
// TC: O(logn)+O(logn)=O(logn) AS: O(logn)
int getOccurrences(vector<int> arr, int x)
{
    int first = getFirstIndex(arr, x, 0, arr.size() - 1);
    if (first == -1)
        return 0;
    int second = getLastIndex(arr, x, 0, arr.size() - 1);
    int count = second - first + 1;
    return count;
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
    int res = getOccurrences(v, x);
    cout << res;

    return 0;
}
