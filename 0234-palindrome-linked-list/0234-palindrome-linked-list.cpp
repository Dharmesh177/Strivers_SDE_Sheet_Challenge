/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* reverseLL(ListNode *curr){
    ListNode *prev = NULL;
   ListNode *nextt = NULL;
  while(curr!=NULL){
      nextt = curr->next;
      curr->next=prev;
      prev=curr;
      curr=nextt;
  }
  return prev;
}
public:
    bool isPalindrome(ListNode* head) {
         if(head==NULL || head->next==NULL) return true;

    ListNode *slow=head;
    ListNode *fast=head;

    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }

    slow->next = reverseLL(slow->next);
    slow=slow->next;
    ListNode *dummy = head;

    while(slow!=NULL){
        if(dummy->val != slow->val){
            return false;
        }
        slow=slow->next;
        dummy=dummy->next;
    }
    return true;
    }
};