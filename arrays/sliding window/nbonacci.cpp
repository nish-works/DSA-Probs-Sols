#include <bits/stdc++.h>
using namespace std;

// Naive approach
// TC: O(n)+O(n*m) = O(n*m) AS: O(m)
vector<int> nbonacci(int n, int m)
{
    vector<int> arr;
    for (int i = 0; i < n - 1; i++)
        arr.push_back(0);
    arr.push_back(1);
    int curr_sum = 1, start = 1;
    for (int i = n; i < m; i++)
    {
        arr.push_back(curr_sum);
        for (int j = i - n + 1; j < i; j++) // or instead of start initialize to i-n
            curr_sum += arr[j];
        // start++;
    }
    return arr;
}

// Optimized solution
// TC: O(m) AS: O(m)
vector<int> nbonacci1(int n, int m)
{
    vector<int> arr;
    int window_sum = 1;
    for (int i = 0; i < n - 1; i++)
        arr.push_back(0);
    arr.push_back(1);

    // for (int i = 0; i < n; i++)
    //     window_sum += arr[i];

    for (int i = n; i < m; i++)
    {
        arr.push_back(window_sum);
        window_sum = 2 * window_sum - arr[i - n];
    }
    return arr;
}

int main()
{
    int n, m;
    vector<int> arr;
    cin >> n >> m;

    arr = nbonacci1(n, m);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}
