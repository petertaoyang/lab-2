#ifndef QUEUE_H
#define QUEUE_H
#include "Deque.h"

template <typename T>
class Queue
{
private:
   Deque<T> queue_;
   
public:
    Queue()
    {
       
    }
    ~Queue()
    {
        
    }
    //push
    string push(const T& item)
    {
        queue_.push_back(item);
    }
    //delete the top
    void pop()
    {
        queue_.pop_front();
    }
    //return top
    T& top()
    {
        return queue_.front();
    }
    //return size
    size_t size()
    {
        return queue_.size();   
    }
    //return at
    T& at(size_t item)
    {
        return queue_.at(item);
    }
};
#endif