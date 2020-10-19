#include <bits/stdc++.h>
using namespace std;

// someone elses solution
int findPairs(vector<int> &arr, int sum)
{
    map<int, int> mpp;
    int count = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
        mpp[arr[i]]++;

    if (sum == 0)
    {
        for (auto x : mpp)
        {
            if (x.second > 1)
                count++;
        }
        return count;
    }

    for (auto x : mpp)
    {
        if (mpp.count(x.first - sum))
            count++;
        // if(mpp[x.first-sum]) count++;
    }
    return count;
}

// my sol
// [1,2,4,4,3,3,0,9,2,3], k=3, [3,1,4,1,5], k = 2,  [-1,-2,-3], k = 1 [1,2,4,4,3,3,0,9,2,3], k = 3
int findPairs1(vector<int> &arr, int sum)
{
    map<int, int> mpp;
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        mpp[arr[i]]++;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (sum == 0)
        {
            if (mpp[arr[i] - sum] && mpp[arr[i] - sum] > 1)
            {
                count++;
                mpp[arr[i] - sum] = 1;
            }
        }
        if (sum != 0 && mpp[arr[i] - sum] > 0)
        {
            count++;
            // mpp[arr[i] - sum] = 0;
            mpp.erase(arr[i] - sum);
        }
    }
    return count;
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
    int k;
    cin >> k;
    int res = findPairs1(v, k);
    cout << res;

    return 0;
}
