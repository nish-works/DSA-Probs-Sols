#include <bits/stdc++.h>
using namespace std;

// TC: Theta(2^n) where n is length of the string
// AS: Theta(2^n)
void printSubsets(string str, string curr, int index)
{
    if (index > str.length() - 1)
    {
        cout << curr << " ";
        return;
    }
    printSubsets(str, curr, index + 1);
    printSubsets(str, curr + str[index], index + 1);
}

int main()
{
    string str, curr = "";
    int index = 0;
    cin >> str;
    printSubsets(str, curr, index);
    return 0;
}
