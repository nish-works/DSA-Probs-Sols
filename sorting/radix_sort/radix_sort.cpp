#include <bits/stdc++.h>
using namespace std;

// Here elements with same value in units/tens/hundreds/.. are treated as duplicates i.e same
// TC: O(n) even when range of input values is quadratic
// AS: O(n+10) = O(n)
void countingSort(vector<int> &arr, int n, int exp)
{
    vector<int> count(10, 0), output(n);
    for (int i = 0; i < n; ++i)
        ++count[(arr[i] / exp) % 10];
    for (int i = 1; i < 10; ++i)
        count[i] += count[i - 1];
    for (int i = 0; i < 10; ++i)
        count[i] -= 1;
    for (int i = n - 1; i >= 0; --i)
    {
        output[count[(arr[i] / exp) % 10]] = arr[i];
        --count[(arr[i] / exp) % 10];
    }
    arr = output;
}

void radixSort(vector<int> &arr, int n)
{
    int largest = *max_element(arr.begin(), arr.end());
    for (int exp = 1; largest / exp > 0; exp = exp * 10)
        countingSort(arr, n, exp);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    radixSort(arr, n);
    for (int x : arr)
        cout << x << " ";
    return 0;
}
