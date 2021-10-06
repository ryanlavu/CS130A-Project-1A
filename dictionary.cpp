#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int p;

int main(int argc, char* argv[])
{
	ifstream wordBase;

	string fileName;
	vector<string> wordVector;
	int intArray[p] = {0};
	string word;
	bool trueOrFalse = true;
	fileName = argv[1];

	wordBase.open(fileName);
	if(wordBase >> word)
	{
		intArray[stringToInt(word)] = intArray[stringToInt(word)]+1;
		wordVector.push_back(word);

	}
	while(wordBase >> word)
	{
		intArray[stringToInt(word)] = intArray[stringToInt(word)]+1;
		for(int i = 0; i < wordVector.size(); i++)
		{
			if(wordVector[i] == word)
				trueOrFalse = false;
		}
		if(trueOrFalse)
			wordVector.push_back(word);
		trueOrFalse = true;
	}

	wordBase.close();
}

int stringToInt(String input) {
	
	int output;
	int c = 41;

	for(int i = 0; i < input.length(); i++) {

		output += (int(input.at(i)) * pow(c, i)) % p;

	}

	return output;

}
