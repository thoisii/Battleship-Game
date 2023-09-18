/*
	Imagine we are using a two-dimensional array as the basis for creating the game battle- ship. In the game of battleship a ‘~’ character entry in the array represents ocean (i.e., not a ship), a ‘#’ character represents a place in the ocean where part of a ship is present, and a ‘H’ character represents a place in the ocean where part of a ship is present and has been hit by a torpedo. Thus, a ship with all ‘H’ characters means the ship has been sunk. Declare a two-dimensional char array that is 25 by 25 that represents the entire ocean and an If statement that prints “HIT” if a torpedo hits a ship given the coordinates X and Y. Write a C++ program that will read in a file representing a game board with 25 lines where each line has 25 characters corresponding to the description above.

	You should write a function called Fire that will take an X and Y coordinate and print “HIT” if a ship is hit and “MISS” if a ship is missed. If a ship is HIT you should update the array with an ‘H’ character to indicate the ship was hit. If a ship is hit that has already been hit at that location you should print “HIT AGAIN”. You should write a second function called FleetSunk that will determine if all the ships have been sunk. Your C++ program must then call these functions until all the ships have been sunk at which point the program should display “The fleet was destroyed!”.

	Your game loop logic (the main logic of a game) should like like the following:

	do {
		Fire(x, y, gameBoard);
	} while(!FleetSunk(gameBoard));
*/

//Include statements
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Global declarations: Constants and type definitions only -- no variables
const int numRows = 25;
const int numCols = 25;
//Function prototypes
void infileArray(char array[][25], int col, int row);
void fillArray(char array[][25], int col, int row);
void PrintArray(char array[][25], int col, int row);

void Fire(int x, int y, char in[][25], char out[][25]);
bool FleetSunk(char in[][25], char out[][25], int col, int row);

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Trenton Hoisington -- Lab08" << endl << endl;

	//Variable declarations
	ifstream infile;

	char fleet[numRows][numCols];
	char gameBoard[numRows][numCols];
	infile.open("Fleet.txt");

	int x, y;
	int turncount = 0;

	infileArray(fleet, numCols, numRows);
	fillArray(gameBoard, numCols, numRows);

	//Program logic
	do {
		turncount++;
		cout << "Turn " << turncount << ": " << endl;
		cout << "Enter an X corrdinate (1-25) :" << endl;
		cin >> x;
		cout << "Enter a Y corrdinate (1-25) :" << endl;
		cin >> y;

		system("cls");

		Fire(x - 1, y - 1, fleet, gameBoard);
		cout << endl;
		PrintArray(gameBoard, numCols, numRows);

		system("pause");
		system("cls");

	} while (!FleetSunk(fleet, gameBoard, numCols, numRows)); // ends game


	//Closing program statements
	cout << "The fleet was destroyed!" << endl;
	cout << "Game lasted " << turncount << "turns." << endl;
	cout << endl;
	PrintArray(gameBoard, numCols, numRows);


	system("pause");
	return 0;
}



//Function Definitions


// checks if guess has hit a ship
void Fire(int x, int y, char in[][25], char out[][25]) {

	if (out[y][x] == 'H') {
		cout << "HIT AGAIN" << endl;
	}
	else if (in[y][x] == '#') {
		out[y][x] = 'H';
		cout << "HIT!" << endl;
	}
	else {
		out[y][x] = 'M';
		cout << "MISS..." << endl;
	}

}


// check if all fleet members have been hit
bool FleetSunk(char in[][25], char out[][25], int col, int row) {
	bool sunk{ true };
	for (int row2 = 0; row2 < row; ++row2)
		for (int col2 = 0; col2 < col; ++col2)

			if (in[row2][col2] == '#') {
				if (out[row2][col2] != 'H') {
					sunk = false;
				}
			}
	return sunk;
}



// fill fleet with map in file
void infileArray(char array[][25], int col, int row) {
	ifstream infile;
	infile.open("Fleet.txt");
	if (!infile)
	{
		cout << "Unable to open file. " << endl;
	}
	else
	{
		for (int row2 = 0; row2 < row; ++row2)
			for (int col2 = 0; col2 < col; ++col2)
				infile >> array[row2][col2];
		//infile.get(array[row2][col2]);

		infile.close();
	}
}


// fill gameboard
void fillArray(char array[][25], int col, int row) {
	for (int row2 = 0; row2 < row; ++row2)
		for (int col2 = 0; col2 < col; ++col2)
			array[row2][col2] = '~';

}



// Print current gameboard array and style
void PrintArray(char array[][25], int col, int row) {

	cout << "* \t1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5\n" << endl;

	for (int row2 = 0; row2 < row; ++row2)
	{
		cout << row2 + 1 << "\t";
		for (int col2 = 0; col2 < col; ++col2)
		{
			cout << array[row2][col2];
			cout << " ";
		}
		cout << endl;
	}
	cout << endl << endl;

}
