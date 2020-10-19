#include <bits/stdc++.h>
using namespace std;

// Naive TC: Theta(n^2) AS: O(1)
int maxSumSubArray(vector<int> arr, int n)
{
    int res = arr[0];
    for (int i = 0; i < n; i++)
    {
        int curr_max = 0;
        for (int j = i; j < n; j++) // Traversing through all subarrays starting with i
        {
            curr_max = curr_max + arr[j]; // Finding sum of all subarrays starting with i
            res = max(res, curr_max);     // Maintaining max among all
        }
    }
    return res;
}

// Naive Recursive
// int rec(vector<int> arr, int end, int sum)
// {

//     // int curr_max = arr[start];
//     int res = 0;
//     if (end == 0)
//         return sum;
//     for (int i = 0; i < end; i++){
//         sum += rec(arr, end - 1, sum) + rec(arr, end - 1, sum + arr[end - 1]);
//         res = max(res, sum);
//     }
//     return res;
// }

// Optimized TC: Theta(n) AS: O(1)
// Get max at each index, since we need to take only contiguos elements max,
// it should be max(sum of max till i-1 & i or only i)
int maxSumSubArray1(vector<int> arr, int n)
{
    int res = arr[0];
    int curr_max = arr[0];
    for (int i = 1; i < n; i++)
    {
        curr_max = max(arr[i], curr_max + arr[i]);
        res = max(curr_max, res);
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

    int res = maxSumSubArray(arr, n);
    cout << res;
    return 0;
}