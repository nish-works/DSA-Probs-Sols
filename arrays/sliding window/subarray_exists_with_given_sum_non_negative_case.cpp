#include <bits/stdc++.h>
using namespace std;

// Optimized solution
// My solution
// TC: O(n) AS: O(1)
// Works only for non negative numbers
bool doSuchSubArrayExist1(vector<int> arr, int sum)
{
    int curr_window = 0;
    int k = 0;
    for (int i = 0; i <= arr.size(); i++) // we used == incase the last ele is the sum i.e
    // arr =  [1 4 20 3 10 15], sum=15
    {
        if (curr_window > sum)
        {
            while (curr_window > sum)
            {
                curr_window -= arr[k];
                k++;
            }
        }
        if (curr_window < sum)
            curr_window += arr[i];

        if (curr_window == sum)
            return true;
    }
    return false;
}

// Optimized solution
// Sir solution
// TC: O(n) AS: O(1)
// Works only for non negative numbers
bool doSuchSubArrayExist2(vector<int> arr, int sum)
{
    int curr_sum = arr[0];
    int start = 0;
    for (int end = 1; end <= arr.size(); end++)
    {
        while (curr_sum > sum && start < end - 1)
        {
            curr_sum -= arr[start];
            start++;
            cout << curr_sum << " ";
        }
        if (curr_sum == sum)
            return true;
        if (end < arr.size())
        {
            curr_sum += arr[end];
            cout << curr_sum << " ";
        }
    }
    return (curr_sum == sum);
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
    int sum;
    cin >> sum;

    bool res = doSuchSubArrayExist2(arr, sum);
    cout << res;
    return 0;
}
