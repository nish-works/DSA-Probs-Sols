#include <bits/stdc++.h>
using namespace std;

// int josephus(int n, int k, int curr, vector<int> killed)
// {
//     int x;
//     if (killed.size() == n - 1)
//     {
//         return curr;
//     }

//     if (find(killed.begin(), killed.end(), curr + k - 1) == killed.end())
//         killed.push_back(curr + k - 1);
//     else
//         killed.push_back(curr + k);

//     // killed.push_back(curr + k - 1);
//     if (curr + k - n >= 0)
//         x = curr + k - n;
//     else
//         x = curr + k;
//     if (find(killed.begin(), killed.end(), x) == killed.end())
//         curr = x;
//     // else
//     //     curr = curr;
//     return josephus(n, k, curr, killed);
// }

// Optimized solution TC: O(n) AS: O(n)
int jos(int n, int k)
{
    if (n == 1)
        return 0;
    else
        return (jos(n - 1, k) + k) % n;
}

int main()
{
    int n, k, curr = 0;
    vector<int> arr;
    cin >> n >> k;
    int res = jos(n, k);
    cout << res;
    return 0;
}
