#include <bits/stdc++.h>
using namespace std;

// Tail recursive solution
// TC: T(n) = T(n-2)+c = O(n), AS: O(n) not O(1) bc we are not manipulating string itself, but in each call we are changing s,e. So separate fc is pushed into function call stack each time.
bool palindrome(string &str, int start, int end)
{
    if (start >= end)
        return true;

    else if (str[start] == str[end])
        return palindrome(str, start + 1, end - 1);
    else
        return false;
    // or return (str[start] == str[end]) && palindrome(str, start+1, end-1)
}

int main()
{
    string str;
    int start, end;
    cin >> str;
    bool res = palindrome(str, 0, str.length() - 1);
    cout << res;
    return 0;
}
