#include<bits/stdc++.h>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int len;
    int cap;
public:

    DynamicArray(int capacity) {
        arr = new int[capacity];
        cap = capacity;
        len = 0;
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if(len == cap) resize();
        arr[len] = n;
        len++;
    }

    int popback() {
        if (len > 0){
            len--;
        }
        return arr[len];
    }

    void resize() {
        cap *= 2;
        int* newArr = new int[cap];
        for(int i=0;i<len;i++){
            newArr[i] = arr[i]; 
        }
        delete[] arr;
        arr = newArr;
    }

    int getSize() {
        return len;
    }

    int getCapacity() {
        return cap;
    }
};
