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


int findMinimumCost(const string& s) {
  // Check if the length of the string is odd
  if (s.size() & 1)
    return -1;
  
  int open = 0; 
  int close = 0; 

  for (char t : s) {
    if (t == '{') {
      open++; // Increment open count for each opening brace encountered
    } else {
      if (open > 0) {
        open--; // Match an opening brace with a closing brace
      } else {
        close++; // Increment close count for each unmatched closing brace
      }
    }
  }

  // Calculate the minimum number of reversals required
  int minReversals = (open + 1) / 2 + (close + 1) / 2;

  return minReversals;
}
