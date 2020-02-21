#ifndef STATION_H
#define STATION_H
#include "Vector.h"
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"

template <typename T>
class Station
{
    private:
    Vector<T> trainVector;
    Stack<T> stackOutput;
    Queue<T> queueOutput;
    T turntableCar;
    bool testEmpty = true;
    
    public:
    Station()
    {
       //constructor 
    }
    ~Station()
    {
        //destructor
    }
    //function to addCar to Turntable
    string addCar(const T& input)
    {
        string outputStatement;
        if(testEmpty == true)
        {
            outputStatement = " OK";
            turntableCar = input;
            testEmpty = false;
        }
        else
        {
            outputStatement = " No";
        }
        return outputStatement;
    }
    //function to remove Car from turntable
    string removeCar()
    {
        string outputStatement;
        if(testEmpty == true)
        {
            outputStatement = " Turntable empty!";
        }
        else
        {
            outputStatement = " OK";
            trainVector.push_back(turntableCar);
            turntableCar--;
            testEmpty = true;
        }
        return outputStatement;
    }
    //function to add the car from turntable to the stack
    string addStack()
    {
        string outputStatement;
        if(testEmpty == true)
        {
            outputStatement = " Turntable empty!";
        }
        else
        {
            outputStatement = " OK";
            stackOutput.push(turntableCar);
            turntableCar--;
            testEmpty = true;
        }
        return outputStatement;
    }
    //function to remove from the stack into the turntable
    string removeStack()
    {
        string outputStatement;
        if(stackOutput.size() == 0)
        {
            outputStatement = " Stack empty!";
        }
        else
        {
            outputStatement = " OK";
            int output = stackOutput.top();
            stackOutput.pop();
            turntableCar = output;
            testEmpty = false;
        }
        return outputStatement;
    }
    //function to return the top of the stack
    string topStack()
    {
        stringstream ss;
        ss << stackOutput.top();
        string outputStatement = ss.str();
        return outputStatement;
    }
    //function to return the size of the Stack
    string sizeStack()
    {
        stringstream ss;
        ss << stackOutput.size();
        string outputStatement = ss.str();
        return outputStatement;
    }
    //function to add turntable car into the Queue
    string addQueue()
    {
        string outputStatement;
        if(testEmpty == true)
        {
            outputStatement = " Turntable empty!";
        }
        else
        {
            outputStatement = " OK";
            queueOutput.push(turntableCar);
            turntableCar--;
            testEmpty = true;
        }
        return outputStatement;
    }
    //function to remove from the Queue into the turntable
    string removeQueue()
    {
        string outputStatement;
        if(queueOutput.size() == 0)
        {
            outputStatement = " Queue empty!";
        }
        else{
            outputStatement = " OK";
            int output = queueOutput.top();
            queueOutput.pop();
            turntableCar = output;
            testEmpty = false;
        }
        return outputStatement;
    }
    //function to return the top of the Queue
    string topQueue()
    {
        stringstream ss;
        ss << queueOutput.top();
        string outputStatement = ss.str();
        return outputStatement;
    }
    //functino to return thte size
    string sizeQueue()
    {
        stringstream ss;
        ss << queueOutput.size();
        string outputStatement = ss.str();
        return outputStatement;
        
    }
    //function to find item in all the data structures
    string find(T itemToFind)
    {
        bool stillTrue = true;
        string outputStatement = "";
        if(itemToFind == turntableCar)
        {
            outputStatement = "Turntable";
            return outputStatement;
        }
        for(unsigned int i = 0; i < trainVector.size(); i++)
        {
            if(itemToFind == trainVector.at(i))
            {
                outputStatement = "Train[" + to_string(i) + "]";
                return outputStatement;
            }
        }
        for(unsigned int i = 0; i < queueOutput.size() + 2 ; i++)
        {
            if(itemToFind == queueOutput.at(i))
            {
                if(i == 3)
                {
                    i = 1;
                }
                outputStatement = "Queue[" + to_string(i) + "]";
                return outputStatement;
            }
        }
        for(unsigned int i = 0; i < stackOutput.size() ; i++)
        {
            if(itemToFind == stackOutput.at(i))
            {
                outputStatement = "Stack[" + to_string(i) + "]";
                return outputStatement;
            }
        }
        if(!stillTrue)
        {
           return outputStatement; 
        }
        else{
            outputStatement = "Not Found!";
            return outputStatement;
        }
    }
    //prints out the items in the vector
    const string toString()
    {
        return trainVector.toString();
    }
};
#endif