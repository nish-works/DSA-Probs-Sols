#include <bits/stdc++.h>
using namespace std;

// O(n^2)
int getPairsCount(vector<int> arr, int x)
{
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == x)
                count++;
        }
    }
    return count;
}

// Hashing O(n)
int getPairsCount1(vector<int> arr, int x)
{
    map<int, int> mpp;
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
        mpp[arr[i]]++;
    for (int i = 0; i < arr.size(); i++)
    {
        // if (mpp.find(x - arr[i]) != mpp.end())
        count += mpp[x - arr[i]];

        if (x - arr[i] == arr[i])
            count--;
    }

    return count / 2;
}

// two pointer Doesnt work for this prob
// int getPairsCount2(vector<int> arr, int x)
// {
//     sort(arr.begin(), arr.end());
//     int left = 0, right = 1;
//     int count = 0;
//     while (right < arr.size())
//     {
//         if (arr[left] + arr[right] == x)
//         {
//             count++;
//             left++;
//             right++;
//         }
//         else if (arr[left] + arr[right] > x)
//             left++;
//         else
//             right++;
//     }
//     return count;
// }

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
    int res = getPairsCount1(v, x);
    cout << res;

    return 0;
}
