#include <bits/stdc++.h>
using namespace std;

// Naive TC: O((n1+n1)log(n1+n2))
double findMedianSortedArrays(vector<int> &v1, vector<int> &v2)
{
    int n1 = v1.size();
    int n2 = v2.size();
    vector<int> v(n1 + n2);

    for (int i = 0; i < n1; i++)
        v[i] = v1[i];
    for (int j = 0; j < n2; j++)
    {
        int indx = n1 + j;
        v[indx] = v2[j];
    }

    sort(v.begin(), v.end());

    int n = v.size();
    if (n % 2)
        return v[n / 2];
    else
        return (double)(v[n / 2] + v[n / 2 - 1]) / 2;
}

// Efficient: TC: O(log(min(n1,n2))) AS: O(n1) only when n1>n2 otherwise O(1)
double findMedianSortedArrays1(vector<int> &v1, vector<int> &v2)
{
    int n1 = v1.size();
    int n2 = v2.size();

    if (n1 > n2)
    {
        vector<int> tempv(n1);
        tempv = v1;
        v1 = v2;
        v2 = tempv;

        int temps;
        temps = n1;
        n1 = n2;
        n2 = temps;
    }

    int low1 = 0, high1 = n1;
    while (low1 <= high1)
    {
        int i1 = (low1 + high1) / 2;
        int i2 = ((n1 + n2 + 1) / 2) - i1;

        int max1 = (i1 == 0) ? INT_MIN : v1[i1 - 1];
        int min1 = (i1 == n1) ? INT_MAX : v1[i1];
        int max2 = (i2 == 0) ? INT_MIN : v2[i2 - 1];
        int min2 = (i2 == n2) ? INT_MAX : v2[i2];

        if (max2 <= min1 && max1 <= min2)
        {
            if ((n1 + n2) % 2)
                return (double)(max(max1, max2));
            else
                return (double)(max(max1, max2) + min(min1, min2)) / 2;
        }
        else if (max1 > min2)
            high1 = i1 - 1;
        else
            low1 = i1 + 1;
    }
    return -1;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> v1, v2;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        v1.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v2.push_back(x);
    }
    double res = findMedianSortedArrays(v1, v2);
    cout << res;

    return 0;
}
