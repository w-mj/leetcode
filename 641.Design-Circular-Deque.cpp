#include <bits/stdc++.h>
class MyCircularDeque {
public:
    int data[1024];
    int s = 0, e = 0;
    int maxk = 0;
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        s = 0;
        e = 0;
        maxk = k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull())
            return false;
        s = (maxk + (s - 1)) % maxk;
        data[s] = value;
        if (s == e)
            e++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull())
            return false;
        data[e] = value;
        e = (e + 1) % maxk;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty())
            return false;
        s = (s + 1) % maxk;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty())
            return false;
        e = ((e - 1) + maxk) % maxk;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty())
            return -1;
        return data[s];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty())
            return -1;
        return data[((e - 1) + maxk) % maxk];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return s == e;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return (s == 0 && e == maxk) || (s == e + 1);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */