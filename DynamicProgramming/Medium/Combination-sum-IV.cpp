// GIven some numbers nums = [1,2,3]
//  target = 4;
//  find the number of ways to use these numbers to generate the target value
// dp[0] =1;
/// foreach val of nums
/// dp[i] += dp[i- val]

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int dp[1005];
  int combinationSum4(vector<int> &nums, int target)
  {

    for (int i = 0; i <= target; i++)
    {
      dp[i] = 0;
    }

    dp[0] = 1;
    for (int i = 1; i <= target; i++)
    {
      for (int j = 0; j < nums.size(); j++)
      {
        if (i - nums[j] >= 0)
        {
          dp[i] += dp[i - nums[j]];
        }
      }
    }

    return dp[target];
  }
};