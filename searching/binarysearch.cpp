#include <iostream>
using namespace std;
#include <vector>

// Naive linear search O(n)
bool search(vector<int> v, int x)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == x)
            return true;
    }
    return false;
}

// Optimized solution O(log n) considering that input is sorted arr
bool search1(vector<int> v, int x)
{
    sort(v.begin(), v.end());
    int low = 0, high = v.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (v[mid] == x)
            return true;
        else if (v[mid] > x)
            high = mid - 1;
        else if (v[mid] < x)
            low = mid + 1;
    }

    return false;
}

// recursive
int search2(vector<int> arr, int x, int low, int high)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;
    if (arr[mid] == x)
        return mid;
    else if (arr[mid] > x)
        return search2(arr, x, low, mid - 1);
    else
        return search2(arr, x, mid + 1, high);
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
    int res = search2(v, x, 0, n - 1);
    cout << res;

    return 0;
}
