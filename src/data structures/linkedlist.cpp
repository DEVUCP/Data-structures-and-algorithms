#include <iostream>

using std::string;

template <typename T>
class Node{
    public:
        T data;
        Node<T>* next;
};

template <typename T>
class LinkedList{
    public:

        Node<T>* head;
        int size;

        LinkedList(){
            this->head = nullptr;
            size = 0;
        }

        ~LinkedList(){
            Node<T>* current = this->head;
            while(current != nullptr){
                Node<T>* next = current->next;
                delete current;
                current = next;
            }
        }

        void push_front(const T& elem){
            insert(elem, 0);
        }

        void push_back(const T& elem){
            insert(elem, size-1);
        }

        void append(const T& elem){
            insert(elem, size);
        }

        void insert(const T& elem, int index){
            if(index > size) // Allows elements to be appended.
                throw std::underflow_error("List is empty, Invalid index.");

            if(!index){
                Node<T>* new_elem = new Node<T>{elem, this->head};
                this->head = new_elem;
                size++;
                return;
            }

            Node<T>* current = this->head;
            int i = 0;

            while(i < index-1){
                current = current->next;
                i++;
            }

            Node<T>* moved = current->next;
            Node<T>* new_elem = new Node<T>{elem, moved};
            current->next = new_elem;
            size++;

        }

        T pop(int index){

            if(!size || index > (size - 1))
                throw std::underflow_error("List is empty,");

            if(!index){ // if first element

                Node<T>* popped = this->head;
                T data = popped->data;
                head->next;
            }
            
            int i = 0;
            Node<T>* current = this->head;

            while(i < index-1){ // Gets address of node before the one to be popped
                current = current->next;
                i++;
            }

            if(index == size-1){ // if current element
                Node<T>* popped = current->next;
                T data = popped->data;

                current->next = nullptr;
                delete popped;
                return data;
            }

            // otherwise

            Node<T>* popped = current->next;
            T data = popped->data;
            Node<T>* after = popped->next;

            current->next = after;
            delete popped;
            return data;

        }

        T pop_front(const T& elem){
            return pop(elem, 0);
        }
    
        T pop_back(const T& elem){
            return pop(elem, size-1);
        }

        void print(){

            Node<T>* current = this->head;
            std::cout << "LinkedList = [ ";
            std::cout << current->data;

            while(current->next != nullptr){
                current = current->next;
                std::cout << ", ";
                std::cout << current->data;
            }
            std::cout << " ]" << std::endl;
        }


};