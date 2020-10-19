#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// Hoare partition
// TC: O(n) AS: O(1)
void segregateEvenOddNumbers(vector<int> &nums, int n)
{
    int i = 0, j = n - 1;
    while (true)
    {
        while (nums[j] % 2 == 1)
            --j;
        while (nums[i] % 2 == 0)
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
    segregateEvenOddNumbers(nums, n);
    for (int x : nums)
        cout << x << " ";
    return 0;
}
