#include <bits/stdc++.h>
using namespace std;

// Tail recursive solution
int sum_of_digits(int n, int sum)
{
    if (n == 0)
        return sum;
    return sum_of_digits(n / 10, sum + (n % 10));
}

int main()
{
    int n, sum = 0;
    cin >> n;
    int res = sum_of_digits(n, sum);
    cout << res;
    return 0;
}
