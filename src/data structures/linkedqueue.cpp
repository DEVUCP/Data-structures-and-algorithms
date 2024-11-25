#include <iostream>
#include "linkedlist.cpp"

template <typename T>
class LinkedQueue{

    private:
        LinkedList<T> elements;
        int size;
    
    public:

        LinkedQueue(){
            size = 0;
        };

        // Enqueue

        void enqueue(const T& elem){
            
            elements.append(elem);
            size++;
        }

        // Dequeue

        void dequeue(){
            if(size == 0){
                throw std::underflow_error("Queue is empty");
            }
            elements.pop(0);
            size--;
        }

        // Peek
        T peek(){
            if(!size){
                throw std::underflow_error("Queue is empty");
            }
            return elements[0];
        }

        // Empty
        bool isEmpty(){
            return !size;
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

        T& operator[](int index) { // Overloads [] operator for element retrieval
            if(!size)
                throw std::underflow_error("Queue is Empty");
            if(index < 0){
                return this->elements[size-1]; // if the index is negative return the last element in the queue.
            }
            return this->elements[index];
        }

        const T& operator[](int index) const { // Overloads [] operator for element retrieval
            if(!size)
                throw std::underflow_error("Queue is Empty");
            if(index < 0){
                return this->elements[size-1]; // if the index is negative return the last element in the queue.
            }
            return this->elements[index];
        }

        friend std::ostream& operator<<(std::ostream& os, const LinkedQueue<T>& arr) { // Overloads the ostream << operator for full arr output
            for(int i = 0; i < arr.size; i++){
                os << arr.elements[i] << " ";
            }

            return os;
        }

        void clear(){
            elements.clear();
        }

};