#include <iostream>

using std::cout;

template <typename T>
class DynamicArray{
    private:
        int size;
        int capacity;
        T* array;

    public:

        DynamicArray(){
            size = 0;
            capacity = 1;
            array = new T[capacity];
        }

        void shrink(){
            capacity /= 2;
            T* new_array = new T[capacity];

            for(int i = 0; i < size; i++){ // Copies old array to new array
                new_array[i] = array[i];
            }

            delete [] array;
            array = new_array;
        }

        void grow(){
            capacity *= 2;
            T* new_array = new T[capacity];

            for(int i = 0; i < size; i++){ // Copies old array to new array
                new_array[i] = array[i];
            }

            delete [] array;
            array = new_array;
        }

        void append(const T& elem){
            if(size == capacity)
                grow();
            array[size++] = elem;
        }

        T peek(int index){
            if(index < 0 || index > size-1)
                throw std::out_of_range("Index out of range");
            
            return array[index];
        }
        
        void insert(const T& elem, int index){
            
            if(index >= size || index < 0){
                append(elem);
                return;
            }

            if(size == capacity)
                grow();

            for(int i = size;i > index;i--){
                array[i] = array[i-1];
            }

            array[index] = elem;
            size++;
        }

        T pop(){

            if(!size)
                throw std::out_of_range("List is empty.");
            
            if(size > 0 && size <= capacity/4){
                shrink();
            }

            int index = size-1;
            T data = array[index];   

            array[index] = T();

            size--;
            return data;
        }

        T pop(int index){

            if(!size)
                throw std::out_of_range("Index out of range");
            
            if(size > 0 && size <= capacity/4){
                shrink();
            }

            T data = array[index];   

            for(int i = index; i < size-1; i++){
                array[i] = array[i+1];
            }

            array[size-1] = T();
            size--;
            return data;

        }

        void print(){
            if(!size)
                throw std::out_of_range("Array is empty");
            cout << "[ ";
            for(int i = 0; i < size; i++){
                cout << array[i] << (i < size-1 ? ", " : "");
            }
            cout << " ]" << std::endl;
        }

        ~DynamicArray(){
            delete [] array;
        }
};