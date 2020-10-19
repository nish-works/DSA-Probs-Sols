#include <bits/stdc++.h>
using namespace std;

// TC: O(n^3) AS: O(1)
int goodTripletsCount(vector<int> arr, int a, int b, int c)
{
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (abs(arr[j] - arr[i]) <= a)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (abs(arr[k] - arr[j]) <= b && abs(arr[k] - arr[i]) <= c)
                        count++;
                }
            }
        }
    }
    return count;
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
    int a, b, c;
    cin >> a >> b >> c;
    int res = goodTripletsCount(v, a, b, c);
    cout << res;

    return 0;
}
