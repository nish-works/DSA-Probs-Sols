#include <bits/stdc++.h>
using namespace std;
// For non negative numbers

// Naive
// TC: O(n^2)
// AS: O(1) exempting res arr
vector<int> subarray_with_sum_zero_exists(vector<int> arr)
{
    vector<int> res;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int curr_sum = arr[i];
        if (curr_sum == 0)
        {
            res.push_back(i);
            res.push_back(i);
        }
        for (int j = i + 1; j < arr.size(); j++)
        {
            curr_sum += arr[j];
            if (curr_sum == 0)
            {
                res.push_back(i);
                res.push_back(j);
            }
        }
    }
    return res;
}

// Optimized
// TC: O(n) AS: O(1)
bool subarray_with_sum_zero_exists1(vector<int> arr)
{
    vector<int> prefix, res;
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];

        if (find(prefix.begin(), prefix.end(), sum) != prefix.end() || sum == 0)
            return true;
        prefix.push_back(sum);
    }
    return false;
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

    // vector<int> res;
    bool res;
    res = subarray_with_sum_zero_exists1(arr);
    cout << res;
    // res = subarray_with_sum_zero_exists(arr);
    // for (int i = 0; i < res.size(); i++)
    //     cout << res[i] << " ";
    return 0;
}
