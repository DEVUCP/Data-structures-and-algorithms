#define MAX 10000
#include <iostream>


template <typename T>
class Stack{
    // First in last out

    private:
        T array[MAX];
        int top = -1;
    
    public:

        Stack(){};

        // Push front
        void push(const T elem){

            if(top >= MAX)
                throw std::overflow_error("Stack overflow");

            array[++top] = elem;
        }


        // Pop front
        T pop(){
            if(top < 0)
                throw std::underflow_error("Stack underflow");
            
            return array[top--];
        }

        // Peek front

        T peek(){
            if(top < 0){
                throw std::underflow_error("Stack is empty");
            }

            return array[top];
        }
        // Empty
        bool isEmpty(){
            return top < 0;
        }

        // Search
        int search(const int elem){
            if(top < 0)
                throw std::underflow_error("Stack is empty");
            
            for(int i = top; i >= 0; i--){
                if(array[i] == elem)
                    return i;
            }

            return -1;
        }

};