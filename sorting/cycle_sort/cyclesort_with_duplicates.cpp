#include <bits/stdc++.h>
using namespace std;

void cycleSortWithDuplicates(vector<int> &arr, int n)
{
    for (int cs = 0; cs < n - 1; ++cs)
    {
        int pos = cs;
        int item = arr[cs];
        for (int i = cs + 1; i < n; ++i)
            if (arr[i] < item)
                ++pos;
        
        if(pos==cs)
            continue;

        while (arr[pos] == item)
            ++pos;

        if (arr[pos] != item)
            swap(item, arr[pos]);

        while (pos != cs)
        {
            pos = cs;
            for (int i = cs + 1; i < n; ++i)
                if (arr[i] < item)
                    ++pos;

            while(arr[pos]==item)
                ++pos;

            if(arr[pos]!=item)
                swap(arr[pos], item);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cycleSortWithDuplicates(arr, n);
    for (int x : arr)
        cout << x << " ";
    return 0;
}
