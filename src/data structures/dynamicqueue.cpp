#include <iostream>
#include "dynamic_array.cpp"

template <typename T>
class DynamicQueue{

    private:
        DynamicArr<T> elements;
        int head;
        int tail;
        int size;
    
    public:

        DynamicQueue(){
            head = 0;
            tail = -1;
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
            head++;
        }

        // Peak
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
            if(index < 0){
                return this->elements[size-1]; // if the index is negative return the last element in the queue.
            }
            return this->elements[index];
        }   

        friend std::ostream& operator<<(std::ostream& os, const DynamicQueue<T>& arr) { // Overloads the ostream << operator for full arr output
            for(int i = 0; i < arr.size; i++){
                os << arr.elements[i] << " ";
            }

            return os;
        }

};