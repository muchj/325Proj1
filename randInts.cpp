#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ctime>

using namespace std;

int main(int argc, char* argv[])
{
	int min, max;
	long total;
	string fileName;
	ofstream outputFile;
	unsigned seed;

	seed = time(0);
	srand(seed);

	cout << "How many randoms? ";
	cin >> total; // Number of randoms.

	cout << "What is the minimum? ";
	cin >> min; // Minimum int, can be negative.

	cout << "What is the maximum? ";
	cin >> max; // Maximum int.

	cin.get();
	cout << "Into which file? ";
	getline(cin, fileName);
	
	outputFile.open(fileName.c_str());
	
	int num;
	for (long i = 0; i < total; i++)
	{
		num = rand() % (max - min + 1) + min;
		outputFile << num;
		
		if (total - i > 1) // No space after last entry.
			outputFile << " ";

		if ((i + 1)% 20 == 0) // This just makes the file look nicer.
			outputFile << "\n";
	}

	outputFile.close();
	
	return 0;
}
