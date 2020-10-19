#include <bits/stdc++.h>
using namespace std;

// Naive TC: Theta(n^2) AS: O(1)
int maxCircularSumSubArray(vector<int> arr, int n)
{
    int res = arr[0];
    for (int i = 0; i < n; i++)
    {
        int curr_sum = 0;
        for (int j = 0; j < n; j++)
        {
            int index = (i + j) % n; // index to start with, formula to get circular sub array indexes to consider
            curr_sum += arr[index];
            res = max(res, curr_sum);
        }
    }
    return res;
}

// Kadane's algorithm
int kadane(vector<int> arr, int n)
{
    int max_normal_subarray_sum = arr[0];
    int curr_sum = arr[0];
    for (int i = 1; i < n; i++)
    {
        curr_sum = max(arr[i], curr_sum + arr[i]);
        max_normal_subarray_sum = max(max_normal_subarray_sum, curr_sum);
    }
    return max_normal_subarray_sum;
}

// Optimized TC: O(n) AS: O(1)
int maxCircularSumSubArray1(vector<int> arr, int n)
{
    int max_normal_subarray_sum = kadane(arr, n);

    // To get min normal sub array sum using same kadane, inorder to reuse the same kadane function, lets find max of inverted arr elements than min of actual arr elements

    // int min_normal_subarray_sum = arr[0];
    // int curr_sum1 = arr[0];
    // for (int i = 1; i < n; i++){
    //     curr_sum1 = min(arr[i], curr_sum1 + arr[i]);
    //     min_normal_subarray_sum = min(min_normal_subarray_sum, curr_sum1);
    // }

    // if (max_normal_subarray_sum < 0)
    //     return max_normal_subarray_sum;

    int total_array_sum = arr[0];
    arr[0] = -arr[0];
    for (int i = 1; i < n; i++)
    {
        total_array_sum += arr[i];
        arr[i] = -arr[i];
    }
    // int circular_max = total_array_sum - min_normal_subarray_sum;
    cout << total_array_sum;
    cout << kadane(arr, n);
    int circular_max = total_array_sum + kadane(arr, n); // + instead of - bc elements are all -ve so -ve res already
    return max(max_normal_subarray_sum, circular_max);
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

    int res = maxCircularSumSubArray1(arr, n);
    cout << res;
    return 0;
}