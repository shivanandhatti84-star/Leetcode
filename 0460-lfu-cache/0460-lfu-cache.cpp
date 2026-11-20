class Node{
    public:
    int value;
    int key;
    Node* next;
    Node* prev;
    int cnt;
    Node(int key,int value){
        this->key=key;
        this->value=value;
        next=nullptr;
        cnt=1;
        prev=nullptr;
    }
};
class List{
    public:
    int size;
    Node* head;
    Node* tail;
    List(){
        this->size=0;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    void add(Node* n){
        n->next=head->next;
        n->prev=head;
        head->next->prev=n;
        head->next=n;
        size++;
    }
    void remove(Node *n){
        n->next->prev=n->prev;
        n->prev->next=n->next;
        n->next=NULL;
        n->prev=NULL;
        size--;
    }

};

class LFUCache {
public:
    unordered_map<int,List*> freq;
    unordered_map<int,Node*> keyl;
    int cap;
    int min_freq;
    
    LFUCache(int capacity) {
        cap=capacity;
        min_freq=0;
        
    }
    void updateList(Node* node){
        keyl.erase(node->key);
        freq[node->cnt]->remove(node);
        if(min_freq==node->cnt && freq[min_freq]->size==0){
            min_freq++;
        }
        List* nexthigh=new List();
        if(freq.find(node->cnt+1)!=freq.end()){
            nexthigh=freq[node->cnt+1];
        }
        node->cnt+=1;
        nexthigh->add( node);
        keyl[node->key]=node;
        freq[node->cnt]=nexthigh;
    }
    
    int get(int key) {
        if(keyl.find(key)!=keyl.end()){
            Node* res=keyl[key];
            updateList(res);
            return res->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cap==0) return ;
        if(keyl.find(key)!=keyl.end()){
            Node* res=keyl[key];
            res->value=value;
            updateList(res);
        }
        else{
            if(cap==(int)keyl.size()){
                List* list=freq[min_freq];
                keyl.erase(list->tail->prev->key);
                freq[min_freq]->remove(list->tail->prev);
            }
            min_freq=1;
            List* list=new List();
            if(freq.find(min_freq)!=freq.end()){
                list=freq[min_freq];
            }
            Node* res=new Node(key,value);
            keyl[key]=res;
            list->add(res);
            freq[min_freq]=list;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */