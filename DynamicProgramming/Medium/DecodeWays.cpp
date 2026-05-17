// Leetcode: 91. Decode Ways

// decode string to A to Z, find number of ways
/// dp[i] = dp[i-1] + dp[i-2];  // take one character or two character

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool hasLeadingZero(string s)
  {
    int p = 0;

    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == '0' && p == 0)
      {
        return true;
      }
      else
      {
        return false;
      }
    }
    return true;
  }

  bool isValid(char prev, char curr)
  {

    if (prev == '1')
      return true;
    if (prev == '2' && curr <= '6')
      return true;
    return false;
  }
  int numDecodings(string s)
  {

    if (hasLeadingZero(s))
      return 0;

    vector<int> dp(s.size() + 5, 0);

    if (s.size() <= 1)
      return s.size();

    for (int i = 0; i < s.size(); i++)
    {
      if (i == 0)
      {
        dp[i] = 1;
      }
      else
      {
        // single character
        int sing = 0;
        if (s[i] != '0')
        {
          sing = dp[i - 1];
        }

        // double character
        int db = 0;

        if (s[i - 1] != '0')
        {

          if (isValid(s[i - 1], s[i]))
          {
            db = 1;
            if (i - 2 >= 0)
            {
              db = dp[i - 2];
            }
          }
        }

        dp[i] = sing + db;
      }
    }
    return dp[s.size() - 1];
  }
};