// 3sum leetcode

// find triples sum = 0, i,j,j not equal, and unique triples
/// 1,3,4 and 3,4,1 are not unique

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {

    sort(nums.begin(), nums.end());

    map<pair<int, int>, int> mp;

    vector<vector<int>> ans;

    map<int, int> mmp;

    for (int i = 0; i < nums.size(); i++)
    {
      mmp[nums[i]]++;
    }

    for (int i = 0; i < nums.size(); i++)
    {
      for (int j = i + 1; j < nums.size(); j++)
      {
        int nmk = -1 * (nums[i] + nums[j]);

        if (mp[{nums[i], nums[j]}] == 1)
          continue;

        mp[{nums[i], nums[j]}] = 1;

        if (nmk > nums[j])
        {
          auto it = lower_bound(nums.begin(), nums.end(), nmk);
          if (it != nums.end() && *it == nmk)
          {
            vector<int> v = {nums[i], nums[j], nmk};
            ans.push_back(v);
          }
        }
        else if (nmk == nums[j] && nmk == nums[i])
        {
          if (mmp[nmk] > 2)
          {
            vector<int> v = {nums[i], nums[j], nmk};
            ans.push_back(v);
          }
        }
        else if (nmk == nums[j])
        {
          if (mmp[nmk] > 1)
          {
            vector<int> v = {nums[i], nums[j], nmk};
            ans.push_back(v);
          }
        }
        else
        {
          break;
        }
      }
    }

    return ans;
  }
};