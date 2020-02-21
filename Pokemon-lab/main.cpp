#include "Set.h"
#include "Map.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif

bool ifEffective(string inputType, string key, Map<string, Set<string>> &effectivies);
bool ifIneffective(string inputType, string key, Map<string, Set<string>> &ineffectives);

int main(int argc, char * argv[])
{
	VS_MEM_CHECK
	ifstream in(argv[1]);
	ofstream out(argv[2]);
	string inputLine;
	string inputCommand;
	string inputName;
	string inputType;
	Map<string, string> pokemon;
	Map<string, string> moves;
	Map<string, Set<string>> effectives;
	Map<string, Set<string>> ineffectives;
	Set<string> pokemonList;


	
	while (getline(in, inputLine))
	{
		if (inputLine == "")
		{
			continue;
		}
		stringstream iss(inputLine);
		iss >> inputCommand;
		iss >> inputName;
		if (inputCommand != "Effectivities" && inputCommand != "Ineffectivities" && inputCommand != "Pokemon" && inputCommand != "Moves" && inputCommand != "Battle:")
		{
			out << inputLine << endl;
		}

		if (inputCommand == "Set:")
		{
			pokemonList.clear();
			do
			{
				pokemonList.insert(inputName);
			} while (iss >> inputName);

			out << "  [" << pokemonList.toString() << "]" << endl << endl;

		}

		if (inputCommand == "Pokemon:")
		{
			iss >> inputType;
			pokemon[inputName] = inputType;
		}

		if (inputCommand == "Move:")
		{
			iss >> inputType;
			moves[inputName] = inputType;
		}

		if (inputCommand == "Effective:")
		{
			iss >> inputType;
			do
			{
				effectives[inputName].insert(inputType);
			} while (iss >> inputType);
		}

		if (inputCommand == "Ineffective:")
		{
			iss >> inputType;
			do
			{
				ineffectives[inputName].insert(inputType);
				//cout << ineffectives.toString() << endl;
			} while (iss >> inputType);

		}

		if (inputCommand == "Effectivities")
		{
			out << endl;
			stringstream ss;
			ss << "Effectivities: " << effectives.size() << "/" << effectives.max_size() << endl;
			ss << effectives.toString();
			out << ss.str();
		}

		if (inputCommand == "Pokemon")
		{
			out << endl;
			stringstream ss;
			ss << "Pokemon: " << pokemon.size() << "/" << pokemon.max_size() << endl;
			ss << pokemon.toString();
			out << ss.str();
			//out << endl;
		}

		if (inputCommand == "Moves")
		{
			out << endl;
			stringstream ss;
			ss << "Moves: " << moves.size() << "/" << moves.max_size() << endl;
			ss << moves.toString();
			out << ss.str();
		}

		if (inputCommand == "Ineffectivities")
		{
			out << endl;
			stringstream ss;
			ss << "Ineffectivities: " << ineffectives.size() << "/" << ineffectives.max_size() << endl;
			ss << ineffectives.toString();
			out << ss.str();
			//out << endl;
		}

		if (inputCommand == "Battle:")
		{
			out << endl;
			stringstream ss;
			string pokemominputName;
			string moveinputType;
			iss >> inputType;
			iss >> pokemominputName;
			iss >> moveinputType;
			string pokemon1inputType = pokemon[inputName];
			string move1inputType = moves[inputType];
			string pokemon2inputType = pokemon[pokemominputName];
			string move2inputType = moves[moveinputType];
			bool ifEffect1 = false;
			bool ifIneffect1 = false;
			bool ifEffect2 = false;
			bool ifIneffect2 = false;
			string gameWinner = "default";
			string result1;
			string result2;
			string effectivites1;
			string effectivites2;
			ifEffect1 = ifEffective(pokemon2inputType, move1inputType, effectives);
			ifIneffect1 = ifIneffective(pokemon2inputType, move1inputType, ineffectives);
			ifEffect2 = ifEffective(pokemon1inputType, move2inputType, effectives);
			ifIneffect2 = ifIneffective(pokemon1inputType, move2inputType, ineffectives);

			//check if the first pokemon's move is effect or ineffect or regular to the second pokemon
			if (ifEffect1 == true)
			{
				result1 = inputName + "'s " + inputType + " is super effective against " + pokemominputName;
				effectivites1 = "super effective";
			}

			else if (ifIneffect1 == true)
			{
				result1 = inputName + "'s " + inputType + " is ineffective against " + pokemominputName;
				effectivites1 = "ineffective";
			}

			else
			{
				result1 = inputName + "'s " + inputType + " is effective against " + pokemominputName;
				effectivites1 = "effective";
			}
//------------------------------------------------------------------------------------------------------------------

			//check if the second pokemon's move is effect or ineffect or regular to the first pokemon
			if (ifEffect2 == true)
			{
				result2 = pokemominputName + "'s " + moveinputType + " is super effective against " + inputName;
				effectivites2 = "super effective";
			}

			else if (ifIneffect2 == true)
			{
				result2 = pokemominputName + "'s " + moveinputType + " is ineffective against " + inputName;
				effectivites2 = "ineffective";
			}

			else
			{
				result2 = pokemominputName + "'s " + moveinputType + " is effective against " + inputName;
				effectivites2 = "effective";
			}

//---------------------------------------------------------------------------------------------------
			//check the gameWinner
			if (effectivites1 == "super effective" && effectivites2 == "super effective")
			{
				gameWinner = " is a tie.";
			}

			else if (effectivites1 == "super effective" && effectivites2 == "effective")
			{
				gameWinner = ", " + inputName + " wins!";
			}

			else if (effectivites1 == "super effective" && effectivites2 == "ineffective")
			{
				gameWinner = ", " + inputName + " wins!";
			}

			else if (effectivites1 == "effective" && effectivites2 == "super effective")
			{
				gameWinner = ", " + pokemominputName + " wins!";
			}

			else if (effectivites1 == "effective" && effectivites2 == "effective")
			{
				gameWinner = " is a tie.";
			}

			else if (effectivites1 == "effective" && effectivites2 == "ineffective")
			{
				gameWinner = ", " + inputName + " wins!";
			}

			else if (effectivites1 == "ineffective" && effectivites2 == "super effective")
			{
				gameWinner = ", " + pokemominputName + " wins!";
			}

			else if (effectivites1 == "ineffective" && effectivites2 == "effective")
			{
				gameWinner = ", " + pokemominputName + " wins!";
			}

			else if (effectivites1 == "ineffective" && effectivites2 == "ineffective")
			{
				gameWinner = " is a tie.";
			}

			ss << "Battle: " << inputName << " " << inputType << " " << pokemominputName << " " << moveinputType << endl;
			ss << "  " << inputName << " (" << inputType << ") vs " << pokemominputName << " (" << moveinputType << ")" << endl;
			ss << "  " << inputName << " is a " << pokemon1inputType << " inputType Pokemon." << endl;
			ss << "  " << pokemominputName << " is a " << pokemon2inputType << " inputType Pokemon." << endl;
			ss << "  " << inputType << " is a " << move1inputType << " inputType move." << endl;
			ss << "  " << moveinputType << " is a " << move2inputType << " inputType move." << endl;
			
			//checking the size of effectivies pokemonList. Marking sure is not equal to zero
			if (effectives[move1inputType].size() == 0)
			{
				ss << "  " << inputType << " is not effective against any Pokemon." << endl;
			}
			else
			{
				ss << "  " << inputType << " is super effective against [" << effectives[move1inputType] << "]" << " inputType Pokemon." << endl;
			}
			if (ineffectives[move1inputType].size() == 0)
			{
				ss << "  " << inputType << " is not ineffective against any Pokemon." << endl;
			}
			
			else
			{
				ss << "  " << inputType << " is ineffective against [" << ineffectives[move1inputType] << "]" << " inputType Pokemon." << endl;
			}

			ss << "  " << result1 << endl;

			//checking the size of effectivies pokemonList. Marking sure is not equal to zero
			if (effectives[move2inputType].size() == 0)
			{
				ss << "  " << moveinputType << " is not effective against any Pokemon" << endl;
			}
			else
			{
				ss << "  " << moveinputType << " is super effective against [" << effectives[move2inputType] << "]" << " inputType Pokemon." << endl;
			}

			if (ineffectives[move2inputType].size() == 0)
			{
				ss << "  " << moveinputType << " is not ineffective against any Pokemon." << endl;
			}

			else
			{
				ss << "  " << moveinputType << "is ineffective against [" << ineffectives[move2inputType] << "]" << " inputType Pokemon." << endl;
			}
			ss << "  " << result2 << endl;
			if (gameWinner == " is a tie.")
			{
				ss << "  " << "The battle between " << inputName << " and " << pokemominputName << gameWinner << endl;
			}

			else
			{
				ss << "  " << "In the battle between " << inputName << " and " << pokemominputName << gameWinner << endl;
			}
			//ss << endl;
			out << ss.str();
		}

	}



	return 0;
}


bool ifEffective(string inputType, string key, Map<string, Set<string>> &effectivies)
{
	if (effectivies[key].count(inputType) == 1)
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool ifIneffective(string inputType, string key, Map<string, Set<string>> &ineffectives)
{
	if (ineffectives[key].count(inputType) == 1)
	{
		return true;
	}

	else
	{
		return false;
	}
}