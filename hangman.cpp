#include <iostream>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

void head();
void torso();
void right_arm();
void left_arm();
void right_leg();
void full_body();
void lifeStatus(int value);
bool binarySearch(char array[], int size, int key);
string randomWord(int value);
int charSearch(char array[], int size, char letter);

int main()
{
	string newWord;
	char input;
	int randomNumber;
	int *letterArray = new int[100];
	int lifeCount = 0;
	int deathCount = 0;
	char *charArray = new char[newWord.size() + 1];
	char letter;
	bool found = false;
	bool dead = false;

	do
	{
		cout << "Press any key to start Hang Man: " << endl;
		cout << "Press 'y' to quit." << endl;
		cin >> input;

		do
		{
			//Starts the game
			cout << "Welcome to Hang Man!" << endl << endl;

			randomNumber = rand() % 5;
			newWord = randomWord(randomNumber);

			//Store each letter from 'newWord' into string array
			memcpy(charArray, newWord.c_str(), newWord.size());

			//Tests random word and number combinations
//			cout << "Your word: " << newWord << ". And your number is: " << randomNumber << endl << endl;
//			cout << "Your word size is: " << newWord.size() << endl << endl;

			do
			{
				cout << "Guess a letter: ";
				cin >> letter; //stores letter that user guesses

				//Read through array to compare each index value with the guessed letter
				found = binarySearch(charArray, newWord.size(), letter);//binary search checks for letter in char array

				if (found)
				{
					cout << "You've guessed a correct letter!" << endl << endl;
					lifeCount++;
					cout << "Your lifeCount: " << lifeCount << endl;
					lifeStatus(deathCount);
					cout << endl << endl;
					cout << "Your number of remaining letters: " << (newWord.size() - lifeCount) << endl << endl;
					if (lifeCount == newWord.size())
					{
						dead = true;
					}
					else
					{
						dead = false;
					}
				}
				else if (!found)
				{
					cout << "Your guess was incorrect..." << endl << endl;
					deathCount++;
					cout << "Your deathCount: " << deathCount << endl;
					lifeStatus(deathCount);
					cout << endl << endl;
					cout << "Your number of remaining letters: " << (newWord.size() - lifeCount) << endl << endl;
					if (deathCount == 6)
					{
						dead = true;
					}
					else
					{
						dead = false;
					}
				}
				else
				{
					cout << "This message should not occur..." << endl << endl;
				}

			} while (!dead);

			cout << "The game is over!" << endl << endl;
			cout << "Press any key to play again. Enter 'y' to quit." << endl << endl;
			cin >> input;
			deathCount = 0;
			lifeCount = 0;

		} while (input != 'y');
	
	} while (input != 'y');

	system("pause");

	return 0;

}

string randomWord(int value)
{
	string word;

	switch (value)
	{
	case 0:
		word = "bacon";
		break;

	case 1:
		word = "chipotle";
		break;

	case 2:
		word = "pork";
		break;

	case 3:
		word = "ham";
		break;

	case 4:
		word = "brisket";
		break;

	default:
		cout << "There is no word. That's a problem..." << endl << endl;
	}
	return word;
}

void head()
{
	cout << "(-.-)" << endl;
}

void torso()
{
	cout << "(-.-)" << endl << "  |  " << endl;
}

void right_arm()
{
	cout << "(-.-)" << endl << "  |-  " << endl;
}

void left_arm()
{
	cout << "(-.-)" << endl << " -|-  " << endl;
}

void right_leg()
{
	cout << "(-.-)" << endl << " -|-  " << endl << " /" << endl;
}

void full_body()
{
	cout << "(-.-)" << endl << " -|-  " << endl << " / L   " << endl;
}

bool binarySearch(char array[], int size, int key) {
	int start = 1, end = size;
	int mid = (start + end) / 2;

	while (start <= end&&array[mid] != key) {
		if (array[mid]<key) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
		mid = (start + end) / 2;
	}// While Loop End

	if (array[mid] == key)
		return true; //Returnig to main
	else
		return false;//Returnig to main

	cout << "\n\n\n";
}// binarySearch Function Ends Here

void lifeStatus(int value)
{
	switch (value)
	{
	case 1:
		head();
		cout << endl << endl;
		break;

	case 2:
		torso();
		cout << endl << endl;
		break;

	case 3:
		right_arm();
		cout << endl << endl;
		break;

	case 4:
		left_arm();
		cout << endl << endl;
		break;

	case 5:
		right_leg();
		cout << endl << endl;
		break;

	case 6:
		full_body();
		cout << "Oh, dear... You are dead!" << endl << endl;
		break;
	}
}

int charSearch(char array[], int size, char letter)
{
	int count = 0;
	char * pch;

	pch = strchr(array, letter);
	while (pch != NULL)
	{
		count++;
	}
	return count;
}