// Gourab
//  12-5-2026

// Reorder List, leetcode

// Reorder linked list  1-2-3-4-5 to 1-5-2-4-3

// Use dequeue: push_front(), push_back(),
//  dequeue: front(), back() -> get data
//  dequeue: pop_front(), pop_back() -> pop data

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
  void reorderList(ListNode *head)
  {
    deque<ListNode *> dq;

    ListNode *temp = head;

    ListNode *lef = nullptr;
    ListNode *rit = nullptr;

    while (temp != nullptr)
    {
      dq.push_back(temp);
      temp = temp->next;
    }

    temp = nullptr;

    while (!dq.empty())
    {

      lef = dq.front();

      dq.pop_front();

      if (temp != nullptr)
      {
        temp->next = lef;
      }

      temp = lef;
      temp->next = nullptr;

      if (!dq.empty())
      {
        rit = dq.back();

        dq.pop_back();
        temp->next = rit;
        temp = rit;
        temp->next = nullptr;
      }
    }

    return;
  }
};