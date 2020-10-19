// Find the missing number from 1 to n+1 in the given array

#include <bits/stdc++.h>
using namespace std;

// Naive solution
// TC: O(n^2)
vector<int> solve1(vector<int> arr, int n)
{
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }
        if ((count % 2 != 0) && (find(res.begin(), res.end(), arr[i]) == res.end()))
            res.push_back(arr[i]);
    }
    return res;
}

// Efficient solution: TC: Theta(n)
vector<int> solve2(vector<int> arr, int n)
{
    int xor_res = 0, sn, res1 = 0, res2 = 0;
    vector<int> res_arr;
    for (int i = 0; i < n; i++)
    {
        xor_res = xor_res ^ arr[i];
    }
    sn = xor_res & ~(xor_res - 1); // To get the rightmost set bit of the xor_res(000..001/000..1000/..)
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] & sn) != 0)
            res1 = res1 ^ arr[i]; // group1: has all numbers with set bit in same place as in sn
        else
            res2 = res2 ^ arr[i]; // group2: has all numbers with no set bit as in sn
    }
    // We divided into group1 and group2 bc xor_res is xor of two only odd numbers which means both are diff nos. i.e both has diff set bits(atleast the rightmost one is diff)
    res_arr.push_back(res1);
    res_arr.push_back(res2);
    return res_arr;
}

int main()
{
    ios_base::sync_with_stdio(0); // fast IO
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> res = solve2(arr, n);
    for (auto i : res)
        cout << i << " ";
    return 0;
}
