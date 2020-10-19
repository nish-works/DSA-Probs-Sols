#include <bits/stdc++.h>
using namespace std;

// Solution 1
// Naive: TC: O(nlogn) AS: O(1)
int findKthLargest(vector<int> &nums, int k)
{

    sort(nums.begin(), nums.end());
    int n = nums.size();
    return nums[n - k];
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int lomuto_partition(vector<int> &nums, int l, int r)
{
    // To pick random pivot instead of last element for linear avg time complexity
    // int pindx = l + rand() % r - l;
    // swap(&nums[pindx], &nums[r]);

    int p = nums[r];
    int i = l - 1;
    for (int j = l; j < r; ++j)
    {
        if (nums[j] < p)
        {
            ++i;
            swap(&nums[i], &nums[j]);
        }
    }
    swap(&nums[r], &nums[i + 1]);
    return i + 1;
}

// Solution 2 - Quick select algorithm
// Optimized: TC: O(n^2) AS: O(1)
// Though this solution is quadratic, it works linear in average case and quadratic in only worst case
// Thus works well for most cases than previous solution
int findKthLargest1(vector<int> &nums, int k)
{
    int n = nums.size();
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int p = lomuto_partition(nums, l, r);
        if (p == n - k)
            return nums[p];
        else if (p < n - k)
            l = p + 1;
        else
            r = p - 1;
    }
    return -1;
}

// Solution 3 - Modified quick select algorithm
// Modifying lomuto partition, elements before pivot are greater and after it are smaller.
// Then we apply quick select algorithm same as that for kth smallest element
int lomuto_partition2(vector<int> &nums, int l, int r)
{
    // int pindx = l + rand() % r - l;
    // swap(&nums[pindx], &nums[r]);

    int p = nums[r];
    int i = l - 1;
    for (int j = l; j < r; ++j)
    {
        if (nums[j] > p)
        {
            ++i;
            swap(&nums[i], &nums[j]);
        }
    }
    swap(&nums[r], &nums[i + 1]);
    return i + 1;
}

int findKthLargest2(vector<int> &nums, int k)
{
    int n = nums.size();
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int p = lomuto_partition2(nums, l, r);
        if (p == k - 1)
            return nums[p];
        else if (p < k - 1)
            l = p + 1;
        else
            r = p - 1;
    }
    return -1;
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
    int res = findKthLargest1(nums, k);
    cout << res;
}
