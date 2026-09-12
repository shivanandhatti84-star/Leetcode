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

class Compare{
    public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val>b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* a=new ListNode();
        ListNode* b=a;
        priority_queue<ListNode*,vector<ListNode*>,Compare> pq;
        for(auto list:lists){
            if(list!=NULL){
                pq.push(list);
            }
        }
        while(!pq.empty()){
            auto l=pq.top();
            pq.pop();
            a->next=l;
            a=a->next;
            if(l->next!=NULL){
                pq.push(l->next);
            }

        }
        return b->next;
    }
};