#include <bits/stdc++.h>
using namespace std;

// Naive TC: O(n^3) AS: O(1)
void printTriplet(vector<int> arr, int x)
{
    for (int i = 0; i < arr.size() - 2; i++)
    {
        for (int j = i + 1; j < arr.size() - 1; j++)
        {
            for (int k = j + 1; k < arr.size(); k++)
            {
                if (arr[i] + arr[j] + arr[k] == x)
                {
                    cout << "(" << arr[i] << "," << arr[j] << "," << arr[k] << ")";
                    return;
                }
            }
        }
    }
    cout << "(,,)";
}

// sorted or unsorted
// TC: O(n^2) AS: O(1)
void printTriplet1(vector<int> arr, int x)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = x - arr[i];
        int left = i + 1, right = arr.size() - 1;
        while (left < right)
        {
            int res = arr[left] + arr[right];
            if (res == sum)
            {
                cout << "(" << arr[i] << "," << arr[left] << "," << arr[right] << ")";
                return;
            }
            if (res > sum)
                right--;
            else
                left++;
        }
    }
    cout << "(,)";
}

// unsorted
// hashing
// 40 50 10 20 100, x=70
void printTriplet2(vector<int> arr, int x)
{
    map<int, int> mpp;
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = x - arr[i]; //30
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (mpp.find(sum - arr[j]) == mpp.end())
                mpp[arr[j]] = 1;
            else
            {
                cout << "(" << arr[i] << "," << arr[mpp[sum - arr[j]]] << "," << arr[j] << ")";
                return;
            }
        }
    }
    cout << "(,,)";
    return;
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
    int x;
    cin >> x;
    printTriplet2(v, x);

    return 0;
}
