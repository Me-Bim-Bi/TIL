//
// Created by Chu Ha Thanh on 2024-12-16.
//

#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>

using namespace std;

//gör man en klass som fungerar som en stack

template <typename T>
class Stack
{
    int size = 5;
    T** stack;
    int top = 0; //index som talar om nästa lediga plats


public:
  //jag kan inte declar .. dem neren med CLion nu men man får göra det
    Stack(){
      stack = new T*[this->size]{nullptr};
    };
    ~Stack(){
      for (int i = 0; i < this->size; i++) {
        delete stack[i];
      }
      delete[] stack;
    };
    void push(const T& element){
      stack[this->top] = new T(element);
      this->top++;
    };
    T pop(){
      return *stack[this->top-1];
    };
};


#endif //STACK_H
