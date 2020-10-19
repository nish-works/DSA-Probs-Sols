#include <bits/stdc++.h>
using namespace std;

// Distribute n chocolate packets with arr[i] no. of chocolates each, to k children such that the lowest and highest chocolates among the selected should be minimum


// TC: O(nlogn) AS: O(1)
int minChocolatesDiff(vector<int> &nums, int k)
{
    int n = nums.size();
    if (k > n)
        return -1;
    sort(nums.begin(), nums.end());

    int res = nums[k - 1] - nums[0];
    for (int i = 1; i + k - 1 < n; ++i)
        res = min(res, nums[i + k - 1] - nums[i]);

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    int res = minChocolatesDiff(nums, k);
    cout << res;
}
