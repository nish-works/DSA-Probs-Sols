#include <bits/stdc++.h>
using namespace std;

// Naive solution
// TC: O(n) time to process each query AS: O(1)
int getSum(vector<int> arr, int l, int r)
{
    int curr_sum = 0;
    for (int i = l; i <= r; i++)
        curr_sum += arr[i];
    return curr_sum;
}

// Optimized solution
// TC: O(1) time to process each query, however you can take O(n) time to preprocess array data once
// AS: O(1)
vector<int> computePrefixSumArray(vector<int> arr)
{
    vector<int> prefix_array;
    prefix_array.push_back(arr[0]);
    for (int i = 1; i < arr.size(); i++)
        prefix_array.push_back(prefix_array[i - 1] + arr[i]);
    return prefix_array;
}

int getSum1(vector<int> prefix_array, int l, int r)
{
    if (l != 0)
        return prefix_array[r] - prefix_array[l - 1];
    else
        return prefix_array[r];
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
    int l, r;

    // for naive
    // for (int i = 0; i < 10; i++) // what if there are 1000's of queries on the same array
    // {
    //     cin >> l >> r;
    //     int res = getSum(arr, l, r);
    //     cout << res;
    // }
    vector<int> prefix_array = computePrefixSumArray(arr);
    for (int i = 0; i < prefix_array.size(); i++)
        cout << prefix_array[i] << " ";
    for (int i = 0; i < 10; i++)
    {
        cin >> l >> r;
        int qres = getSum1(prefix_array, l, r);
        cout << qres;
    }

    return 0;
}
