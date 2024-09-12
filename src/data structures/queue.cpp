#include <iostream>
#define MAX 10000

template <typename T>
class Queue{

    private:
        T elements[MAX];
        int head;
        int tail;
        int size;
    
    public:

        Queue(){
            head = 0;
            tail = -1;
            size = 0;
        };

        // Enqueue

        void enqueue(const T& elem){

            if(size >= MAX)
                throw std::underflow_error("Queue is full");
            
            elements[++tail] = elem;
            size++;
        }

        // Dequeue

        void dequeue(){
            if(tail < 0){
                throw std::underflow_error("Queue is empty");
            }
            size--;
            head++;
        }

        // Peak
        T peek(){
            if(!size){
                throw std::underflow_error("Queue is empty");
            }
            return elements[head];
        }

        // Empty
        bool isEmpty(){
            return size;
        }

        // Contains
        bool contains(const T& elem){
            for(int i = 0; i < size; i++){
                if(elements[i] == elem)
                    return true;
            }
            return false;
        }

        // Size
        int getSize(){
            return size;
        }

};