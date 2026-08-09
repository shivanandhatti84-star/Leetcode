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
    ListNode* man(ListNode* first,int k){
        while(first!=NULL && k-1!=0){
            k--;
            first=first->next;
        }
        if(k-1==0){
            return first;
        }
        else{
            return NULL;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL){
            return head;
        }
        ListNode* first=head;
        ListNode* pr=NULL;
        bool fir=true;
        while(true){
            ListNode* kth=man(first,k);
            if(!kth) break;
            ListNode* nn=kth->next;
            kth->next=NULL;
            if(pr) pr->next=NULL;
            ListNode* prev=NULL;
            ListNode* ff=first;
            for(int i=0;i<k;i++){
                ListNode* nnn=first->next;
                first->next=prev;
                prev=first;
                first=nnn;
            }
            if(fir){
                head=prev;
                fir=false;
            }
            if(pr) pr->next=prev;
            pr=ff;
            ff->next=nn;
            first=nn;
           
        }
        return head;
    }
};