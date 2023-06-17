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
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* t=head;
        int size=0;
        
        while(t!=NULL){
            size++;
            t = t->next;
        }
        
        if(size == n){
head = head->next;
return head;
}
        int res = size - n;
       
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(res-- && temp != NULL){
            prev=temp;
           temp = temp->next; 
        }
        
        prev->next = temp->next;
        temp->next=NULL;
        return head;
        
    }
};