// Gourab
// Sri krishna

// 11-5-2026

// Merge Two Sorted Lists
// Given two sorted list, merge them and make one sorted list

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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
  {

    ListNode *head = nullptr;
    ListNode *temp;

    while (list1 != nullptr || list2 != nullptr)
    {
      if (list1 == nullptr)
      {
        if (head == nullptr)
        {
          head = list2;
          temp = list2;
        }
        else
        {
          temp->next = list2;
          temp = list2;
        }

        list2 = list2->next;
      }
      else if (list2 == nullptr)
      {

        if (head == nullptr)
        {
          head = list1;
          temp = list1;
        }
        else
        {
          temp->next = list1;
          temp = list1;
        }

        list1 = list1->next;
      }
      else
      {
        if (list1->val < list2->val)
        {
          if (head == nullptr)
          {
            head = list1;
            temp = list1;
          }
          else
          {
            temp->next = list1;
            temp = list1;
          }
          list1 = list1->next;
        }
        else
        {
          if (head == nullptr)
          {
            head = list2;
            temp = list2;
          }
          else
          {
            temp->next = list2;
            temp = list2;
          }

          list2 = list2->next;
        }
      }
    }

    return head;
  }
};