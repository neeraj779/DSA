#include <bits/stdc++.h>
bool checkPalindrome(string str)
{
    // Write your code here.
    int s = 0;
    int e = str.length() - 1;
    while (s <= e)
    {
        if (!isalnum(str[s]))
            s++;
        else if (!isalnum(str[e]))
            e--;
        else
        {
            if (tolower(str[s]) != tolower(str[e]))
                return false;

            s++;
            e--;
        }
    }
    return true;
}

