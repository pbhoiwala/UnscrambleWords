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

#define locateFile "D:\\CSc\\Personal practice ones\\UnscrambleWords\\dictionary2.txt"       // LOCATION OF THE DICTIONARY (INPUT) FILE

void unscrambleIt(ifstream& inFile, string unWord);
bool DEBUG_CODE = false;
//#define exit "zzz"

int main(int argc, char** argv) {

	// INSTRUCTIONS

	cout << endl;
	cout << " Welcome to My Word Unscrambler " << endl;
	cout << " Enter a Scrambled Word and the program" << endl;
	cout << " will Unscramble it and display possible words" << endl;
	cout << endl << " ENTER 'zzz' TO EXIT" << endl;
	cout << endl << endl;




	//char exit = 'N';								// INITIALIZE EXIT TO 'N' (NO)

	string unWord0 = "aaa";

	while (unWord0 != "zzz" || unWord0 != "ZZZ")
	{
		ifstream inputFile;
		inputFile.open(locateFile);					// OPEN INPUT FILE (DICTIONARY)


		if (inputFile.fail()) 
		{
			cout << "**** ERROR OPENING FILE **** " << locateFile << endl;		// IF PROGRAM IS UNABLE TO OPEN THE FILE THEN DISPLAY THIS
			return EXIT_FAILURE;
		}

		else
		{

			cout << " Enter a Scrambled Word:  ";
			cin >> unWord0;
			if (unWord0 == "zzz" || unWord0 == "ZZZ") { break; }
			else
			{
				unscrambleIt(inputFile, unWord0);	// CALL FUNCTION THAT UNSCRAMBLES THE WORD
				cout << endl << endl;
			}
		}

	}
	/*cout << endl << endl << " Do you want to exit (Y or N)? ";				// ASK IF THEY WANT TO EXIT
	cin >> exit;*/
	cout << endl;




return EXIT_SUCCESS;
}

// FUNCTION - ALGORITHM THAT UNSCRAMBLES THE WORD

void unscrambleIt(ifstream& inFile, string unWord) {

	//string unWord;	
	//cout << " Enter a Scrambled Word:  ";					// ASK USER TO ENTER A WORD (STRING IN C++)
	//cin >> unWord;


	int unSize = unWord.length();							// DEFINE THE SIZE OF WORD (NUM OF LETTERS)


	string getWord;
	int match = 0;											// INITIALIZE MATCH TO '0'

	int displayPossWords = 9;								// ALL THIS DOES IS MAKES SURE THAT THE LINE "Possible Words: "
	// IS DISPLAYED ONLY ONE TIME. SO AFTER THAT LINE IS DISPLAYED ONCE
	// I WILL SET displaPossWords = 8 SO IT DOESN'T DISPLAY IT NEXT TIME


	bool found = false;										// SET FOUND = FALSE (IT IS ACTUALLY INNECESSARY)
	while (!inFile.eof())									// LOOP UNTIL THE FILE HAS ENDED
	{
		inFile >> getWord;
		if (unSize == getWord.length())						// BEFORE YOU CHECK FOR LETTERS, MAKE SURE THE SIZE OF THOSE WORDS MATCH
		{													// IF WORDS HAVE DIFFERENET SIZES, THEN THERE'S NO POINT IN GOING AHEAD

			match = 0;										// SET MATCH TO '0' EVERY TIME THE LOOP BEGINS, SO OLD VALUE OF MATCH GETS DELETED

			// INITIALIZE AN ARRAY OF 20 LETTERS
			char dontUse[20] = { 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a' };
			for (int u = 0; u < getWord.length(); u++)		// THIS 'u' LOOP LOOPS FOR ONE WORD (WORD FROM FILE)
			{

				for (int s = 0; s < getWord.length(); s++)  // THIS 's' LOOP LOOPS UNTIL ANY OF THE LETTERS OF OTHER UNSCRAMBLED 
					// WORD MATCHES THE WORD FROM FILE
				{
					if (dontUse[s] != '!')				// IF dontUse AT 's' = '!' THEN DON'T RECHECK IT
					{
						if (unWord[s] == getWord[u])	// CHECK IF LETTERS MATCH
						{
							match = match + 1;			// IF THEY DO, MATCH GETS A +1
							dontUse[s] = '!';			// AND dontUse AT 's' GETS AN '!' SO THAT IT DOESN'T LOOK FOR THAT AGAIN
							break;						// BREAK LOOP IF MATCHES
						}
					} // if dontUse
				}

			} // for u
		} // if

		// IF NUMBER OF MATCHES = NUMBER OF LETTERS IN WORD THEN THE WORD IS UNSCRAMBLEDD
		if (match == getWord.length() && match == unSize && getWord.length() == unSize)
		{
			if (displayPossWords == 9)					// REMEMBER WE SET IT EQUAL TO '9', SO NOW EVERYTHING BELOW WILL BE DISPLAYED ONCE
			{
				cout << " Word Unscrambled ! " << endl;
				cout << " List of Possible Words: ";
				displayPossWords = 8;					// NOW WE'RE SETTING IT EQUAL TO (NOT '9') LIKE '8'SO NEXT LOOP, THAT WON'T BE DISPLAYED
			}
			cout << getWord << ", ";				// DISPLAY POSSIBLE WORDS
			found = true;							// SET FOUND TO TRUE (ACTUALLY UNNECESSARY)


			//break;
		}

	} // BIG WHILE   

	// IF WORD NOT FOUND THEN DISPLAY THIS
	if (!found)
	{
		cout << " Sorry! I can't unscramble this Word" << endl;

	}



	inFile.close();						// CLOSE THE FILE

}



