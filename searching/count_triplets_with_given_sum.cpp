#include <bits/stdc++.h>
using namespace std;
#include <unordered_set>

// two pointer approach
// TC: O(nlogn)+O(n^2)=O(n^2) AS: O(1)
int findTriplets(vector<int> arr, int k)
{
    int n = arr.size();
    int count = 0;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        int left = i + 1;
        int right = n - 1;
        int sum = k - arr[i];
        while (left < right)
        {
            if (arr[left] + arr[right] == sum)
            {
                count++;
                left++;
                right--;
            }
            else if (arr[left] + arr[right] > sum)
                right--;
            else
                left++;
        }
    }
    return count;
}

void printSet(set<int> s)
{
    for (auto it : s)
        cout << it << " ";
}

// hashing // dont consider
int findTriplets1(vector<int> arr, int k)
{
    map<int, int> mpp;
    set<set<int> > s;
    set<int> r;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = k - (arr[i] + arr[j]);
            if (mpp.find(sum) != mpp.end())
            {
                r.insert(arr[i]);
                r.insert(arr[j]);
                r.insert(sum);
                s.insert(r);
                r.clear();
            }
            else
            {
                mpp[arr[j]] = 1;
            }
        }
    }
    for (auto it = s.begin(); it != s.end(); it++)
    {
        printSet(*it);
        cout << endl;
    }
    return s.size();
}

// hashing O(n^2) TC O(n) AS
int findTriplets2(vector<int> arr, int k)
{

    int n = arr.size();
    int count = 0;
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            int sum = k - (arr[i] + arr[j]);
            if (s.find(sum) != s.end())
            {
                count++;
            }
            else
            {
                s.insert(arr[j]);
            }
        }
        s.clear();
    }
    // for (auto it = s.begin(); it != s.end(); it++)
    // {
    //     printSet(*it);
    //     cout << endl;
    // }
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
    int k;
    cin >> k;
    int res = findTriplets2(v, k);
    cout << res;

    return 0;
}
