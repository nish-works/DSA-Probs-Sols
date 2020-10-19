#include <bits/stdc++.h>
using namespace std;

// Naive solution
// TC: O(n^2) AS: O(1)
int windowSliding(vector<int> arr, int k)
{
    int res = INT_MIN;
    for (int i = 0; i < arr.size() - k + 1; i++)
    {
        int curr_sum = arr[i];
        for (int j = i + 1; j <= i + k - 1; j++)
        {
            curr_sum += arr[j];
        }
        res = max(res, curr_sum);
    }
    return res;
}

// Optimized solution
// TC: O(n) AS: O(1)
int windowSliding1(vector<int> arr, int k)
{
    int curr_sum = 0;
    int res = INT_MIN;
    for (int i = 0; i < k; i++)
        curr_sum += arr[i];
    for (int i = 1; i < arr.size() - k + 1; i++)
    {
        curr_sum = curr_sum + arr[k + i - 1] - arr[i - 1];
        res = max(res, curr_sum);
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
    int k;
    cin >> k;

    int res = windowSliding(arr, k);
    cout << res;
    return 0;
}
