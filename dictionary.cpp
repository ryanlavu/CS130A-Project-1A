#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int p;
//int *table[];

int main(int argc, char *argv[])
{
	ifstream wordBase(argv[1]);

	string fileName;
	vector<string> wordVector;
	int intArray[p] = {0};
	int totalWords = 0;
	string word = "";
	bool trueOrFalse = true;

	if(wordBase)
	{
		//intArray[stringToInt(word)] = intArray[stringToInt(word)]+1;
		getline(wordBase, word);
		wordVector.push_back(word);
		totalWords++;
		cout << word  << " if statement" << endl;
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
                        //intArray[stringToInt(word)] = intArray[stringToInt(word)]+1;
                        wordVector.push_back(word);
                }
                trueOrFalse = true;

		cout << word << " for loop" << endl;
	}

	wordBase.close();

	
	cout <<"This is the end!" << endl;
	
}

/*
int stringToInt(string input) {
	
	int output;
	int c = 41;

	for(int i = 0; i < input.length(); i++) {

		output += (int(input.at(i)) * pow(c, i)) % p;

	}

	return output;

}

void insert(string data) {

	int index = stringToInt(data);

	if(table[index]) {
		
		for(int i = 0; i < table[index].size(); i++) {

			if(!table[index][i]) {

				table[index][i] = data;
				return;

			}

		}

	}

}

string indexOfQuery(string query) {

	int index = stringToInt(query);
	String output;

	if(table[index]) {

		for(int i = 0; i < table[index].size(); i++) {

			if(table[index][i].compare(query) == 0) {

				return "exists at (" + index + "," + i + ").";

			}
			

		}

	}

	return "does not exist.";	

}

void printSlot(int slotIndex) {

	for(int i = 0; i < table[slotIndex].size(); i++) {
	
		cout << table[slotIndex][i] << " ";

	}

	cout << endl;

}

int * getCounts(int * intArray) {

	int counts[21] = {0};

	for(int i = 0, i < intArray.size(), i++) {

		if(intArray[i] > 20) continue;
		else {
			
			counts[inArray[i]]++;

		}

	}

	return counts;

}
*/
