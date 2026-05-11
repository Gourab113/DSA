// Gourab
// Sri krishna

// 11-05-2026, 8:25 AM

// Cycle detection in linked list

// Leetcode Linked list cycle

// As n<= 10^4 we can solve it broute force

/*
        ListNode* temp = head;

        int ct =0;

        while(temp != nullptr && ct< 10010){
            ct++;
            temp = temp->next;
        }

        return ct >= 10010;

*/

// But also an algorithm: for learning

// Floy'ds cycle finding algorithm:

// Slow pointer and fast pointer, the fast pointer moves two steps at a time
// slow pointer moves one step at a time

/*

        while(temp != nullptr){


            temp = temp->next;
            i++;

            if(i==2){
                i=0;
                slow= slow->next;
            }

            if(temp == slow){
                    tr=1;
                    break;
            }

        }

*/
