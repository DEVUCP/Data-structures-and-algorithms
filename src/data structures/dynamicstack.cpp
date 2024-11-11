#include "dynamic_array.cpp"
#include <iostream>


template <typename T>
class DynamicStack{
    // First in last out

    private:
        DynamicArr<T> arr;
        int top = -1;
    
    public:

        DynamicStack(){};
        
        int getTop(){return top;}

        // Push front
        void push(T elem){
            top++;
            arr.append(elem);
        }


        // Pop front
        T pop(){
            if(top < 0)
                throw std::underflow_error("Stack underflow");
            
            return arr.pop(top--);
        }

        // Peek front

        T peek(){
            if(top < 0){
                throw std::underflow_error("Stack is empty");
            }

            return arr[top];
        }
        // Empty
        bool isEmpty(){
            return top < 0;
        }

        // Search
        int search(const T& elem){
            if(top < 0)
                throw std::underflow_error("Stack is empty");
            
            for(int i = top; i >= 0; i--){
                if(arr[i] == elem)
                    return i;
            }

            return -1;
        }

        void print(){
            if(top < 0)
                throw std::underflow_error("Stack is empty");
            std::cout<< "[ ";
            for(int i = 0; i<=top;i++){
                if (i != top)
                    std::cout<< this->arr[i] << ", ";
                else
                    std::cout<< this->arr[i] << " ]";
            }
        }

        void clear(){
            if(top < 0)
                throw std::underflow_error("Stack is empty");
            top = -1;
            arr.clear();
                
        }
        

};