// To output true if there exists a sub array with given k and sum
// Otherwise false
#include <bits/stdc++.h>
using namespace std;

// Naive solution
// TC: Theta(n^2) AS: O(1)
bool doSuchSubArrayExist(vector<int> arr, int k, int sum)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int curr_sum = 0;
        for (int j = i; j < i + k; j++)
        {
            curr_sum += arr[j];
        }
        if (curr_sum == sum)
            return true;
    }
    return false;
}

// Optimized solution
// TC: O(n) AS: O(1)
bool doSuchSubArrayExist1(vector<int> arr, int k, int sum)
{
    int curr_sum = 0;
    for (int i = 0; i < k; i++)
        curr_sum += arr[i];
    if (curr_sum == sum)
        return true;
    for (int i = k; i < arr.size(); i++)
    {
        curr_sum += arr[i] - arr[i - k];
        if (curr_sum == sum)
            return true;
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
    int k, sum;
    cin >> k >> sum;

    bool res = doSuchSubArrayExist1(arr, k, sum);
    cout << res;
    return 0;
}
