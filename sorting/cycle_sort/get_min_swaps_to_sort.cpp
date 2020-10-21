#include <bits/stdc++.h>
using namespace std;

int minSwaps(vector<int> &arr, int n)
{
    int writes = 0;
    for (int cs = 0; cs < n - 1; ++cs)
    {
        int pos = cs;
        int item = arr[cs];
        for (int i = cs + 1; i < n; ++i)
            if (arr[i] < item)
                ++pos;

        if (pos == cs)
            continue;

        while (arr[pos] == item)
            ++pos;

        if (arr[pos] != item)
        {
            swap(item, arr[pos]);
            ++writes;
        }

        while (pos != cs)
        {
            pos = cs;
            for (int i = cs + 1; i < n; ++i)
                if (arr[i] < item)
                    ++pos;

            while (arr[pos] == item)
                ++pos;

            if (arr[pos] != item)
            {
                swap(arr[pos], item);
                ++writes;
            }
        }
    }
    return writes;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int writes = minSwaps(arr, n);
    cout << writes;
    return 0;
}
