#include <bits/stdc++.h>
using namespace std;

// Tail recursive solution
int fibnocci(int n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    // or simply if(n<=1) return n;
    else
        return fibnocci(n - 1) + fibnocci(n - 2);
}

int main()
{
    int n, k = 1;
    cin >> n;
    int res = fibnocci(n);
    cout << res;
    return 0;
}
