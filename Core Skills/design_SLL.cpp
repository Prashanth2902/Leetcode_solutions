#include<bits/stdc++.h>
using namespace std;


class Node {
    public:
        int val;
        Node* next;

        Node(int val): val(val), next(nullptr) {}
        Node(int val, Node* next): val(val), next(next) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList() {
        head = new Node(-1);
        tail = head;
    }

    int get(int index) {
        Node* curr = head->next;
        int i=0;
        while(curr != nullptr) {
            if(i==index) return curr->val;
            i++;
            curr = curr->next;
        }
        return -1;
    }

    void insertHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head->next;
        head->next = newNode;
        if(newNode->next == nullptr) tail = newNode;
    }
    
    void insertTail(int val) {
        Node* newNode = new Node(val);
        tail->next = newNode;
        tail = tail->next;
    }

    bool remove(int index) {
        int i=0;
        Node* curr = head;
        while(i < index && curr != nullptr){
            curr = curr->next;
            i++;
        }
        if(curr != nullptr && curr->next != nullptr) {
            if (curr->next == tail){
                tail = curr;
            }
            Node* toDelete = curr->next;
            curr->next = curr->next->next;
            delete toDelete;
            return true;
        }
        return false;
    }

    vector<int> getValues() {
        vector<int> res;
        Node* curr = head->next;
        while(curr != nullptr) {
            res.push_back(curr->val);
            curr = curr->next;
        }
        return res;
    }
};
