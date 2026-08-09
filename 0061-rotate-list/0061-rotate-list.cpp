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
    ListNode* rotateRight(ListNode* head, int k) {
        if( head==NULL||k==0) return head;
        int count=1;
        ListNode* fast=head;
        while(fast->next!=NULL){
            fast=fast->next;
            count++;
        }
        k=k%count;
        if(k==0) return head;
        ListNode* slow=head;
        ListNode* prev=NULL;
        for(int i=1;i<=count-k;i++){
            prev=slow;
            slow=slow->next;
        }
    fast->next=head;
    prev->next=NULL;
    return slow;
    }
};