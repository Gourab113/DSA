// Gourab
// Sri krishna
// 11-5-2026, 9:40 PM

// Merge k Sorted Lists leetcode
//  Merge k sorted list into one sorted list

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {

    ListNode *head = nullptr;
    ListNode *temp = nullptr;

    int ft = 0;

    while (1)
    {
      int x = -1;
      int take = 0;
      int check = 0;
      for (int i = 0; i < lists.size(); i++)
      {

        if (lists[i] != nullptr)
        {
          check = 1;

          if (x == -1)
          {
            x = i;
            take = lists[i]->val;
          }
          else if (lists[i]->val < take)
          {
            take = lists[i]->val;
            x = i;
          }
        }
      }

      if (check == 0)
        break;

      if (ft == 0)
      {
        head = lists[x];
        temp = head;
        ft = 1;
      }
      else
      {
        temp->next = lists[x];
        temp = temp->next;
      }

      lists[x] = lists[x]->next;
    }

    return head;
  }
};
