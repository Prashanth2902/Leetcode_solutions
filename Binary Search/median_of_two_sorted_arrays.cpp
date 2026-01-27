#include<bits/stdc++.h>
using namespace std;

/**
 * Leetcode Hard
 * Problem - 4. Median of Two Sorted Arrays
 * Link -> https://leetcode.com/problems/median-of-two-sorted-arrays/description/?q=median
 * 
 * Logic:-
 * So the logic is as follows
 * 1) First we find the total number of elements
 * 2) Then we store the half in a var.
 * 3) We assume A to be the smaller array. If its the other way, swap them.
 * 4) Init l to zero and r to size of array.
 * 5) Then inside the while loop, do the following
 * 6) i is the midpoint of A, j is half - i.
 * 7) Then get the left and right values using i and j, edge cases assign inf (+-)
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        int total = nums1.size() + nums2.size();
        int half = (total + 1) / 2;
        if(B.size() < A.size()) swap(A, B);
        int l = 0, r = A.size();
        while(l <= r) {
            int i = (l+r)/2;
            int j = half - i;
            int Aleft = i>0 ? A[i-1] : INT_MIN;
            int Aright = i<A.size() ? A[i] : INT_MAX;
            int Bleft = j>0 ? B[j-1] : INT_MIN;
            int Bright = j<B.size() ? B[j] : INT_MAX;

            if(Aleft <= Bright && Bleft <= Aright) {
                if(total%2 != 0) return max(Aleft, Bleft);
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            } else if (Aleft > Bright) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }
        return -1;
    }
};
