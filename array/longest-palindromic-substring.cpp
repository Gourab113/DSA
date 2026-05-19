// 5. Longest Palindromic Substring
// s(i to j) is palindrome if s(i+1, j-1) is palindrome
// we can use 2d array instead of map

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int dp[1005][1005];
  string longestPalindrome(string s)
  {

    for (int i = 0; i < 1005; i++)
    {
      for (int j = 0; j < 1005; j++)
      {
        dp[i][j] = 0;
      }
    }

    string ans = s.substr(0, 1);
    int ii = 0;
    int jj = 0;
    int mx = 1;

    for (int i = 0; i < s.size(); i++)
    {
      for (int j = i - 1; j >= 0; j--)
      {
        int df = i - j + 1;
        if (df <= 3)
        {
          if (s[i] == s[j])
          { // palindrome
            dp[j][i] = 1;
          }
          else
          {
            dp[j][i] = 0;
          }
        }
        else
        {
          if (s[i] == s[j])
          {
            dp[j][i] = dp[j + 1][i - 1];
          }
          else
          {
            dp[j][i] = 0;
          }
        }

        if (dp[j][i] == 1)
        {
          int df = (i - j + 1);
          if (df > mx)
          {
            mx = df;
            ii = i;
            jj = j;
          }
        }
      }
    }

    ans = s.substr(jj, mx);

    return ans;
  }
};