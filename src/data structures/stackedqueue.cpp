#pragma ONCE
#include "linkedstack.cpp"
#include "linkedqueue.cpp"

template<typename T>
class StackedQueue{
    private:
        LinkedStack<T> storage;
        LinkedStack<T> mover;
        int size;

    public:

        StackedQueue(){
            size = 0;
        }
    void enqueue(const T& elem){
        if(size < 1){
            storage.push(elem);
            size++;
            return;
        }
        mover.push(elem);

        while(!storage.isEmpty()){
            mover.push(storage.pop());
        }
        while(!mover.isEmpty()){
            storage.push(mover.pop());
        }
        size++;
    }
    T dequeue(){
        if(size = 0)
            throw std::overflow_error("Stack is Empty");
        return storage.pop();
    }

    T front(){
        if(size==0)
            throw std::underflow_error("Stack is empty");
        return storage.peek();
    }
    bool isEmpty(){
        return !size;
    }

    void clear(){
        storage.clear();
    }

    T& operator[](int index) { // Overloads [] operator for element retrieval
        if(!size)
            throw std::underflow_error("Queue is Empty");
        if(index < 0){
            return this->storage[size-1]; // if the index is negative return the last element in the queue.
        }
        return this->storage[index];
    }

};