#include <iostream>
using namespace std;
#include <vector>

int mergeAndCount(vector<int> arr, int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    vector<int> left(n1), right(n2);
    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    cout << "\n"
         << "left";
    for (int x : left)
        cout << x;
    cout << "\n"
         << "right";
    for (int x : right)
        cout << x;
    cout << "arr";
    for (int x : arr)
        cout << x << " ";

    int i = 0, j = 0, k = l;
    int res = 0;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
        {
            arr[k++] = right[j++];
            res = res + n1 - i;
        }
    }
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];
    return res;
}

int countInversion(vector<int> arr, int l, int r)
{
    int res = 0;
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        res = res + countInversion(arr, l, mid);
        // cout<<res<<" ";
        res = res + countInversion(arr, mid + 1, r);
        // cout<<res<<" ";
        res = res + mergeAndCount(arr, l, mid, r);
        // cout<<res<<" ";
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    int count = countInversion(arr, 0, n - 1);
    cout << count;
    // your code goes here
    return 0;
}
