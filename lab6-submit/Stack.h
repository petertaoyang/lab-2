#ifndef STACK_H
#define STACK_H
#include "Deque.h"

template <typename T>
class Stack
{
private:
   Deque<T> stack_;
   
public:
    Stack()
    {
        
    }
    ~Stack()
    {
        
    }
    //push function
    string push(const T& item)
    {
     stack_.push_back(item);  
    }
    //pop the top
    void pop()
    {
        stack_.pop_back();
    }
    //return the top
    T& top()
    {
        return stack_.back();
    }
    //return the size
    size_t size()
    {
        return stack_.size();
    }
    //return at
    T& at(size_t item)
    {
        return stack_.at(item);
    }
};
#endif