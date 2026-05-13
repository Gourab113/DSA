// Word Break, leetcode
// Gourab, Sri krishna, 13/5/2026

// Given a string, and a list of words
// Check if the stricg can be made using the words
// a word can be used multiple times or not used

// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true

// 1 <= s.length <= 300
// 1 <= wordDict.length <= 1000
// 1 <= wordDict[i].length <= 20

// solution: for i the position check by using the words if till i th the string can be made
// if made then make dp[i] = 1;
// for any other words if dp[i - words.size()] == 1 , then dp[i] = 1 if the word match with s characters

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int dp[305];
  bool wordBreak(string s, vector<string> &wordDict)
  {

    for (int i = 0; i < s.size(); i++)
    {
      for (int j = 0; j < wordDict.size(); j++)
      {

        if (i + 1 >= wordDict[j].size())
        {
          int c = i;
          int ne = 0;
          for (int k = wordDict[j].size() - 1; k >= 0; k--)
          {

            cout << wordDict[j][k];
            if (wordDict[j][k] != s[c])
            {
              ne = 1;
              break;
            }
            c--;
          }
          cout << ne << " " << c << endl;
          cout << endl;

          if (ne == 0 && (c < 0 || (c >= 0 && dp[c] == 1)))
          {
            dp[i] = 1;
          }
        }
      }

      cout << i << " " << dp[i] << endl;
    }

    return dp[s.size() - 1] == 1;
  }
};