#include <bits/stdc++.h>

int findMinimumCost(const string &str)
{
    // Check if the length of the string is odd
    if (str.length() & 1)
        return -1;

    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '{')
            s.push(ch);
        else
        {
            // ch is a closed brace so look for a matching open brace
            if (!s.empty() && s.top() == '{')
            {
                s.pop();
            }
            else
            {
                s.push(ch);
            }
        }
    }

    // Calculate the minimum cost
    int openBraces = 0, closedBraces = 0;
    while (!s.empty())
    {
        if (s.top() == '{')
            openBraces++;
        else
            closedBraces++;
        s.pop();
    }

    return ((openBraces + 1) / 2 + (closedBraces + 1) / 2);
}
