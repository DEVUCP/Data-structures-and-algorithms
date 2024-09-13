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

            Node<T>* last = this->head;
            int i = 0;

            while(i < index-1){
                last = last->next;
                i++;
            }

            Node<T>* moved = last->next;
            Node<T>* new_elem = new Node<T>{elem, moved};
            last->next = new_elem;
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
            Node<T>* last = this->head;

            while(i < index-1){ // Gets address of node before the one to be popped
                last = last->next;
                i++;
            }

            if(index == size-1){ // if last element
                Node<T>* popped = last->next;
                T data = popped->data;

                last->next = nullptr;
                delete popped;
                return data;
            }

            // otherwise

            Node<T>* popped = last->next;
            T data = popped->data;
            Node<T>* after = popped->next;

            last->next = after;
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

            Node<T>* last = this->head;
            std::cout << "LinkedList = [ ";
            std::cout << last->data;

            while(last->next != nullptr){
                last = last->next;
                std::cout << ", ";
                std::cout << last->data;
            }
            std::cout << " ]" << std::endl;
        }
};