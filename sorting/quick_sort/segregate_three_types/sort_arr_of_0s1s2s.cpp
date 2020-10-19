#include <bits/stdc++.h>
using namespace std;

// All multiple elements of pivot should be in one place, elements lower than these will go to its left, greater to its right

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// Naive
// TC: O(n) four traversals AS: O(n)
// Can simply maintain count for each and write in result but indexes are ignored. The input data might be k,v related to students scores and their roll nos. or so, this naive solution would preserve the keys and treat them as objects and will sort students
void segregate0s1s2s(vector<int> &nums, int n)
{
    vector<int> temp;
    int i;
    for (i = 0; i < n; ++i)
        if (nums[i] == 0)
            temp.push_back(nums[i]);
    for (int j = 0; j < n; ++j)
        if (nums[j] == 1)
            temp.push_back(nums[j]);
    for (int k = 0; k < n; ++k)
        if (nums[k] == 2)
            temp.push_back(nums[k]);
    nums = temp;
}

// Optimised
// TC: O(n) single traversal AS: O(1)
// Modified Hoare partition algorithm with extra pointer called "Dutch National flag algorithm/ Three wap partitioning algorithm"
void segregate0s1s2s1(vector<int> &nums, int n)
{
    int l = 0, r = n - 1, mid = 0;
    while (mid <= r)
    {
        switch (nums[mid])
        {
        case 0:
            swap(&nums[l], &nums[mid]);
            ++l, ++mid;
            break;
        case 1:
            ++mid;
            break;
        case 2:
            swap(&nums[mid], &nums[r]);
            --r;
            break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    segregate0s1s2s1(nums, n);
    for (int x : nums)
        cout << x << " ";
    return 0;
}
