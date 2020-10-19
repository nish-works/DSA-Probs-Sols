#include <iostream>
using namespace std;
#include <vector>

// [7 0 1 2 3 4 5 6], [4 5 6 7 0 1 2]
// recursive O(logn) AS: O(logn)
int search(vector<int> arr, int x, int low, int high)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == x)
        return mid;
    else if (arr[low] <= arr[mid])
    {
        if (x >= arr[low] && x < arr[mid])
            return search(arr, x, low, mid - 1);
        else
            return search(arr, x, mid + 1, high);
    }
    else
    {
        if (x > arr[mid] && x <= arr[high])
            return search(arr, x, mid + 1, high);
        else
            return search(arr, x, low, mid - 1);
    }
}

// iterative O(logn)
int search1(vector<int> arr, int x)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[low] <= arr[mid])
        {
            if (x < arr[mid] && x >= arr[low])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (x > arr[mid] && x <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
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
    int res = search(v, x, 0, n - 1);
    cout << res;

    return 0;
}
