#include <bits/stdc++.h>
using namespace std;

// Naive solution with two traversals from 0 to n
// TC: Theta(n) AS: O(1)
void getMinFlips(vector<int> arr, int n)
{
    int onegroups = 0, zerogroups = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            if ((arr[i] != arr[i + 1]) || (i == n - 1))
                onegroups++;
        }
        else
        {
            if ((arr[i] != arr[i + 1]) || (i == n - 1))
                zerogroups++;
        }
    }
    if (zerogroups == 0 || onegroups == 0)
        return;
    if (zerogroups <= onegroups)
    {
        for (int i = 0; i < n; i++)
        {
            if ((arr[i - 1] == 1 && arr[i] == 0) || ((i == 0) && (i + 1 == n - 1)))
                cout << "From " << i;
            if (arr[i] == 0 && arr[i + 1] == 1)
                cout << " to " << i << endl;
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if ((arr[i - 1] == 0 && arr[i] == 1) || ((i == 0) && (i + 1 == n - 1)))
                cout << "From " << i;
            if (arr[i] == 1 && arr[i + 1] == 0)
                cout << " to " << i << endl;
        }
    }
}

// Optimized solution with single traversal
void getMinFlips1(vector<int> arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            if (arr[i] != arr[0])
                cout << "From " << i << " to ";
            else
                cout << i - 1 << endl;
        }
    }
    if (arr[n - 1] != arr[0])
        cout << n - 1 << endl;
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

    getMinFlips1(arr, n);
    return 0;
}
