
#include <bits/stdc++.h>
using namespace std;

// input sorted array
// TC: O(n) AS: O(1)
int count1s(vector<int> arr)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
        sum += arr[i];
    return sum;
}

// TC: O(logn) AS:O(1)
int count1s1(vector<int> arr)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (mid == 0 || (arr[mid] == 1 && arr[mid - 1] == 0))
            return (arr.size() - mid);
        if (arr[mid] == 1)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return 0;
}

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
    int res = count1s1(v);
    cout << res;

    return 0;
}
