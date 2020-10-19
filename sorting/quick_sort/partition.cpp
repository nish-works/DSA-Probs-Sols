#include <bits/stdc++.h>
using namespace std;

void partition(vector<int> &arr, int l, int h, int p)
{
    int n = arr.size();
    int index = 0;
    vector<int> temp(h - l + 1, 0);

    for (int i = l; i <= h; i++)
        if (arr[i] < arr[p])
            temp[index++] = arr[i];

    temp[index++] = arr[p];

    for (int i = l; i <= h; i++)
        if (arr[i] > arr[p])
            temp[index++] = arr[i];

    arr = temp;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int lomutoPartition(vector<int> arr, int l, int h, int k)
{
    swap(arr[k], arr[h]);
    int pivot = arr[h];
    int i = -1;
    for (int j = l; j <= h - 1; ++j)
    {
        if (arr[j] < pivot)
        {
            swap(arr[i + 1], arr[j]);
            ++i;
        }
    }
    swap(arr[i + 1], arr[h]);
    for (int x : arr)
        cout << x << " ";
    return i + 1;
}

int hoarePartition(vector<int> &arr, int l, int h, int k)
{
    swap(&arr[k], &arr[l]);
    int pivot = arr[l];
    int i = l, j = h;
    // int i = l - 1, j = h + 1;
    // while (true)
    // {
    //     do
    //     {
    //         i++;
    //     } while (arr[i] < pivot);
    //     do
    //     {
    //         j--;
    //     } while (arr[j] > pivot);
    //     if (i >= j)
    //     {
    //         for (int x : arr)
    //             cout << x << " ";
    //         return j;
    //     }
    //     // return j;
    //     swap(&arr[i], &arr[j]);
    // }

    while (true)
    {
        while (arr[i] < pivot)
            ++i;
        while (arr[j] > pivot)
            --j;
        if (i >= j){
            for (int x : arr)
                cout << x << " ";
            return j;
        }
        swap(arr[i], arr[j]);
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // int res = lomutoPartition(arr, 0, n - 1, k);
    // cout << res;
    int res = hoarePartition(arr, 0, n - 1, k);
    cout << res;
    // for (int x : arr)
    //     cout << x << " ";
    // your code goes here
    return 0;
}