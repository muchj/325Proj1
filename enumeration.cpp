#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <ctime>

using namespace std;

#define inputFile "MSS_Problems.txt"
#define ouputFile "MSS_Results.txt"

int * fillArray(string fileName, int array[]);
int enumeration(int A[], int size);

int main(int argc, char* argv[])
{
	
	//int size;
	//int A[size];
	int A[] = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};

	/*switch(argc)
	{	
		// No command line argument, use inputFile.
		case '1':
		{				
			fillArray(inputFile, A);
		}			
		break;	

		// Use argv[1] if it exists.
		default:
		{			
			fillArray(argv[1], A);
		}
		break;		
	}*/

	
	for (int i = 0; i < 10; i++)
	{
		cout << "\n" << A[i];
	}

	int sum = enumeration(A, 10);
	cout << "\nSum: " << sum << endl;
	
	return 0;
}

/******************************************************************************
Update later.
******************************************************************************/
int * fillArrayFromFile(string fileName, int array[])
{
	fstream inFile;
	inFile.open(fileName.c_str());
}

/******************************************************************************
Brute force enumeration function. 3 loops, should be O(n^3).
Receives: an array of integers and the length of the array.
Returns: An integer equal to the longest contigious sum in the array.
******************************************************************************/
int enumeration(int A[], int size)
{
	int sum = 0; // Return variable shouldn't be negative.
	int current; // Keep track of current value in loops.
	int j, k;

	// i is the first index of the summation.
	for (int i = 1; i < size - 1; i++)
	{
		// j is the last index of the summation.
		for (j = i + 1; j < size; j++)
		{
			current = 0; // Zero current for each run.
			// Let k run from i to j.
			for (k = i; k <= j; k++)
			{
				current = current + A[k];
			}
		
			// Update sum only if current is greater.
			if (current > sum)
				sum = current;
		}
	}
	return sum;
}
