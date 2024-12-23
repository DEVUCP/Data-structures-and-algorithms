#include <iostream>

using std::string;

template <typename T>
struct Node{
    public:
        T data;
        Node<T>* next;
        Node<T>* prev;

        Node(T data) : data(data), next(nullptr), prev(nullptr){}

        Node(T data, Node<T>* next) : data(data), next(next), prev(nullptr){}

// to call the tail constructor you must provide a third int argument just to diffrentiate from head constructor
        Node(T data, Node<T>* prev, int num) : data(data), prev(prev), next(nullptr){}

        Node(T data, Node<T>* next, Node<T>* prev) : data(data), next(next), prev(prev){}
};

template <typename T>
class DoublyLinkedList{
    public:

        Node<T>* head;
        Node<T>* tail;
        int size;

        DoublyLinkedList(){
            this->head = nullptr;
            this->tail = this->head;
            size = 0;
        }

        ~DoublyLinkedList(){
            Node<T>* current = this->head;
            while(current != nullptr){
                Node<T>* next = current->next;
                delete current;
                current = next;
            }
        }

        int getSize(){
            return this->size;
        }
        void push_front(T elem){
            insert(elem, 0);
        }

        void append(T elem){
            insert(elem, size);
        }

        T get(int index){

            if(!size || index > (size - 1))
                throw std::underflow_error("List is empty,");

            if(!index){ // if first element
                return head->data;
            }
    
            if(index == size-1 || index < 0){ // if last element
               return tail->data;
            }
            
            Node<T>* current = this->head;

            for(int i = 0; i < index-1; i++){ // Gets address of node before the one to be popped
                current = current->next;
            }

            return current->data;

        }

        T search(T elem){

            if(!size)
                throw std::underflow_error("List is empty,");


            Node<T>* current = this->head;

            for(int i = 0; i < size-1; i++){ // Gets address of node before the one to be popped
                if(current->data == elem){
                    return i;
                }
                current = current->next;
            }

            return size-1;

        }

        void insert(T elem, int index){
            if(index > size) // Allows elements to be appended.
                throw std::underflow_error("List is empty, Invalid index.");

            if(!index){
                Node<T>* new_elem = new Node<T>{elem, this->head};
                this->head = new_elem;
                size++;
                return;
            }
            if(index == size && size == 1){
                Node<T>* new_elem = new Node<T>{elem, this->head, 1};
                this->head->next = new_elem;
                this->tail = new_elem;
                size++;
                return;
            }

            Node<T>* current = this->head;
            int i = 0;

            while(i < index-1){ 
                current = current->next;
                i++;
            }
            if(index < size){
                Node<T>* moved = current->next;
                Node<T>* new_elem = new Node<T>{elem, moved, current};
                current->next = new_elem;
                moved->prev = new_elem;
                size++;
            }
            else{
                Node<T>* new_elem = new Node<T>{elem, current, 1};
                current->next = new_elem;
                this->tail = new_elem;
                size++;
            }
        

        }

        T pop(int index){

            if(index < 0)
                index = size-1;

            if(!size || index > (size - 1))
                throw std::underflow_error("List is empty,");

            if(!index){ // if first element

                Node<T>* popped = head;
                T data = popped->data;

                head = head->next;
                head->prev = nullptr;
                delete popped;
                this->size--;
                return data;
            }
            
            int i = 0;
            Node<T>* current = this->head;

            while(i < index-1){ // Gets address of node before the one to be popped
                current = current->next;
                i++;
            }

            if(index == size-1 || index < 0){ // if last element
                Node<T>* popped = tail;
                T data = tail->data;
                current->next = nullptr;
                tail = current;
                
                delete popped;
                this->size--;
                return data;
            }

            // otherwise

            Node<T>* popped = current->next;
            T data = popped->data;
            Node<T>* after = popped->next;

            current->next = after;
            after->prev = current;
            this->size--;
            delete popped;
            return data;

        }

        T pop_front(){
            return pop(0);
        }
    
        T pop_back(){
            return pop(size-1);
        }


        void print(){

            if(size == 0){
                std::cout << "LinkedList = [ ]";
                return;}

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
    
        int getMin(){

            Node<T>* current = this->head;
            int smallest = this->head->data;

            for(int i = 0;i < size; i++){ // Gets address of node before the one to be popped
                if(current->data < smallest)
                    smallest = current->data;
                current = current->next;
            }
            return smallest;
        }

        void delAtSight(const T element){
            Node<T>* current = this->head;

            if(current->data == element){
                this->pop(0);
                return;
            }
            
            int i = 0;
            while(i < size-1){ // Gets address of node before the one to be deleted
                if(current->next->data == element)
                    break;
                current = current->next;
                i++;
            }

            if(i < size){
                Node<T>* del = current->next;
                current->next = del->next;
                delete del;
                size--;
                return;
            }

            if(i == size)
                this->pop_back();
        }

};