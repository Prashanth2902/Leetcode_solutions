#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Hard
 * Problem - 295. Find Median from Data Stream
 * Link -> https://leetcode.com/problems/find-median-from-data-stream/description/
 * 
 * Logic:-
 * So this is somehow a hard problem.
 * Basically, we need two heaps, a min heap and a max heap.
 * We need to make sure that the size of the heaps dont exceed 
 * each other's by 1.
 * They basically need to be the same size of let the minheap have the 
 * extra element.
 * If there is a size mismatch, put the biggest element in the other heap.
 */

class MedianFinder {
public:

    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);
        if(!large.empty() && small.top() > large.top()) {
            large.push(small.top());
            small.pop();
        }
        if(small.size() > large.size() + 1) {
            large.push(small.top());
            small.pop();
        }
        if(large.size() > small.size() + 1) {
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if(small.size() > large.size()) {
            return small.top();
        } else if(small.size() < large.size()) {
            return large.top();
        } else {
            return (small.top() + large.top()) / 2.0;
        }
    }
};
