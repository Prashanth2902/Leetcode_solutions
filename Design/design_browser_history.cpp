#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Medium
 * Problem - 1472. Design Browser History
 * Link -> https://leetcode.com/problems/design-browser-history/description/
 * 
 * Logic:-
 * Use a DLL to navigate the browser
 */

class Node {
public:
    string website;
    Node* prev;
    Node* next;

    Node(string website) {
        this->website = website;
        this->prev = nullptr;
        this->next = nullptr; 
    }

    Node(string website, Node* prev, Node* next) {
        this->website = website;
        this->prev = prev;
        this->next = next; 
    }
};

class BrowserHistory {
private:
    Node* curr;
    int count;

public:
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
        count = 1;
    }
    
    void visit(string url) {
        if(curr->next) {
            curr->next = nullptr;
        }
        curr->next = new Node(url, curr, nullptr);
        curr = curr->next;
        count++;
    }
    
    string backHelper(int x) {
        while(curr->prev && x > 0) {
            curr = curr->prev;
            x--;
        }
        return curr->website;
    }

    string back(int steps) {
        if(count < steps) {
            return backHelper(count);
        } else {
            return backHelper(steps);
        }
    }
    
    string forwardHelper(int x) {
        while(curr->next && x > 0) {
            curr = curr->next;
            x--;
        }
        return curr->website;
    }

    string forward(int steps) {
        if(count < steps) {
            return forwardHelper(count);
        } else {
            return forwardHelper(steps);
        }
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */