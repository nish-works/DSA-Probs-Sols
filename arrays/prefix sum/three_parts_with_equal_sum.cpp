#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
vector<int> three_parts_with_equal_sum(vector<int> arr)
{
    vector<int> res;
    vector<int> prefix;
    prefix.push_back(arr[0]);
    for (int i = 1; i < arr.size(); i++)
        prefix.push_back(prefix[i - 1] + arr[i]);

    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
        sum += arr[i];

    int multiple = sum / 3;
    // int k = 0, count = 0;
    for (int i = 0; i < prefix.size(); i++)
    {
        if (prefix[i] % multiple == 0 && prefix[i - 1] != prefix[i])
        {
            // res.push_back(k);
            res.push_back(i);
            // k = i + 1;
        }
    }
    if (res.size() == 3)
        return res;
    else
    {
        res.clear();
        return res;
    }
    // return res;
}

// TC: O(n) AS: O(1) excepting the res array
vector<int> three_parts_with_equal_sum1(vector<int> arr)
{
    vector<int> res;
    // vector<int> prefix;
    // prefix.push_back(arr[0]);
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
        sum += arr[i];

    for (int i = 1; i < arr.size(); i++)
        arr[i] = arr[i - 1] + arr[i];

    int multiple = sum / 3;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] % multiple == 0 && arr[i - 1] != arr[i])
        {
            res.push_back(i);
        }
    }
    if (res.size() == 3)
        return res;
    else
    {
        res.clear();
        return res;
    }
    // return res;
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

    vector<int> res;
    res = three_parts_with_equal_sum1(arr);
    // for (int i = 0; i < res.size(); i++)
    //     for (int j = 0; j < res[i].size(); j++)
    //         cout << res[i][j] << " ";
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}
