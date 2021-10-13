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

	output = output % p;

        return output;

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

int main(int argc, char *argv[]) {

	//To read the file containing p and c values
	string getP, getC;
	ifstream pAndC(argv[1]);
	getline(pAndC,getP);
	p = stoi(getP);
	getline(pAndC,getC);
	c = stoi(getC);

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
	//This is to read in the wordbase file and hash the words into a intArray, as wlel as counting how many unique words there are
	if(wordBase)
	{
		intArray[stringToInt(word)] = intArray[stringToInt(word)]+1;
		getline(wordBase, word);
		wordVector.push_back(word);
		totalWords++;
		uniqueWords++;
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
                        intArray[stringToInt(word)]++;
                        wordVector.push_back(word);
			uniqueWords++;
                }
                trueOrFalse = true;

	}

	wordBase.close();

	//Initializes the string arrays within the hashtable to the right size and if it is zero it is null
	for(int i = 0; i < p; i++) {

		if(intArray[i] > 0) {

			hashTable[i] = new string[intArray[i]];

		}

	}
	
	//Inputs all the strings from wordVector into the hashtable
	for(int i = 0; i < wordVector.size(); i++) {
	
		int index = stringToInt(wordVector[i]);

		for(int j = 0; j < intArray[index]; j++) {


			if(hashTable[index][j] == "") {	

				hashTable[index][j] = wordVector[i];
				break;

			}

		}

	}

	//Print size of input, number of words, primary array size
	cout << "Size of input: " << totalWords << endl;
	cout << "Number of words in table: " << uniqueWords << endl;
	cout << "Primary array size: " << p << endl;

	//Find max number of collisions in a hashbucket
	int max = intArray[0];
	int maxIndex = 0;

	for(int i = 1; i < p; i++) {

		if(intArray[i] > max) {

			max = intArray[i];
			maxIndex = i;

		}

	}

	cout << "Maximum number of collisions in a hashbucket: " << max << endl;
	
	//Find amount of arrays with sizes zero through twenty and print
	int sizeArray[21] = {0};
	for(int i = 0; i < p; i++) {
	
		if(intArray[i] < 20) {

			sizeArray[intArray[i] - 1]++;

		}

	}

	cout << "The number of hashbuckets b with x elements:" << endl;

	for(int i = 0; i < 21; i++) {

		cout << "x=" << i << " : b=" << sizeArray[i] << endl;

	}

	//Print keys in the most populated bucket
	cout << "Keys in most populated bucket:";

	for(int i = 0; i < intArray[maxIndex]; i++) {

		cout << " " << hashTable[maxIndex][i];

	}

	cout << endl;
	cout << endl;

	//checks if user inputs a query file
	if(argc > 3)
	{
		//Looks through the hashtable for the word
		string query = "";
		ifstream queryFile(argv[3]);
		cout << "Queries" << endl;
		while(queryFile)
		{
			getline(queryFile, query);
			if(query.empty())
				break;
				
			int index = stringToInt(query);
			bool found;
			
			if(hashTable[index]) {

				found = false;

				for(int i = 0; i < intArray[index]; i++) {

					if(hashTable[index][i].compare(query) == 0) {

						cout << "Key \"" << query << "\" exists at (" << index << string(",") << i << ")" << endl;
						found = true;
						break;

					}

				}

				if(!found) cout << "Key \"" << query << "\" does not exist" << endl;

			}

			
			
		}
	}
	
}

