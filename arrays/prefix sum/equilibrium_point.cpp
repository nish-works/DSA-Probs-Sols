#include <bits/stdc++.h>
using namespace std;

// Naive solution
// TC: O(n^2) AS: O(1)
int equilibriumPoint(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int lsum = 0, rsum = 0;
        for (int j = 0; j < i; j++)
            lsum += arr[j];
        for (int k = i + 1; k < arr.size(); k++)
            rsum += arr[k];

        if (lsum == rsum)
            return i;
    }
    return -1;
}

// Optimized solution using prefix & suffix sum array
// TC: O(n), has to travel same array thrice
// AS: O(n) for two arrays: prefix and suffix
int equilibriumPoint1(vector<int> arr)
{
    vector<int> prefix_sum_array;
    prefix_sum_array.push_back(arr[0]);
    for (int i = 1; i < arr.size(); i++)
        prefix_sum_array.push_back(prefix_sum_array[i - 1] + arr[i]);

    vector<int> suffix_sum_array;
    suffix_sum_array.push_back(arr[arr.size() - 1]);
    int k = 0;
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        suffix_sum_array.push_back(suffix_sum_array[k] + arr[i]);
        k = k + 1;
    }
    reverse(suffix_sum_array.begin(), suffix_sum_array.end());

    for (int i = 0; i < arr.size(); i++)
    {
        if (prefix_sum_array[i] == suffix_sum_array[i])
            return i;
    }
    return -1;
}

// Optimized solution
// TC: O(n), has to travel same array twice
// AS: O(1)
int equilibriumPoint2(vector<int> arr)
{
    int total_sum = 0;
    for (int i = 0; i < arr.size(); i++)
        total_sum += arr[i];

    int lsum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (lsum == total_sum - arr[i])
            return i;
        lsum += arr[i];
        total_sum -= arr[i];
    }
    return -1;
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

    int res;
    res = equilibriumPoint2(arr);
    cout << res;
    return 0;
}
