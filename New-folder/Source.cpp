#include <iostream>                                    // J
#include <fstream>
#include <sstream>
#include <string>
#include "LinkedList.h"
using namespace std;

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK;
#endif

// used hours = 1.5 hrs reading + 1.5 hrs VD + 0.5 hr VD.= 3.5 hrs.
// Used Hours =2 hrs + 2Hrs // Feb 13. 



int main(int argc, char* argv[])
{
	VS_MEM_CHECK;
	//_CrtSetBreakAlloc(294);
	if (argc < 3)
	{
		cerr << "Please provide name of input and output files";
		return 1;
	}
	cout << "Input file: " << argv[1] << endl;
	ifstream in(argv[1]);
	if (!in)
	{
		cerr << "Unable to open " << argv[1] << " for input";
		return 2;
	}
	cout << "Output file: " << argv[2] << endl;
	ofstream out(argv[2]);
	if (!out)
	{
		in.close();
		cerr << "Unable to open " << argv[2] << " for output";
		return 3;
	}

	string userInput;
	string dataType;
	int userIntVal = 0;
	int matchInt = 0;
	string userString;
	string matchString;
	LinkedList<int> myIntList;
	LinkedList<string> myStringList;







	while (in >> userInput)
	{
		if (userInput == "INT")
		{
			dataType = userInput;
			out << "INT true" << endl;
			in >> userInput;
		}
		if (userInput == "STRING")
		{
			dataType = userInput;
			out << "STRING true" << endl;
			in >> userInput;
		}  
		// Define the Datatype.
		if (dataType == "INT")
		{
			// INT
			if (userInput == "insertHead")
			{
				out << userInput << " ";
				in >> userIntVal;
				out << userIntVal;
				bool test = false;
				if (!myIntList.checkMatch(userIntVal))
				{
					myIntList.insertHead(userIntVal);
					out << " " << "true" << endl;
				}
				else {
					out << " " << "false" << endl;
				}
			}
			if (userInput == "insertTail")
			{
				out << userInput << " ";
				in >> userIntVal;
				out << userIntVal;
				if (!myIntList.checkMatch(userIntVal))
				{
					myIntList.insertTail(userIntVal);
					out << " " << "true" << endl;
				}
				else
				{
					out << " " << "false" << endl;
				}
			}
			if (userInput == "printList")
			{
				out << "printList ";
				out << myIntList.toString();
				out << endl;
			}
			if (userInput == "insertAfter")
			{
				out << "insertAfter ";
				in >> matchInt;
				in >> userIntVal;
				if (myIntList.checkMatch(userIntVal))
				{
					out << matchInt << " " << userIntVal << " false" << endl;
				}

				else if (!myIntList.insertAfter(matchInt, userIntVal))
				{
					out << matchInt << " " << userIntVal << " false" << endl;
				}
				else
				{
					//myIntList.insertAfter(matchInt, userIntVal);
					out << matchInt << " " << userIntVal << " true" << endl;
				}
			}
			if (userInput == "remove")
			{
				in >> userIntVal;
				out << "remove " << userIntVal;
				if (myIntList.checkMatch(userIntVal))
				{
					myIntList.remove(userIntVal);
					out << " true" << endl;
				}
				else
				{
					out << " false" << endl;
				}
			}
			if (userInput == "size")
			{
				out << "size " << myIntList.size() << endl;
			}
			if (userInput == "clear")
			{
				out << "clear ";
				myIntList.clear();
				out << "true" << endl;
			}
			if (userInput == "at")
			{
				int userIndex = 0;
				in >> userIndex;
				out << "at ";
				out << userIndex << " ";
				if (myIntList.at(userIndex, userString))
				{
					out << userString;
					out << " true" << endl;
				}
				else
				{
					out << "Invalid Index" << endl;
				}
			}
			if (userInput == "iterateList")
			{
				out << "iterateList ";
				LinkedList<int>::Iterator intIter = myIntList.begin();
				for (; intIter != myIntList.end(); ++intIter)
				{
					out << *intIter << " ";
				}
				out << endl;
			}
		}
		if (dataType == "STRING")
		{
			// STRING
			if (userInput == "insertHead")
			{
				out << userInput << " ";
				in >> userString;
				out << userString;
				if (!myStringList.checkMatch(userString))
				{
					myStringList.insertHead(userString);
					out << " " << "true" << endl;
				}
				else {
					out << " " << "false" << endl;
				}
			}
			if (userInput == "insertTail")
			{
				out << userInput << " ";
				in >> userString;
				out << userString;
				if (!myStringList.checkMatch(userString))
				{
					myStringList.insertTail(userString);
					out << " " << "true" << endl;
				}
				else
				{
					out << " " << "false" << endl;
				}
			}
			if (userInput == "printList")
			{
				out << "printList ";
				out << myStringList.toString();
				out << endl;
			}
			if (userInput == "insertAfter")
			{
				out << "insertAfter ";
				in >> matchString;
				in >> userString;
				if (myStringList.checkMatch(userString))
				{
					out << matchString << " " << userString << " false" << endl;
				}

				else if (!myStringList.insertAfter(matchString, userString))
				{
					out << matchString << " " << userString << " false" << endl;
				}
				else
				{
					//myIntList.insertAfter(matchInt, userIntVal);
					out << matchString << " " << userString << " true" << endl;
				}

			}
			if (userInput == "remove")
			{
				in >> userString;
				out << "remove " << userString;
				if (myStringList.checkMatch(userString))
				{
					myStringList.remove(userString);
					out << " true" << endl;
				}
				else
				{
					out << " false" << endl;
				}
			}
			if (userInput == "size")
			{
				out << "size " << myStringList.size() << endl;
			}
			if (userInput == "clear")
			{
				out << "clear ";
				myStringList.clear();
				out << "true" << endl;
			}
			if (userInput == "at")
			{
				int userIndex = 0;
				in >> userIndex;
				out << "at " << userIndex << " ";
				if (myStringList.at(userIndex, userString))
				{
					out << userString;
					out << " true" << endl;
				}
				else
				{
					out << "Invalid Index" << endl;
				}
			}
			if (userInput == "iterateList")
			{
				out << "iterateList ";
				LinkedList<string>::Iterator intIter = myStringList.begin();
				for (intIter; intIter != myStringList.end(); ++intIter)
				{
					out << *intIter << " ";
				}
				out << endl;
			}
		}
	}
	return 0;
}