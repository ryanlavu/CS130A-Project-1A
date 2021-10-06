#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	ifstream wordBase;

	string fileName;
	vector<string> wordVector;
	vecotr<int> intVector;
	string word;
	bool trueOrFalse = true;
	fileName += argv[1];

	wordBase.open(fileName);
	if(wordBase >> word)
	{
		intVecotr.push_back(stringToInt(word));
		wordVector.push_back(word);

	}
	while(wordBase >> word)
	{
		intVecotr.push_back(stringToInt(word));
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
	int p = 44;

	for(int i = 0; i < input.length(); i++) {

		output += int(input.at(i)) % p;

	}

	return output;

}
