using namespace std;

int stringToInt(String input) {
	
	int output;
	int p = 44;

	for(int i = 0; i < input.length(); i++) {

		output += int(input.at(i)) % p;

	}

	return output;

}
