

#include <bits/stdc++.h>
using namespace std;

// Naive solution
// We are checking if the last bit is set/not(%2), and removing last bit in every iteration (/2)
// Since each bit is a power of 2
// TC: O(total bits in n)
void solve1()
{
    int n;
    cin >> n;
    int set_count = 0;
    while (n > 0)
    {
        if (n % 2 != 0)
            set_count++;
        n = n / 2;
    }
    cout << set_count;
}

// Other Naive solution using same logic but using bitwise operators
// TC: O(total bits in n)
void solve2()
{
    int n, set_count = 0;
    cin >> n;
    while (n > 0)
    {
        if ((n & 1) == 1)
            set_count++;
        n = n >> 1;
    }
    cout << set_count;
}

// Brian kerninghams algorithm TC: Theta(set bits count)
void solve3()
{
    int n, set_count = 0;
    cin >> n;
    while (n > 0)
    {
        n = (n & (n - 1));
        set_count++;
    }
    cout << set_count;
}

// Auxiliary space is constant, SC: Theta(8*256)
int table[256];
void initialize()
{
    table[0] = 0;
    for (int i = 1; i < 256; i++) // range of values for 8bits: (0, 2^7-1)=(0, 255)
        table[i] = (i & 1) + table[i / 2];
}

int lookup_method(int n)
{
    int res = 0;
    for (int i = 1; i <= 4; i++) //32bit
    {
        res = res + table[n & 0xff]; // here 0xff is hexa decimal representation which takes in the last 8 bits in each iteration and does and operation with n
        n = n >> 8;
    }
    return res;
}

// TC: Theta(1)
// Auxiliary space is none, SC: Theta(8*256)
void solve4()
{
    int n = pow(2, 31) - 1, set_bits_count;
    // cin >> n;
    initialize();
    set_bits_count = lookup_method(n);
    cout << set_bits_count;
}

int main()
{
    ios_base::sync_with_stdio(0); // fast IO
    cin.tie(0);
    cout.tie(0);
    solve4();
    return 0;
}
