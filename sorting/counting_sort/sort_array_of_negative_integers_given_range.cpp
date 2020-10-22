#include <bits/stdc++.h>
using namespace std;

// For negative integers
// l, u can be negative bound
// TC: O(n+k)
// AS: O(n+k)
void countingSort(vector<int> &arr, int n, int min, int max)
{
    int range = max - min + 1;
    vector<int> count(range), output(n);
    for (int i = 0; i < n; ++i)
        ++count[arr[i] - min];
    for (int i = 1; i < range; ++i)
        count[i] += count[i - 1];
    for (int i = 0; i < range; ++i)
        count[i] = count[i] - 1;
    for (int i = 0; i < n; ++i)
    {
        output[count[arr[i] - min]] = arr[i];
        --count[arr[i] - min];
    }
    arr = output;
    return;
}

int main()
{
    int n, l, u;
    cin >> n >> l >> u;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    countingSort(arr, n, l, u);
    for (int x : arr)
        cout << x << " ";
    return 0;
}
