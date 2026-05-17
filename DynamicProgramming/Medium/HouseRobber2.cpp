

// leetcode 213. House Robber II

// can't rob two adjacent house at a time, Houses are arranged in a circle
// It it better to use function, make tasks divide into smaller tasks
// write code in multiple functions, instead of same file, it is required

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int res(vector<int> nums, int st, int en)
  {
    vector<int> v1(nums.size(), 0);
    int mx = 0;
    for (int i = st; i <= en; i++)
    {
      if (i == st)
      {
        v1[i] = nums[i];
      }
      else if (i == st + 1)
      {
        v1[i] = max(nums[i], nums[i - 1]);
      }
      else
      {
        v1[i] = max(nums[i] + v1[i - 2], v1[i - 1]);
      }
      mx = max(mx, v1[i]);
    }

    return mx;
  }
  int rob(vector<int> &nums)
  {
    int n = nums.size();

    if (n == 1)
    {
      return nums[0];
    }
    if (n == 2)
    {
      return max(nums[0], nums[1]);
    }

    int rs1 = res(nums, 0, n - 2);
    int rs2 = res(nums, 1, n - 1);

    return max(rs1, rs2);
  }
};