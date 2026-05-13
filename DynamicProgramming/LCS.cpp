// Gourab, 13/5/2026 9:37 PM

// Longest Common Subsequence, Dynamic Programming, leetcode 1143

// if x[i] == y[j],  dp[i][j] =  1 + dp[i-1][j-1];
// else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

#include <bits/stdc++.h>
using namespace std;
int main()
{

  vector<vector<int>> dp(1005, vector<int>(1005, 0));

  string x, y;

  cin >> x >> y;

  int ans = 0;

  // Use +1 starting index for dp

  for (int i = 0; i < x.size(); i++)
  {
    for (int j = 0; j < y.size(); j++)
    {
      if (x[i] == y[j])
      {
        dp[i + 1][j + 1] = 1 + dp[i][j];
      }
      else
      {
        dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
      }

      ans = max(ans, dp[i + 1][j + 1]);
    }
  }

  cout << ans << endl;
}