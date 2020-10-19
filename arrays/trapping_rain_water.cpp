#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) AS: O(1)
int getTrappedWater(vector<int> arr, int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int lmax = arr[i];
        for (int j = 0; j < i; j++)
        {
            lmax = max(lmax, arr[j]);
        }
        int rmax = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            rmax = max(rmax, arr[j]);
        }
        res += min(lmax, rmax) - arr[i];
    }
    return res;
}

// TC: O(n) AS: O(n)
int getTrappedWater1(vector<int> arr, int n)
{
    vector<int> lmax(n), rmax(n);
    int res = 0;
    lmax[0] = arr[0];
    for (int i = 1; i < n; i++)
        lmax[i] = max(arr[i], lmax[i - 1]);
    rmax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        rmax[i] = max(arr[i], rmax[i + 1]);
    for (int i = 0; i < n; i++)
        res += min(lmax[i], rmax[i]) - arr[i];
    return res;
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
    int res = getTrappedWater(arr, n);
    cout << res;
    return 0;
}
