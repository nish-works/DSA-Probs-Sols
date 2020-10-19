#include <bits/stdc++.h>
using namespace std;

// TC:O(pos) AS: O(1)
int search(vector<int> arr, int x)
{
    int i = 0;
    while (arr[i] <= x)
        i++;
    if (arr[i - 1] == x)
        return i - 1;
    else
        return -1;
}

// O(log pos) since high is always i-1 where arr[i]>x
int binSearch(vector<int> arr, int x, int low, int high)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;
    if (arr[mid] == x)
        return mid;
    else if (arr[mid] > x)
        return binSearch(arr, x, low, mid - 1);
    else
        return binSearch(arr, x, mid + 1, high);
}

// TC: O(log 2*pos)=O(log pos) AS: O(1)
int search1(vector<int> arr, int x)
{
    if (arr[0] == x)
        return 0;
    int i = 1;
    while (arr[i] < x)
        i = i * 2;
    if (arr[i] == x)
        return i;
    return binSearch(arr, x, i / 2 + 1, i - 1);
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
    int res = search1(v, x);
    cout << res;

    return 0;
}
