#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m)+O(1)=O(n*m) where m is the max no. of elements in a range
// AS: O(n*m)
int get_max_appearing_element(vector<int> l, vector<int> r)
{
    map<int, int> hm;
    for (int i = 0; i < l.size(); i++)
    {
        for (int j = l[i]; j <= r[i]; j++)
        {
            hm[j]++;
        }
    }
    int max_val = INT_MIN;
    int max_key;
    for (auto it : hm)
    {
        if (it.second > max_val)
        {
            max_val = it.second;
            max_key = it.first;
        }
    }
    return max_key;
}

// Efficient solution
// TC: O(n)+O(1)=O(n)
// AS: O(1)
int get_max_appearing_element1(vector<int> l, vector<int> r)
{
    vector<int> arr(1000);
    for (int i = 0; i < l.size(); i++)
    {
        arr[l[i]]++;
        arr[r[i] + 1]--;
    }

    // Calculating prefix sum
    int max = INT_MIN;
    int res;
    for (int i = 1; i < 1000; i++)
    {
        arr[i] = arr[i - 1] + arr[i];
        if (arr[i] > max)
        {
            max = arr[i];
            res = i;
        }
    }
    return res;
}

int main()
{
    int n;
    vector<int> L, R;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        L.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        R.push_back(x);
    }

    int res;
    res = get_max_appearing_element1(L, R);
    cout << res;
    return 0;
}
