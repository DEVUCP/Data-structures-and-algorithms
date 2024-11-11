#pragma once
#include <iostream>
#include <type_traits>

using std::cout;

template <typename T>
class DynamicArr{
    private:
        int size;
        int capacity;
        T* arr;

    public:

        DynamicArr(){
            size = 0;
            capacity = 1;
            arr = new T[capacity];
        }

        T& operator[](int index) { // Overloads [] operator for element retrieval
        return this->arr[index];
        }   

        friend std::ostream& operator<<(std::ostream& os, const DynamicArr<T>& arr){ // Overloads the ostream << operator for full arr output
            for(int i = 0; i < arr.size; i++){
                os << arr.arr[i] << " ";
            }

            return os;
        }

        void shrink(){
            capacity /= 2;
            T* new_arr = new T[capacity];

            for(int i = 0; i < size; i++){ // Copies old arr to new arr
                new_arr[i] = arr[i];
            }

            delete [] arr;
            arr = new_arr;
        }

        void grow(){
            capacity *= 2;
            T* new_arr = new T[capacity];

            for(int i = 0; i < size; i++){ // Copies old arr to new arr
                new_arr[i] = arr[i];
            }

            delete [] arr;
            arr = new_arr;
        }

        void append(const T& elem){
            if(size == capacity)
                grow();
            arr[size++] = elem;
        }

        T peek(int index){
            if(index < 0 || index > size-1)
                throw std::out_of_range("Index out of range");
            
            return arr[index];
        }
        
        void insert(const T& elem, int index){
            
            if(index >= size || index < 0){
                append(elem);
                return;
            }

            if(size == capacity)
                grow();

            for(int i = size;i > index;i--){
                arr[i] = arr[i-1];
            }

            arr[index] = elem;
            size++;
        }

        T pop(){

            if(!size)
                throw std::out_of_range("List is empty.");
            
            if(size > 0 && size <= capacity/4){
                shrink();
            }

            int index = size-1;
            T data = arr[index];   

            arr[index] = T();

            size--;
            return data;
        }

        T pop(int index){

            if(!size)
                throw std::out_of_range("Index out of range");
            
            if(size > 0 && size <= capacity/4){
                shrink();
            }

            T data = arr[index];   

            for(int i = index; i < size-1; i++){
                arr[i] = arr[i+1];
            }

            arr[size-1] = T();
            size--;
            return data;

        }

        void print(){
            if(!size)
                throw std::out_of_range("arr is empty");
            cout << "[ ";
            for(int i = 0; i < size; i++){
                cout << arr[i] << (i < size-1 ? ", " : "");
            }
            cout << " ]" << std::endl;
        }

        bool isEmpty(){
            return !this->size;
        }

        void sort(){
            int n = this->size();
            for (int i = 0; i < n - 1; ++i) {

                bool swapped = false;

                for (int j = 0; j < n - i - 1; ++j) {

                    if (this->arr[j] > this->arr[j + 1]) {
                        std::swap(this->arr[j], this->arr[j + 1]);
                        swapped = true;
                    }
                }
                if (!swapped) {
                    break;
                }
            }
        }

        void reverse(){
            int beg = 0;
            int end = this->size - 1;

            while (beg < end) { // swap alternating
                std::swap(this->arr[beg++], this->arr[end--]);
            }
        }
        
        int countPrime(){
            static_assert(std::is_same<T, int>::value, "countPrime() can only be used with int type.");
            int count = 0;
            for (int j = 0; j < this->size; j++) {

                if (this->arr[j] > 1) { 
                    bool prime = true; 

                    for (int i = 2; i * i <= this->arr[j]; ++i) {
                        if (this->arr[j] % i == 0) {
                            prime = false;
                            break;
                        }
                    }
                    if (prime) {
                        count++; // Count the prime number
                    }
                }
            }
            return count;
        }

        int countEven() {
            static_assert(std::is_same<T, int>::value, "countEven() can only be used with int type.");
            int count = 0;
            for (int i = 0; i < this->size; i++) {
                if (this->arr[i] % 2 == 0) {
                    count++;
                }
            }
            return count;
        }
        void clear(){
            size = 0;
            delete [] arr;
            arr = new T[capacity];
        }
        // I would add countPrime() and countEven() methods, but those are int exclusive
        ~DynamicArr(){
            delete [] arr;
        }
};


