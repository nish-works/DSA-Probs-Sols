#include <bits/stdc++.h>
using namespace std;

// NAive O(n^3)
vector<vector<int> > threeSum(vector<int> &nums)
{
    vector<vector<int> > res;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    sort(temp.begin(), temp.end());
                    if (find(res.begin(), res.end(), temp) == res.end())
                    {
                        vector<int> v1;
                        v1.push_back(nums[i]);
                        v1.push_back(nums[j]);
                        v1.push_back(nums[k]);
                        sort(v1.begin(), v1.end());
                        res.push_back(v1);
                    }
                }
            }
        }
    }
    return res;
}

// Optimised code
// TC: O(n^2) AS: O(3n)
void threeSum1(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    // set<int> ans;
    vector<vector<int> > res;
    for (int i = 0; i < nums.size(); i++)
    {
        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0)
            {
                vector<int> temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                temp.push_back(nums[k]);
                
                if(find(res.begin(), res.end(), temp)==res.end()){
                    cout << nums[i] << "," << nums[j] << "," << nums[k];
                    res.push_back(temp);
                }
                j++;
                k--;
                cout << endl;
            }
            if (sum > 0)
                k--;
            if (sum < 0)
                j++;
        }
    }
    // return res;
}

int main()
{
    ios_base::sync_with_stdio(0); // fast IO
    cin.tie(0);
    cout.tie(0);

    vector<int> input(7);
    for (int i = 0; i < 6; i++)
        cin >> input[i];
    threeSum1(input);
    // for (int i = 0; i < res.size(); i++)
    // {
    //     for (auto j = res[i].begin(); j != res[i].end(); j++)
    //         cout << *j << " ";
    //     cout << endl;
    // }

    return 0;
}