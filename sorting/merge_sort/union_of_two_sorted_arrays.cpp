#include <bits/stdc++.h>
using namespace std;

// TC: O(m+n) AS: O(1)
void union1(vector<int> a, vector<int> b, int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (i > 0 && a[i - 1] == a[i])
        {
            i++;
            continue;
        }
        if (j > 0 && b[j - 1] == b[j])
        {
            j++;
            continue;
        }
        if (a[i] < b[j])
        {
            cout << a[i++] << " ";
            // i++;
        }
        else if (a[i] > b[j])
        {
            cout << b[j++] << " ";
            // j++;
        }
        else
        {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }
    while (i < m)
    {
        if (i == 0 || a[i - 1] != a[i])
            cout << a[i++] << " ";
        // i++;
    }
    while (j < n)
    {
        if (j == 0 || b[j - 1] != b[j])
            cout << b[j++] << " ";
        // j++;
    }
}

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> v1, v2;
    for (int i = 0; i < n1; i++)
    {
        int x;
        cin >> x;
        v1.push_back(x);
    }
    for (int i = 0; i < n2; i++)
    {
        int x;
        cin >> x;
        v2.push_back(x);
    }
    // vector<int> res = intersection(v1, v2);
    union1(v1, v2, n1, n2);
    // for (int x : res)
    //     cout << x << " ";

    return 0;
}