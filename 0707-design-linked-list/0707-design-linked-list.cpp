class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int x) : val(x), next(nullptr) {}
    };

    Node* dummy;
    int size;

public:
    MyLinkedList() {
        dummy = new Node(0);
        size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        
        Node* curr = dummy->next;
        for (int i = 0; i < index; ++i) {
            curr = curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0) index = 0;
        if (index > size) return;
        
        Node* curr = dummy;
        for (int i = 0; i < index; ++i) {
            curr = curr->next;
        }
        
        Node* newNode = new Node(val);
        newNode->next = curr->next;
        curr->next = newNode;
        
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        
        Node* curr = dummy;
        for (int i = 0; i < index; ++i) {
            curr = curr->next;
        }
        
        Node* toDelete = curr->next;
        curr->next = toDelete->next;
        delete toDelete;
        
        size--;
    }
};