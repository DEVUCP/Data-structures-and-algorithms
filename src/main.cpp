#include <iostream>
#include "data structures/stack.cpp"

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main(){
    Stack<string> stack = Stack<string>();

    cout << stack.isEmpty() << endl;

    return 0;
}