#include <bits/stdc++.h>
using namespace std;

// Naive solution
// TC: O(n*k) AS: O(n-k+1)=O(n)
vector<int> distinctCountInWindow(vector<int> arr, int k)
{
    vector<int> distinctElements, res;
    for (int i = 0; i < arr.size() - k + 1; i++)
    {
        distinctElements.clear();
        for (int j = i; j < i + k; j++)
        {
            if (find(distinctElements.begin(), distinctElements.end(), arr[j]) == distinctElements.end())
                distinctElements.push_back(arr[j]);
        }
        res.push_back(distinctElements.size());
    }
    return res;
}

// Using hashmap and window sliding
// Optimized solution
// TC: O(n) AS: O(n)
vector<int> distinctCountInWindow1(vector<int> arr, int k)
{
    map<int, int> hm;
    vector<int> res;
    int distinct_count = 0;
    for (int i = 0; i < k; i++)
    {
        if (hm[arr[i]] == 0)
            distinct_count++;
        hm[arr[i]]++;
    }
    res.push_back(distinct_count);
    for (int i = k; i < arr.size() - k + 1; i++)
    {
        if (hm[arr[i - k]] == 1) // if removed ele is occured only once in prev window
            distinct_count--;

        hm[arr[i - k]]--; // if removed ele is either occured once or more than once, so reduce its count for sure

        if (hm[arr[i]] == 0)
            distinct_count++;
        hm[arr[i]]++;

        res.push_back(distinct_count);
    }
    return res;
}

int main()
{
    int n;
    vector<int> arr, res;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    int k;
    cin >> k;

    res = distinctCountInWindow(arr, k);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}
