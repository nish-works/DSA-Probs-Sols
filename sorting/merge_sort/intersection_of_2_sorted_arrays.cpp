#include <bits/stdc++.h>
using namespace std;

// TC: O(n1*n2) AS: O(n)
vector<int> intersection(vector<int> v1, vector<int> v2)
{
    vector<int> res;
    int n1 = v1.size(), n2 = v2.size();
    for (int i = 0; i < n1; i++)
    {
        if (i > 0 && v1[i - 1] == v1[i])
            continue;
        for (int j = 0; j < n2; j++)
        {
            if (v1[i] == v2[j])
                res.push_back(v1[i]);
        }
    }
    return res;
}

void intersection2(vector<int> a, vector<int> b, int m, int n)
{
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (i > 0 && a[i - 1] == a[i])
        {
            i++;
            continue;
        }
        // if (j > 0 && b[j - 1] == b[j])
        // {
        //     j++;
        //     continue;
        // }
    if (a[i] < b[j])
        i++;
    else if (a[i] > b[j])
        j++;
    else if (a[i] == b[j])
    {
        cout << a[i] << " ";
        i++;
        j++;
    }
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
    intersection2(v1, v2, n1, n2);
    // for (int x : res)
    //     cout << x << " ";

    return 0;
}