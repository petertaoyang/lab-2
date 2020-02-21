#include "BST.h"
#include<iostream>
#include<fstream>
#include<sstream>


using namespace std;

int main(int argc, char** argv) {

	if (argc < 3)
	{
		cout << "Please provide name of input and output files";
		return 1;
	}
	cout << "Input file: " << argv[1] << endl;
	ifstream in(argv[1]);
	if (!in)
	{
		cout << "Unable to open " << argv[1] << " for input";
		return 2;
	}
	cout << "Output file: " << argv[2] << endl;
	ofstream out(argv[2]);
	if (!out)
	{
		in.close();
		cout << "Unable to open " << argv[2] << " for output";
		return 3;
	}

	BST<string> stringTree;
	BST<int> intTree;
	string command = " ";
	int numberElement = 0;
	string textELement = " ";
	bool isString = true;
	
	while (in>>command) {

		if (command == "INT") {
			isString = false;
			out << "INT true" << endl;
		}
		else if (command == "STRING") {
			isString = true;
			out << "STRING true" << endl;
		}

		if (command == "add" && !isString) {
			//call add function
			in >> numberElement;
			out << "add " << numberElement;
			if (!intTree.addNode(numberElement)) {
				out << " false" << endl;
			}
			else {
				out << " true" << endl;
			}
		}
		else if (command == "print" && !isString) {
			if (intTree.size() > 0) {
				out << "print: " << endl << intTree.toString() << endl;
			}
			else {
				out << "print: empty" << endl;
			}
			
		}
		else if (command == "size" && !isString) {
			out << "size " << intTree.size() << endl;
		}
		else if (command == "clear" && !isString) {
			out << "clear true" << endl;
			intTree.clearTree();
		}
		else if (command == "remove" && !isString) {
			in >> numberElement;
			out << "remove " << numberElement;
			if (!intTree.removeNode(numberElement)) {
				out << " false" << endl;
			}
			else {
				out << " true" << endl;
			}
			
		}
		else if (command == "find" && !isString) {
			in >> numberElement;
			out << "find " << numberElement;
			if (!intTree.find(numberElement)) {
				out << " not found" << endl;
			}
			else {
				out << " found" << endl;
			}
		}

		// for strings
		else if (command == "add" && isString) {
			//call add function
			in >> textELement;
			out << "add " << textELement;
			if (!stringTree.addNode(textELement)) {
				out << " false" << endl;
			}
			else {
				out << " true" << endl;
			}
		}
		else if (command == "print" && isString) {
			if (stringTree.size() > 0) {
				out << "print: " << endl << stringTree.toString() << endl;
			}
			else {
				out << "print: empty" << endl;
			}

		}
		else if (command == "size" && isString) {
			out << "size " << stringTree.size() << endl;
		}
		else if (command == "clear" && isString) {
			out << "clear true" << endl;
			stringTree.clearTree();
		}
		else if (command == "remove" && isString) {
			in >> textELement;
			out << "remove " << textELement;
			
			if (!stringTree.removeNode(textELement)) {
				out << " false" << endl;
			}
			else {
				out << " true" << endl;
			}
		}
		else if (command == "find" && isString) {
			in >> textELement;
			out << "find " << textELement;
			if (!stringTree.find(textELement)) {
				out << " not found" << endl;
			}
			else {
				out << " found" << endl;
			}
		}
		
	}
	return 0;
}