class Node {
public:
    int key, val;
    Node* next;
    Node* prev;
    Node(){
        key = val = -1;
        prev = next = NULL;
    }

    Node(int key_, int val_){
        key = key_;
        val = val_;
        prev = next = nullptr;
    }
};

class LRUCache {
public:
    unordered_map<int,Node*> mp;
    int cap;
    Node* head;
    Node* tail;

    void delNode(Node* node){
        Node* nextNode = node->next;
        Node* prevNode = node->prev;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAfterHead(Node* node){
        Node* currAfterHead = head->next;
        head->next = node;
        node->next = currAfterHead;
        currAfterHead->prev = node;
        node->prev = head;
    }

    LRUCache(int capacity) {
        cap = capacity;
        mp.clear();
        head = new Node();
        tail = new Node();

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        Node* node = mp[key];
        int val = node->val;
        delNode(node);
        insertAfterHead(node);
        return val;
    }
    
    void put(int key_, int value_) {
        if(mp.find(key_) != mp.end()){
            Node* node = mp[key_];
            node->val = value_;
            delNode(node);
            insertAfterHead(node);
            return;
        }else{
            if(mp.size() == cap){
                Node* node = tail->prev;
                mp.erase(node->key);
                delNode(node);
            }
            Node* newNode = new Node(key_, value_);
            mp[key_] = newNode;
            insertAfterHead(newNode);
        }
    }
};
