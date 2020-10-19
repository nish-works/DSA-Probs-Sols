#include <bits/stdc++.h>
using namespace std;
#include <unordered_map>

// Optimized solution: Hashtable
// TC: Theta(n) AS: O(n)
void frequencies(vector<int> arr, int n)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        if (mpp.find(arr[i]) == mpp.end())
            mpp[arr[i]] = 1;
        else
        {
            int val = mpp[arr[i]];
            mpp[arr[i]] = val + 1;
        }
    }
    for (auto i : mpp)
        cout << i.first << ":" << i.second << endl;
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

    frequencies(arr, n);
    return 0;
}
