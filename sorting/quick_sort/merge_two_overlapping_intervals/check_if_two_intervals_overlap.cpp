#include <bits/stdc++.h>
using namespace std;

// [5,10] [1,8] => is said to be overlapping each other because min(interval1[1], interval2[1]) is in the other interval or max(interval1[0], interval2[0]) is in the other interval. We can check for any one condition.
bool overlap(vector<int> &interval1, vector<int> &interval2)
{
    int minval = min(interval1[1], interval2[1]);
    if (minval == interval1[1])
        if (minval >= interval2[0] && minval <= interval2[1])
            return true;

    if (minval == interval2[1])
        if (minval >= interval1[0] && minval <= interval1[1])
            return true;

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> interval1(2), interval2(2);
    cin >> interval1[0] >> interval1[1];
    cin >> interval2[0] >> interval2[1];
    bool res = overlap(interval1, interval2);
    cout << res;
}