#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int p;
int c;
string table[2][3] = {};

int stringToInt(string input) {

        int output;

        for(int i = 0; i < input.length(); i++) {

                output += (int(input.at(i)) * int(pow(c, i))) % p;

        }

        return output;

}

void insert(string data, int intArray[]) {

	int index = stringToInt(data);

	if(table[index]) {
		
		for(int i = 0; i < intArray[index]; i++) {

			if(table[index][i] == "") {

				table[index][i] = data;
				return;

			}

		}

	}

}

string indexOfQuery(string query, int intArray[]) {

	int index = stringToInt(query);
	string output = "does not exist";

	if(table[index]) {

		for(int i = 0; i < intArray[index]; i++) {

			if(table[index][i].compare(query) == 0) {

				output = "exists at (" + index + string(",");
				output += i;
				output += ").";
				return output;

			}
			

		}

	}

	return output;	

}

void printSlot(int slotIndex, int intArray[]) {

	for(int i = 0; i < intArray[slotIndex]; i++) {
	
		cout << table[slotIndex][i] << " ";

	}

	cout << endl;

}

void printCounts(int intArray[], int arraySize) {

	int counts[21] = {0};

	for(int i = 0; i < 21; i++) {

		if(intArray[i] > 20) continue;
		else {
			
			counts[intArray[i]]++;

		}

	}

	for(int i = 0; i < 21; i++) {

		cout << "x=" << i << " : b=" << counts[i] << endl;

	}

}

int getLargestSlotIndex(int intArray[], int arraySize) {

	int max = intArray[0];
	int indexMax = 0;

	for(int i = 1; i < arraySize; i++) {

		if(intArray[i] > max) {

			max = intArray[i];
			indexMax = i;

		}

	}

	return indexMax;

}

int main(int argc, char *argv[])
{

	//To read the file containing p and c values
	string getP, getC;
	ifstream pAndC(argv[1]);
	getline(pAndC,getP);
	p = stoi(getP);
	cout << "Printing p: " << p << endl;
	getline(pAndC,getC);
	c = stoi(getC);
	cout << "Printing c: " << c << endl;

	pAndC.close();


	//create hashtable
	string **hashTable = new string *[p];


	ifstream wordBase(argv[2]);

	string fileName;
	vector<string> wordVector;
	int intArray[p] = {0};
	int totalWords = 0;
	int uniqueWords = 0;
	string word = "";
	bool trueOrFalse = true;
	cout << stringToInt("asd")  << endl;
	//This is to read in the wordbase file and hash the words into a intArray, as wlel as counting how many unique words there are
	if(wordBase)
	{
		intArray[stringToInt(word)] = intArray[stringToInt(word)]+1;
		getline(wordBase, word);
		wordVector.push_back(word);
		totalWords++;
		uniqueWords++;
		cout << word  << " if statement" << endl;
		cout << intArray[0] << " if statement first line int" << endl;
	}
	while(wordBase)
	{
		getline(wordBase, word);
		if(word.empty())
			break;

		totalWords++;

                for(int i = 0; i < wordVector.size(); i++)
                {
                        if(wordVector[i] == word)
                                trueOrFalse = false;
                }
                if(trueOrFalse)
                {
                        intArray[stringToInt(word)] = intArray[stringToInt(word)]+1;
                        wordVector.push_back(word);
			uniqueWords++;
                }
                trueOrFalse = true;

		cout << word << " for loop" << endl;
	}

	wordBase.close();


	//checks if user inputs a query file
	if(argc > 3)
	{
		//Looks through the hashtable for the word
		string query = "";
		ifstream queryFile(argv[3]);
		while(queryFile)
		{
			getline(queryFile, query);
			if(word.empty())
				break;
			
			
		}
	}

	
	cout <<"This is the end!" << endl;
	
}

