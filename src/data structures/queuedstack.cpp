#pragma ONCE
#include "linkedstack.cpp"
#include "linkedqueue.cpp"

template<typename T>
class QueuedStack{
    private:
        LinkedQueue<T> storage;
        LinkedQueue<T> mover;
        int size;
    public:

        QueuedStack(){
            size = 0;
        }

    void push(const T& elem){
        if(size < 1){
            storage.enqueue(elem);
            size++;
            return;
        }
        mover.enqueue(elem);

        while(!storage.isEmpty()){
            mover.enqueue(storage.peek());
            storage.dequeue();
        }
        std::swap(storage,mover);
        size++;
    }
    T pop(){
        if(size = 0)
            throw std::overflow_error("Stack is Empty");
        T popped1 = storage.peek();
        storage.dequeue();
        return popped1;
    }

    T peek(){
        if(size==0)
            throw std::underflow_error("Stack is empty");
        return storage[0];
    }
    bool isEmpty(){
        return !size;
    }

    void clear(){
        storage.clear();
    }

    T& operator[](int index) { // Overloads [] operator for element retrieval
        if(!size)
            throw std::underflow_error("Stack is Empty");
        if(index < 0){
            return this->storage[size-1]; // if the index is negative return the last element in the queue.
        }
        return this->storage[index];
    }
};