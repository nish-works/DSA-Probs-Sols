#include<bits/stdc++.h>
using namespace std;

// Naive
// TC: O(n^3)
// AS: O(n)
vector<vector<int> > merge(vector<vector<int> > &intervals)
{
    int n = intervals.size();
    for (int i = 0; i < n;)
    {
        int flag = 0;
        if (!intervals[i].size())
        {
            ++i;
            continue;
        }
        for (int j = 0; j < n; ++j)
        {
            if (i == j || !intervals[j].size())
                continue;
            int minval = min(intervals[i][1], intervals[j][1]);
            if (minval == intervals[i][1])
            {
                if (minval >= intervals[j][0] && minval <= intervals[j][1])
                {
                    intervals[i][0] = min(intervals[i][0], intervals[j][0]);
                    intervals[i][1] = max(intervals[i][1], intervals[j][1]);
                    intervals[j].clear();
                    flag = 1;
                }
            }
            else if (minval == intervals[j][1])
            {
                if (minval >= intervals[i][0] && minval <= intervals[i][1])
                {
                    intervals[i][0] = min(intervals[i][0], intervals[j][0]);
                    intervals[i][1] = max(intervals[i][1], intervals[j][1]);
                    intervals[j].clear();
                    flag = 1;
                }
            }
            else
                flag = 0;
        }
        if (flag == 0)
            i = i + 1;
    }
    vector<vector<int> > res;
    for (auto x : intervals)
    {
        if (x.size())
            res.push_back(x);
    }
    return res;
}

// Optimised
// TC: O(nlogn) AS: O(n)
// Without modifying original array
vector<vector<int> > merge1(vector<vector<int> > &intervals)
{
    vector<vector<int> > res;
    sort(intervals.begin(), intervals.end());

    for (int i = 0; i < intervals.size(); ++i)
    {
        if (res.size() == 0 || intervals[i][0] > res.back()[1])
            res.push_back(intervals[i]);
        else
            res.back()[1] = max(res.back()[1], intervals[i][1]);
    }
    return res;
}

// Optmised
// TC: O(nlogn) AS: O(n)
// Modifying the original array
vector<vector<int> > merge2(vector<vector<int> > &intervals)
{
    if (intervals.size() == 0)
        return intervals;

    sort(intervals.begin(), intervals.end());

    int res = 0;
    for (int i = 1; i < intervals.size(); ++i)
    {
        if (intervals[res][1] >= intervals[i][0])
            intervals[res][1] = max(intervals[res][1], intervals[i][1]);
        else
        {
            res++;
            intervals[res] = intervals[i];
        }
    }

    res = res + 1;
    vector<vector<int> > result(res);
    copy(intervals.begin(), intervals.begin() + res, result.begin());
    // or
    // for(auto it=intervals.begin(); it<=intervals.begin()+res; ++it)
    //     result.push_back(*it);

    return result;
}

// [[1,3],[2,6],[8,10],[15,18]] => [[1,6],[8,10],[15,18]]
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int> > intervals;
    for (int i = 0; i < n; ++i){
        vector<int> t;
        for (int j = 0; j < 2; ++j){
            int x;
            cin >> x;
            t.push_back(x);
        }
        intervals.push_back(t);
        t.clear();
    }

    vector<vector<int> > res = merge(intervals);
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
        cout << "[" << res[i][0] << "," << res[i][1] << "],";
    cout << "]";
}
