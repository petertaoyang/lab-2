/*
Justin Strommen, Roper, Section 2
*/

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif

#include <iostream>
#include <fstream>
#include <sstream>

#include "Station.h"

int main(int argc, char* argv[])
{
	VS_MEM_CHECK
	if (argc < 3)
	{
		std::cerr << "Please provide input and output files." << std::endl;
		return 1;
	}
	std::ifstream inFS;
	inFS.open(argv[1]);
	if (!inFS)
	{
		std::cerr << "Unable to open " << argv[1] << " for input." << std::endl;
		return 2;
	}
	std::ofstream outFS;
	outFS.open(argv[2]);
	if (!outFS)
	{
		inFS.close();
		std::cerr << "Unable to open " << argv[2] << " for output." << std::endl;
		return 3;
	}

	int newCar;
	int findCar;
	std::string inputLine;
	std::string currInput;
	std::istringstream inSS;

	Station<int> *station235 = new Station<int>;

	while (getline(inFS, inputLine))
	{
		inSS.str(inputLine);
		inSS >> currInput;

		if (inSS.fail())	// To handle blank lines in input file
		{
			currInput = "";
			inSS.clear();
			continue;
		}

		if (currInput == "Add:station")
		{
			outFS << currInput;
			inSS >> newCar;
			outFS << " " << newCar << " ";
			outFS << station235->addCar(newCar);
			outFS << std::endl;
		}
		else if (currInput == "Add:stack")
		{
			outFS << currInput;
			outFS << " " << station235->addStack();
			outFS << std::endl;
		}
		else if (currInput == "Add:queue")
		{
			outFS << currInput;
			outFS << " " << station235->addQueue();
			outFS << std::endl;
		}
		else if (currInput == "Remove:station")
		{
			outFS << currInput;
			outFS << " " << station235->removeCar();
			outFS << std::endl;
		}
		else if (currInput == "Remove:stack")
		{
			outFS << currInput;
			outFS << " " << station235->removeStack();
			outFS << std::endl;
		}
		else if (currInput == "Remove:queue")
		{
			outFS << currInput;
			outFS << " " << station235->removeQueue();
			outFS << std::endl;
		}
		else if (currInput == "Top:station")
		{
			outFS << currInput;
			outFS << " " << station235->topCar();
			outFS << std::endl;
		}
		else if (currInput == "Top:stack")
		{
			outFS << currInput;
			outFS << " " << station235->topStack();
			outFS << std::endl;
		}
		else if (currInput == "Top:queue")
		{
			outFS << currInput;
			outFS << " " << station235->topQueue();
			outFS << std::endl;
		}
		else if (currInput == "Size:stack")
		{
			outFS << currInput;
			outFS << " " << station235->sizeStack();
			outFS << std::endl;
		}
		else if (currInput == "Size:queue")
		{
			outFS << currInput;
			outFS << " " << station235->sizeQueue();
			outFS << std::endl;
		}
		else if (currInput == "Train:")
		{
			outFS << currInput;
			outFS << " " << station235->toString();
			outFS << std::endl;
		}
		else if (currInput.substr(0, 5) == "Find:")
		{
			outFS << currInput;
			findCar = std::stoi(currInput.substr(5, 1));
			outFS << " " << station235->find(findCar);
			outFS << std::endl;
		}
		else if (inputLine == "")
		{
			// Do nothing
		}

		inSS.clear();
	}

	// delete things
	delete station235;

	return 0;
}
