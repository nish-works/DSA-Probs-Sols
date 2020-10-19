#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// Hoare partition - Single traversal
// TC: O(n) AS: O(1)
void segregateZeroesAndOnes(vector<int> &nums, int n)
{
    int i = 0, j = n - 1;
    while (true)
    {
        while (nums[j] == 1)
            --j;
        while (nums[i] == 0)
            ++i;
        if (i >= j)
            return;
        swap(&nums[i++], &nums[j--]);
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
    segregateZeroesAndOnes(nums, n);
    for (int x : nums)
        cout << x << " ";
    return 0;
}
