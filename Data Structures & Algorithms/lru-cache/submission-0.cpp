class Node{
    public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int key, int value){
            this->key = key;
            this->value = value;
            prev = nullptr;
            next = nullptr;
        }
};

class DDL{
    public:
        Node* head;
        Node* tail;

        DDL(){
            Node* newHeadNode = new Node(-1, -1);
            Node* newTailNode = new Node(-1, -1);

            head = newHeadNode;
            tail = newTailNode;
            head->next = tail;
            tail->prev = head;
        }

        void insertAfterHead(Node* node){
            Node* afterHead = head->next;
            head->next = node;
            node->prev = head;
            
            node->next = afterHead;
            afterHead->prev = node;
        }

        Node* deleteNode(Node* node){
            Node* prev = node->prev;

            prev->next = node->next;
            node->next->prev = prev;

            return node;
        }
};

class LRUCache {
public:
    int capacity;
    DDL* doublyLinkedList;
    unordered_map<int, Node*> hash;

    LRUCache(int capacity) {
        this->capacity = capacity;
        doublyLinkedList = new DDL();
    }
    
    int get(int key) {
        if(hash.find(key) != hash.end()){
            Node* ans = hash[key];
            ans = doublyLinkedList->deleteNode(ans);
            doublyLinkedList->insertAfterHead(ans);

            return ans->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(hash.find(key) != hash.end()){
            Node* ans = hash[key];
            ans->value = value;
            ans = doublyLinkedList->deleteNode(ans);
            doublyLinkedList->insertAfterHead(ans);

            return;
        }
        Node* newNode = new Node(key, value);

        if(hash.size() >= capacity){
            Node* toBeDeleted = doublyLinkedList->deleteNode(doublyLinkedList->tail->prev);
            hash.erase(toBeDeleted->key);
        }
        doublyLinkedList->insertAfterHead(newNode);
        hash[key] = newNode;
    }
};
