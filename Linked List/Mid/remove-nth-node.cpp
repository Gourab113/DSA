// Remove Nth node from the end
// Remove Nth Node from End of list leetcode

// Gourab
// 11/5/2026 - 10:20 PM

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
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {

    int ct = 0;

    ListNode *temp = head;

    while (temp != nullptr)
    {
      temp = temp->next;
      ct++;
    }

    int tot = ct;

    int rm = ct - n + 1;

    temp = head;
    ListNode *prev = head;

    ct = 0;

    while (temp != nullptr)
    {
      ct++;
      if (ct == rm)
      {
        if (ct == 1)
        {
          head = head->next;
          break;
        }
        else
        {
          prev->next = temp->next;
          break;
        }
      }

      prev = temp;
      temp = temp->next;
    }

    return head;
  }
};
