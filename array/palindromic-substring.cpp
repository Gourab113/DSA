
// 647. Palindromic Substrings

// find the number of palindromic substring

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int dp[1005][1005];

  int countSubstrings(string s)
  {

    for (int i = 0; i < s.size(); i++)
    {
      for (int j = 0; j < s.size(); j++)
      {
        dp[i][j] = 0;
      }
    }

    int ans = 0;

    for (int i = 0; i < s.size(); i++)
    {
      for (int j = i; j >= 0; j--)
      {

        int len = i - j + 1;

        if (len == 1)
        {
          dp[j][i] = 1;
          ans++;
        }
        else if (len <= 3)
        {
          if (s[i] == s[j])
          {
            dp[j][i] = 1;
            ans++;
          }
        }
        else
        {
          if (s[i] == s[j] && dp[j + 1][i - 1] == 1)
          {
            dp[j][i] = 1;
            ans++;
          }
        }
      }
    }

    return ans;
  }
};