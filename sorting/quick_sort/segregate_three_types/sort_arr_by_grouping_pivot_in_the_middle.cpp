#include <bits/stdc++.h>
using namespace std;

// All multiple elements of pivot should be in one place, elements lower than these will go to its left, greater to its right

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// Optimised
// TC: O(n) single traversal AS: O(1)
// Dutch National Flag/ Three way partitioning algorithm
void sortInThreeGroups(vector<int> &nums, int n, int pivot)
{
    int l = 0, r = n - 1, mid = 0;
    while (mid <= r)
    {
        if (nums[mid] < pivot)
        {
            swap(&nums[l], &nums[mid]);
            ++l, ++mid;
        }
        else if (nums[mid] > pivot)
        {
            swap(&nums[mid], &nums[r]);
            --r;
        }
        else
            ++mid;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, pivot;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    cin >> pivot;
    sortInThreeGroups(nums, n, pivot);
    for (int x : nums)
        cout << x << " ";
    return 0;
}
