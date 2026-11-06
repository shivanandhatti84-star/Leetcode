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
    ListNode* mergeList(ListNode* left,ListNode* right){
        ListNode dummy(0);
        ListNode* list=&dummy;
        while(left!=NULL  && right!=NULL){
            if(left->val<=right->val){
                list->next=left;
                left=left->next;
            }
            else{
                list->next=right;
                right=right->next;
            }
            list=list->next;
        }
        list->next=(left!=NULL)?left:right;
        return dummy.next;
    }
    ListNode* splitList(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* second=slow->next;
        slow->next=NULL;
        return second;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* second=splitList(head);
        ListNode* left=sortList(head);
        ListNode* right=sortList(second);
        return mergeList(left,right);
    }
};