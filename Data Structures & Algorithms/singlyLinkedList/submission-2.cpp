class Node {
    public:
        int data;
        Node* next;

        Node(int v){
            data = v;
            next = nullptr;
        }
};

class LinkedList {

private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    int get(int index) {
        Node* cur = head;
        int currIdx = 0;
        while(cur != nullptr){
            if(currIdx == index){
                return cur->data;
            }
            cur = cur->next;
            currIdx++;
        }
        return -1;
    }

    void insertHead(int val) {
        Node* newHead = new Node(val);
        if(head == nullptr){
            head = newHead;
            return;
        }
        newHead->next = head;
        head = newHead;
        return;
    }
    
    void insertTail(int val) {
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = newNode;
            return;
        }
        Node* cur = head;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = newNode;
        return;

    }

    bool remove(int index) {
        if(head == nullptr){
            return false;
        }
        
        if (index == 0) {
        Node* nodeToDelete = head;
        head = head->next; 
        delete nodeToDelete; 
        return true;
    }

        Node* prev = nullptr;
        Node* cur = head;
        int currIdx = 0;

        while(cur != nullptr ){
            if(currIdx == index){
                prev->next = cur->next;
                delete cur;
                return true;
            }
            prev = cur;
            cur = cur->next;
            currIdx++;
        }
        return false;
    }

    vector<int> getValues() {
        vector<int> ans;
        Node* cur = head;
        while(cur != nullptr){
            ans.push_back(cur->data);
            cur = cur->next;
        }
        return ans;
    }
};
