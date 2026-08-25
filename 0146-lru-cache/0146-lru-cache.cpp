class Node{
    public:
        int key;
        int value;
        Node* next;
        Node* prev;
        Node(int key,int value){
            this->key=key;
            this->value=value;
            next=nullptr;
            prev=nullptr;
        }

};


class LRUCache {
public:
    int capacity;
    unordered_map<int,Node*> m;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    LRUCache(int capacity) {
        this->capacity=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    Node* add(Node* n){
            n->next=head->next;
            head->next->prev=n;
            head->next=n;
            n->prev=head;
            return n;            
        }
    int deletes(Node* n){
            // tail->prev->next=NULL;
            // tail->prev->prev=NULL;
            // tail->prev->prev->next=tail;
            // tail->prev=tail->prev->prev;
            n->next->prev=n->prev;
            n->prev->next=n->next;
            n->next=NULL;
            n->prev=NULL;
            
            return n->key;          
        }

    int get(int key) {
        if(m.find(key)!=m.end()){
            Node* res=m[key];
            int a=deletes(m[key]);
         
            res=add(res);
        
            return m[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.size()<capacity && m.find(key)==m.end()){
            Node* res=new Node(key,value);
            res=add(res);
            m[key]=res;
        }
        else if(m.find(key)!=m.end()){
            Node* res=m[key];
            int a=deletes(res);
            m.erase(key);
            res->value=value;
            res=add(res);
            m[key]=res;
        }
        else if(m.size()>=capacity){
            int k=deletes(tail->prev);
            m.erase(k);
            Node* res=new Node(key,value);
            res=add(res);
            m[key]=res;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */