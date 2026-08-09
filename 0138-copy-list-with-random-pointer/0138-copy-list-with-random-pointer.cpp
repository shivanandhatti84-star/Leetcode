/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node* temp=head;
        while(temp!=NULL){
            Node* copy=new Node(temp->val);
            copy->next=temp->next;
            temp->next=copy;
            temp=copy->next;
        }
        temp=head;
        while(temp!=NULL){
            if(temp->random!=NULL) temp->next->random=temp->random->next;
            temp=temp->next->next;
        }
        temp=head;
        Node* copy=head->next;
        Node* c=copy;
        while(temp != NULL) {

            // Restore original list
            temp->next = c->next;

            // Move original pointer
            temp = temp->next;

            // Set copy's next pointer
            if(temp != NULL) {
                c->next = temp->next;
                c = c->next;
            }
        }

        return copy;
    }
    
};