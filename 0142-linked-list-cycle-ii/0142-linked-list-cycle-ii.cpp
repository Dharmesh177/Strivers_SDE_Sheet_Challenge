/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
           //    Write your code here.

   ListNode* slow = head;

    ListNode* fast = head;

 

    

     while  (fast != NULL && fast->next != NULL){

        fast = fast->next->next;

        slow = slow->next;

          if (slow == fast) {

            fast = head;

            while (slow != fast) {

                slow = slow->next;

                fast = fast->next;

            }

            return slow;  // First node of the cycle

        }

    }

    return NULL;
    }
};