#include "defines.h"

class LRUCache {
public:
    struct Node {
        int key = 0;
        int value = 0;
        Node* prev = nullptr;
        Node* next = nullptr;
    };

    // map<int, Node*> index;
    Node *index[10010];
    Node* head = new Node();
    int cap;
    int size;

    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        head->prev = head;
        head->next = head;
        for (int i = 0; i < 10010; i++) {
            index[i] = nullptr;
        }
    }

    void del(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        // node->next = node;
        // node->prev = node;
    }

    void ins(Node *node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    
    int get(int key) {
        if (index[key] != nullptr) {
            Node* node = index[key];
            del(node);
            ins(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (index[key] != nullptr) {
            Node* node = index[key];
            node->value = value;
            del(node);
            ins(node);
        } else {
            Node* node;
            if (size == cap) {
                node = head->prev;
                index[node->key] = nullptr;
                del(node);
            } else {
                node = new Node();
                size++;
            }
            index[key] = node;
            node->key = key;
            node->value = value;
            ins(node);
        }
    }
};

int main() {
    LRUCache c(2);
    c.put(1, 1);
    c.put(2, 2);
    cout << c.get(1) << endl;
    c.put(3, 3);
    cout << c.get(2) << endl;
    c.put(4, 4);
    cout << c.get(1) << endl;
    cout << c.get(3) << endl;
    cout << c.get(4) << endl;
}