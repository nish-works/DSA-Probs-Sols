#include <bits/stdc++.h>
using namespace std;
#include <unordered_map>

// Naive solution
// TC: Theta(n^2) AS: O(1)
int majorityEleIndex1(vector<int> arr, int n)
{
    int res = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] == arr[i])
                count++;
        }
        if (count > n / 2)
            return i;
    }
    return -1;
}

// Using sorting
// TC: O(nlogn) AS: O(1)
// 3 3 3 1
int majorityElement1(vector<int> arr, int n)
{
    sort(arr.begin(), arr.end());
    int count = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == arr[i + 1])
            count++;
        else
        {
            if (count > n / 2)
                return arr[i];
            count = 1;
        }
    }
    return -1;
}

// My solution using hash table
// TC: Theta(n) AS: O(1)
int majorityEleIndex(vector<int> arr, int n)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        if (mpp.find(arr[i]) != mpp.end())
        {
            int val = mpp[arr[i]];
            mpp[arr[i]] = val + 1;
        }
        else
        {
            mpp[arr[i]] = 1;
        }
    }
    int res = -1;
    for (auto it : mpp)
    {
        if (it.second > n / 2)
        {
            auto it1 = find(arr.begin(), arr.end(), it.first);
            res = distance(arr.begin(), it1);
        }
    }
    return res;
}

// Optimized solution
// TC: Theta(n) AS: O(1)
// Moore's voting algorithm
// Phase 1
int findCandidate(vector<int> arr, int n)
{
    int majorityIndex = 0, count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[majorityIndex] == arr[i])
            count++;
        else
            count--;
        if (count == 0)
        {
            count = 1;
            majorityIndex = i;
        }
    }
    return arr[majorityIndex];
}

// Phase 2
int getMajorityIndex(vector<int> arr, int n)
{
    int majorityElement = findCandidate(arr, n);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == majorityElement)
            count++;
    }
    if (count > n / 2)
    {
        auto it = find(arr.begin(), arr.end(), majorityElement);
        return distance(arr.begin(), it);
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

    int res = majorityElement1(arr, n);
    cout << res;
    return 0;
}
