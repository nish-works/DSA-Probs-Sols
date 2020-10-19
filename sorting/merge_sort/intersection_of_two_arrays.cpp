#include <bits/stdc++.h>
using namespace std;
#include <unordered_map>

// Sol1-> TC: O(n^2) AS: O(1)
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    vector<int> res;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if ((nums1[i] == nums2[j]) && (find(res.begin(), res.end(), nums1[i])) == res.end())
                res.push_back(nums1[i]);
        }
    }
    return res;
}

// Sol2-> TC: O(min(n1,n2)) AS: O(max(n1,n2))
vector<int> intersection1(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    vector<int> res;
    unordered_map<int, int> mpp;

    if (n2 > n1)
    {
        vector<int> temp(n1);
        temp = nums1;
        nums1 = nums2;
        nums2 = temp;

        int tmp;
        tmp = n1;
        n1 = n2;
        n2 = tmp;
    }

    for (int i = 0; i < n1; i++)
    {
        if (mpp.find(nums1[i]) == mpp.end())
            mpp[nums1[i]]++;
    }
    for (int i = 0; i < n2; i++)
    {
        if ((mpp.find(nums2[i]) != mpp.end()) && (find(res.begin(), res.end(), nums2[i]) == res.end()))
            res.push_back(nums2[i]);
    }

    return res;
}

// TC: O(nlogn) AS: O(1) 
// If sorted already: TC: O(n) AS: O(1)
vector<int> intersection2(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    vector<int> res;

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int l = 0, r = 0;
    while (l != n1 && r != n2)
    {
        if ((nums1[l] == nums2[r]) && (find(res.begin(), res.end(), nums1[l]) == res.end()))
        {
            res.push_back(nums1[l]);
            l++;
            r++;
        }
        else if (nums1[l] > nums2[r])
            r++;
        else
            l++;
    }
    return res;
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
    vector<int> res = intersection2(v1, v2);
    for (int x : res)
        cout << x << " ";

    return 0;
}
