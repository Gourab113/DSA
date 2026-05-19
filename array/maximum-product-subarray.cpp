
/// leetcode : 152. Maximum Product Subarray

// an array have values 0, negative, positive,
// return the subarray which product is maximum]

// use divide and concure approach
//  divide the problem into subproblem then merge the solution
// divide and conquer:
// divide: divide the problem into smaller subproblem
// conquer: solve each subproblem
// combine: combine the smaller solutions to make the larger solutions

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int find(vector<int> nums, int st, int en)
  {

    if (st == en)
    {
      return nums[st];
    }

    for (int i = st; i <= en; i++)
    {
      if (nums[i] == 0)
      {

        int val;
        if (i == st)
        {
          val = find(nums, st + 1, en);
        }
        else if (i == en)
        {
          val = find(nums, st, en - 1);
        }
        else
        {
          val = max(find(nums, st, i - 1), find(nums, i + 1, en));
        }

        return max(0, val);
      }
    }

    // not have any zero

    int p = 1;
    for (int i = st; i <= en; i++)
    {
      p = p * nums[i];
    }
    if (p > 0)
      return p;

    p = 1;

    int gt = 0;

    for (int i = st; i <= en; i++)
    {
      if (gt == 0 && nums[i] < 0)
      {
        gt = 1;
      }
      else if (gt == 1)
      {
        p = p * nums[i];
      }
    }

    int left = p;

    p = 1;
    gt = 0;

    for (int i = en; i >= st; i--)
    {
      if (gt == 0 && nums[i] < 0)
      {
        gt = 1;
      }
      else if (gt == 1)
      {
        p = p * nums[i];
      }
    }

    int right = p;

    return max(left, right);
  }

  int maxProduct(vector<int> &nums)
  {

    return find(nums, 0, nums.size() - 1);
  }
};