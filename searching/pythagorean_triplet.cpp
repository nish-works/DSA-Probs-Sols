#include <bits/stdc++.h>
using namespace std;
#include <unordered_map>

// sort+two pointer approach TC: O(n^2) AS: O(1)
bool tripletExists(vector<int> arr)
{
    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++)
        arr[i] = arr[i] * arr[i];

    for (int i = arr.size() - 1; i >= 0; i++)
    {
        int left = 0;
        int right = i - 1;
        while (left < right)
        {
            if (arr[left] + arr[right] == arr[i])
                return true;
            else if (arr[left] + arr[right] > arr[i])
                right--;
            else
                left++;
        }
    }
    return false;
}

//hashing TC: O(n^2) AS: O(n)
bool tripletExists1(vector<int> arr)
{
    unordered_map<int, int> um;
    for (int i = 0; i < arr.size(); i++)
        um[arr[i]]++;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            int x = arr[i] * arr[i];
            int y = arr[j] * arr[j];
            if (um.find(sqrt(x + y)) != um.end())
                return true;
        }
    }
    return false;
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
    bool res = tripletExists1(v);
    cout << res;

    return 0;
}