#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <cstddef>
#include "Station.h"
#define BONUS 0
#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif
using namespace std;
int main(int argc, char * argv[])
{
	VS_MEM_CHECK;

	if (argc < 3) {
		cerr << "Please provide name of input and outputinputLine files";
		return 1;
	}
	cout << "Input file: " << argv[1] << endl;
	ifstream in(argv[1]);
	if (!in) {
		cerr << "Unable to open " << argv[1] << " for input";
		return 2;
	}
	cout << "outputinputLine file: " << argv[2] << endl;
	ofstream out(argv[2]);
	if (!out) {
		in.close();
		cerr << "Unable to open " << argv[2] << " for outputinputLine";
		return 3;
	}
	
    //READING IN THE INPUTS
	string inputLine, inputCommand, outputExpression;
	int integerInVector;
	Station<int> stationTurntable;
    while (getline(in, inputLine))
    {
        try
       {
          if (inputLine.size() == 0) continue;
          istringstream iss(inputLine);
          iss >> inputCommand;
          if(inputCommand == "Add:station")
          {
             iss >> integerInVector;
             out << inputCommand << " " << integerInVector << stationTurntable.addCar(integerInVector) << endl;
          }
          else if(inputCommand == "Remove:station")
          {
    		  out << inputCommand << stationTurntable.removeCar() << endl;
          }
          else if (inputCommand == "Train:")
          {
          	  out << inputCommand << stationTurntable.toString() << endl;
          }
          else if (inputCommand == "Add:stack")
          {
              out << inputCommand << stationTurntable.addStack() << endl;
          }
          else if (inputCommand == "Top:stack")
          {
              out << inputCommand << " " << stationTurntable.topStack() << endl;
          }
          else if (inputCommand == "Remove:stack")
          {
              out << inputCommand << stationTurntable.removeStack() << endl;
          }
          else if (inputCommand == "Add:queue")
          {
              out << inputCommand << stationTurntable.addQueue() << endl;
          }
          else if (inputCommand == "Top:queue")
          {
              out << inputCommand << " " << stationTurntable.topQueue() << endl;
          }
          else if (inputCommand == "Remove:queue")
          {
              out << inputCommand << stationTurntable.removeQueue() << endl;
          }
          else if (inputCommand == "Size:queue")
          {
              out << inputCommand << " " << stationTurntable.sizeQueue() << endl;
          }
           else if (inputCommand == "Size:stack")
          {
              out << inputCommand << " " << stationTurntable.sizeStack() << endl;
          }
          else if (inputCommand.find("Find:") != std::string::npos)
          {
              string subString;
              subString = inputCommand.substr(5);
              int outputString = stoi(subString);
              out << inputCommand << " " << stationTurntable.find(outputString) << endl;
          }
       }
       catch (std::exception& e)
       {
          out << e.what() << endl;
       }
    }
	return 0;
}