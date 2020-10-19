#include <bits/stdc++.h>
using namespace std;

// For arr = [1, 5, 3 ,8, 12]
// 1: gives o/p as 11 (12-1)
// 2: gives o/p as 13 (5-1)+(12-3)

// Naive solution: Iterative For modified stock buy and sell problem where we can buy and sell a single stock, not multiple
// TC: O(n^2)
int max_profit_1n(vector<int> arr, int n)
{
    // int max = INT_MAX;
    int res = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int curr_max = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
                curr_max = max(arr[j] - arr[i], curr_max);
        }
        res = max(res, curr_max);
    }
    return res;
}

// Optimized solution for single stock buy and sell
// TC: Theta(n) AS: O(1)
int max_profit_1o(vector<int> arr, int n)
{
    int min_price = INT_MAX;
    int max_pro = 0;
    for (int i = 0; i < n; i++)
    {
        min_price = min(min_price, arr[i]);
        max_pro = max(max_pro, arr[i] - min_price);
    }
    return max_pro;
}

// Naive solution: Recursive For multiple stocks buy and sell
// TC: Theta(n^2) AS: O(n^2)
int max_profit_2n(vector<int> arr, int start, int end)
{
    if (end <= start)
        return 0;
    int profit = 0;
    for (int i = start; i < end; i++)
    {
        for (int j = i + 1; j <= end; j++)
        {
            if (arr[j] > arr[i])
            {
                int curr_profit = arr[j] - arr[i] + max_profit_2n(arr, start, i - 1) + max_profit_2n(arr, j + 1, end);
                profit = max(profit, curr_profit);
            }
        }
    }
    return profit;
}

// Efficient solution: TC: Theta(n) AS: O(1) For multiple stocks buy and sell
int max_profit_2o(vector<int> arr, int n)
{
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            profit += arr[i] - arr[i - 1];
        }
    }
    return profit;
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
    // for (auto i = arr.begin(); i != arr.end(); i++)
    //     cout << *i << " ";
    // reverse(arr.begin() + 0, arr.begin() + n);
    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << " ";
    int res = max_profit_2n(arr, 0, n - 1);
    cout << res;
    return 0;
}
