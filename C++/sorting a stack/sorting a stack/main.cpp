#include <iostream>
#include "stack"
using namespace std;


template <class T>
stack<T> stack_sort(stack<T> input_stack) {
    stack<T> temp_stack;
    T current;
    while (!input_stack.empty()) {
        current = input_stack.top();
        input_stack.pop();
        while (!temp_stack.empty() && temp_stack.top()<current) {
            input_stack.push(temp_stack.top());
            temp_stack.pop();
        }
        temp_stack.push(current);
    }
    return temp_stack;
}
int main(void){
    stack<char> input;
    cout<<"Enter number of characters : "<<endl;
    int num;
    cin>>num;
    while (num) {
        cout<<"enter a character : "<<endl;
        char alpha;
        cin>>alpha;
        input.push(alpha);
        num--;
    }
    stack<char> tmpstack = stack_sort(input);
    cout<<"sorted numbers are:\n";
    while (!tmpstack.empty()) {
        cout<<tmpstack.top()<<" ";
        tmpstack.pop();
    }
    cout<<"\n";
}
