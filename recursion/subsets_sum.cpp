#include <bits/stdc++.h>
using namespace std;

int subsetsSum(int arr[], int n, int sum)
{
    if (n == 0)
        return (sum == 0) ? 1 : 0;
    return subsetsSum(arr, n - 1, sum) + subsetsSum(arr, n - 1, sum - arr[n - 1]);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int sum;
    cin >> sum;
    int res = subsetsSum(arr, n, sum);
    cout << res;
    return 0;
}
