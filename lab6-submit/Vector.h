#ifndef VECTOR_H
#define VECTOR_H
#include "Deque.h"
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

template <typename T>
class Vector
{
private:
   Deque<T> vector_;
   
public:
    Vector()
    {
         
    }
    ~Vector()
    {
        
    }
    //push the data into vector
    void push_back(const T& data)
    {
        vector_.push_back(data);
    }
    //pop back the data
    void pop_back()
    {
        T temp = vector_.back();
        vector_.pop_back();
        return temp;
    }
    //return the back of the vector
    T& back()
    {
       return vector_.back();
    }
    //return the size
    size_t size()
    {
        return vector_.size();
    }
    //return location
    T& at(size_t item)
    {
        return vector_.at(item);
    }
    //return the items in the vector
    const string toString()
    {
        stringstream ss;
        for(unsigned int i = 0; i < vector_.size(); i++){
            ss << " " << vector_.at(i);
        }
        string statementOutput = ss.str();
        return statementOutput;
    }
};
#endif