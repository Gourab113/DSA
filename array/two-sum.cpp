// 1. Two Sum  comp < o(n^2)

// To create a pair, use make_pair(a,b) instead of {a,b}
// because {a,b} we don't give any type of pair
// Inside lower bound make_pair(a,b) works
// or can use pair<int,int>p = {a,b}

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    vector<pair<int, int>> v;

    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
      v.push_back({nums[i], i});
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < nums.size(); i++)
    {
      int rem = target - nums[i];
      pair<int, int> p = {rem, 0};

      auto it = lower_bound(v.begin(), v.end(), p);
      if (it == v.end())
      {
        continue;
      }

      int val = it->first;
      int ind = it->second;

      if (val == rem && ind != i)
      {
        ans.push_back(ind);
        ans.push_back(i);
        return ans;
      }
    }

    return ans;
  }
};