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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head==NULL || k==1) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        
        int count=0;
        
        ListNode* pre=dummy,*cur=dummy,*nex=dummy,*t=head;
        
        while(t!=NULL){
            t=t->next;
            count++;
        }
        
        while(count>=k){
            cur=pre->next;  //always at start of every new subgroup
            nex=cur->next; //always 2nd in subgroup 
            for(int i=1; i<k; i++){
                cur->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=cur->next;
            }
            pre=cur;
            count-=k;
        }
        
        return dummy->next;
    }
};