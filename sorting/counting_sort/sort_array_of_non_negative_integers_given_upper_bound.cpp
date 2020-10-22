#include <bits/stdc++.h>
using namespace std;

// For non negative integers
// TC: O(n+k)
// AS: O(n+k)
void countingSort(vector<int> &arr, int n, int k)
{
    vector<int> count(k, 0), output(n, 0);
    for (int i = 0; i < n; ++i)
        ++count[arr[i]];
    for (int i = 1; i < k; ++i)
        count[i] += count[i - 1];
    for (int i = 0; i < k; ++i)
        count[i] = count[i] - 1;
    for (int i = 0; i < n; ++i)
    {
        output[count[arr[i]]] = arr[i];
        --count[arr[i]];
    }
    arr = output;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    countingSort(arr, n, k);
    for (int x : arr)
        cout << x << " ";
    return 0;
}
