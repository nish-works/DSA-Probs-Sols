#include <bits/stdc++.h>
using namespace std;

// Naive
// TC: O(n^2)
// AS: O(1)
int longest_subarray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
            arr[i] = -1;
    }
    int max = INT_MIN;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int sum = arr[i];
        for (int j = i + 1; j < arr.size(); j++)
        {
            sum += arr[j];
            if (sum == 0)
            {
                if (j - i + 1 > max)
                    max = j - i + 1;
            }
        }
    }
    return max;
}

// Optimized solution
// TC: O(n) AS: O(n)
int longest_subarray1(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] == 0)
            arr[i] = -1;

    int curr_sum = 0;
    int max = 0;
    int size;
    map<int, int> hm;
    for (int i = 0; i < arr.size(); i++)
    {
        curr_sum += arr[i];
        if (curr_sum == 0)
        {
            size = i - 0 + 1;
            if (size > 1 && size > max)
                max = size;
        }
        else if (hm.find(curr_sum) != hm.end())
        {
            size = i + 1 - hm[curr_sum]; // 2
            // hm[curr_sum] = i + 1;        // 5 // 6
            if (size > 1 && size > max)
                max = size; // 2 // 4
        }
        else if (curr_sum != 0 && hm[curr_sum] == 0)
            hm[curr_sum] = i + 1;
    }
    return max;
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

    int res;
    res = longest_subarray1(arr);
    cout << res;
    return 0;
}
