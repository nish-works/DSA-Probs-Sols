#include <bits/stdc++.h>
using namespace std;

// Naive
// TC: Theta(n^2) AS: O(1)
int getMaxEvenOddSubArray(vector<int> arr, int n)
{
    int res = 1;
    for (int i = 0; i < n - 1; i++)
    {
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (((arr[j] % 2 == 0) && (arr[j - 1] % 2 != 0)) || ((arr[j] % 2 != 0) && (arr[j - 1] % 2 == 0)))
                count++;
            else
                break;
        }
        res = max(res, count);
    }
    return res;
}

// Efficient
// TC: Theta(n) AS: O(1)
int getMaxEvenOddSubArray1(vector<int> arr, int n)
{
    int count = 1;
    int res = 1;
    for (int i = 1; i < n; i++)
    {
        if (((arr[i] % 2 == 0) && (arr[i - 1] % 2 != 0)) || ((arr[i] % 2 != 0) && (arr[i - 1] % 2 == 0)))
            count++;
        else
            count = 1;
        res = max(res, count);
    }
    return res;
}

int main()
{
    int n;
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    int res = getMaxEvenOddSubArray1(arr, n);
    cout << res;
    return 0;
}
