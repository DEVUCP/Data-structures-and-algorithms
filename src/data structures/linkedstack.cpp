#include "linkedlist.cpp"

using std::cout;
using std::endl;

template <typename T>
class LinkedStack : public LinkedList<T>{

    public:

    LinkedStack(){}

    T peak(const int &index){

        Node<T>* current = this->head;
        int i = 0;

        while(i < index){
            current = current->next;
            i++;
        }
        T data = current->data;

        return data;
    }

    void push(const T& elem){
        this->push_front(elem);
    }
    
    T pop(){
        return this->pop_front();
    }
};