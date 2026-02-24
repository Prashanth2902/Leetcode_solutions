#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Hard
 * Problem - 460. LFU Cache
 * Link -> https://leetcode.com/problems/lfu-cache/description/
 */

class LFUCache {
private:
    struct Node{
        int val;
        Node* prev;
        Node* next;
        Node(int val): val(val), prev(nullptr), next(nullptr) {}
        Node(int val, Node* prev, Node* next): val(val), prev(prev), next(next) {}
    };

    struct LinkedList {
        Node* left;
        Node* right;
        unordered_map<int, Node*> mapper;

        LinkedList() {
            left = new Node(0);
            right = new Node(0);
            left->next = right;
            right->prev = left;
        }

        int length() {
            return mapper.size();
        }

        void insert(int val) {
            Node* node = new Node(val, right->prev, right);
            mapper[val] = node;
            right->prev->next = node;
            right->prev = node;
        }

        void remove(int val) {
            if(mapper.count(val)) {
                Node* node = mapper[val];
                Node* prevNode = node->prev;
                Node* nextNode = node->next;
                prevNode->next = nextNode;
                nextNode->prev = prevNode;
                mapper.erase(val);
                delete node;
            }
        }

        int removeLeft() {
            int res = left->next->val;
            remove(res);
            return res;
        }

        void update(int val) {
            remove(val);
            insert(val);
        }
    };

int capacity;
int lfuCount;
unordered_map<int, int> valMap, countMap;
unordered_map<int, LinkedList*> listMap;

void counter(int key) {
    int count = countMap[key];
    countMap[key] = count + 1;

    listMap[count]->remove(key);

    if(!listMap.count(count+1)) {
        listMap[count + 1] = new LinkedList();
    }
    listMap[count + 1]->insert(key);

    if(count == lfuCount && listMap[count]->length() == 0) lfuCount++;
}

public:
    LFUCache(int capacity) {
        listMap[0] = new LinkedList();
        this->capacity = capacity;
        lfuCount = 0;
    }
    
    int get(int key) {
        if(valMap.count(key)) {
            counter(key);
            return valMap[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;
        if(!valMap.count(key) && valMap.size() == capacity) {
            int toRemove = listMap[lfuCount]->removeLeft();
            valMap.erase(toRemove);
            countMap.erase(toRemove);
        }
        valMap[key] = value;
        if(!countMap.count(key)) {
            countMap[key] = 0;
            listMap[0]->insert(key);
            lfuCount = 0;
        }
        counter(key);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */