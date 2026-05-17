// Leetcode: 198. House Robber

// can't rob two adjacent house at a time, get maximum money

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int rob(vector<int> &nums)
  {
    vector<int> dp(nums.size(), 0);
    int mx = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (i == 0)
      {
        dp[i] = nums[i];
      }
      else if (i == 1)
      {
        dp[i] = max(nums[0], nums[1]);
      }
      else
      {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
      }
      mx = max(mx, dp[i]);
    }

    return mx;
  }
};