#include <bits/stdc++.h>
using namespace std;

// Naive TC: O(n^2) AS: O(1)
bool pairWithGivenSum(vector<int> arr, int sum)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == sum)
            {
                cout << "(" << arr[i] << "," << arr[j] << ")";
                return true;
            }
        }
    }
    cout << "(,)";
    return false;
}

// TC: O(n) AS:O(n) Best for unsorted array
bool pairWithGivenSum1(vector<int> arr, int sum)
{
    map<int, int> mpp;
    for (int i = 0; i < arr.size(); i++)
    {
        if (mpp.find(sum - arr[i]) == mpp.end()) // O(1)
            mpp[arr[i]] = i;
        else
        {
            cout << "(" << arr[mpp[sum - arr[i]]] << "," << arr[i] << ")";
            return true;
        }
    }
    cout << "(,)";
    return false;
}

// If you try to sort and then apply two pointer approach, it takes O(nlogn) + O(n) = O(nlogn) AS: O(1)
// So hashing is better for unsorted array

// sorted -> Two pointer algorithm
// TC: O(n) AS: O(1)
bool pairWithGivenSum2(vector<int> arr, int sum)
{
    int left = 0, right = arr.size() - 1;
    while (left < right)
    {
        int res = arr[left] + arr[right];
        if (res == sum)
        {
            cout << "(" << arr[left] << "," << arr[right] << ")";
            return true;
        }
        if (res > sum)
            right--;
        else
            left++;
    }
    cout << "(,)";
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int x;
    cin >> x;
    bool res = pairWithGivenSum2(v, x);
    cout << res;

    return 0;
}
