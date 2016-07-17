/*
* File:   main.cpp
* Author: Preet
*
* Created on March 19, 2015, 3:14 PM
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

#define locateFile "G:\\CSc\\Personal practice ones\\UnscrambleWords\\dictionary.doc"       //

void unscrambleIt(ifstream& inFile);
bool DEBUG_CODE = false;
#define exit "zzz"

int main(int argc, char** argv) {



	ifstream inputFile;
	inputFile.open(locateFile);
	unscrambleIt(inputFile);

















	return 0;
}

void unscrambleIt(ifstream& inFile)
{

	string unWord;


	cout << " Enter an unscrambled word:  ";
	cin >> unWord;





	if (DEBUG_CODE){ cout << "letters to look for " << unWord[0] << ", " << unWord[1] << ", " << unWord[2] << unWord[3] << endl; }

	int unSize = unWord.length();
	if (DEBUG_CODE){ cout << "Size of your word" << unSize << endl; }



	string getWord;
	int match = 0;
	while (!inFile.eof())                         // NOT END OF FILE
	{
		inFile >> getWord;
		if (unSize == getWord.length())           // MAKE SURE WORD SIZE MATCHES
		{
			match = 0;
			if (DEBUG_CODE){ cout << " chosen word " << getWord << endl; }

			for (int u = 0; u<getWord.length(); u++)
			{
				if (DEBUG_CODE){ cout << " length of getWord " << getWord.length() << endl; }
				for (int s = 0; s<getWord.length(); s++)
				{
					if (unWord[u] == getWord[s])
					{
						if (DEBUG_CODE){ cout << " letters of getWord " << getWord[s] << endl; }
						match = match + 1;             // THIS MESSES THINGS UP
						if (DEBUG_CODE){ cout << " match = " << match << endl; }
						break;
					}

				} // for s
				if (match == match + 1)
					break;
			} // for u
		} // if
		if (DEBUG_CODE){ cout << endl; }
		if (match == getWord.length() && match == unSize)
		{
			cout << " WORD UNSCRAMBLED " << endl;
			cout << " It is: " << getWord << endl;
			break;
		}

	} // BIG WHILE   
	inFile.close();


}