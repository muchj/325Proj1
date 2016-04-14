#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <ctime>

using namespace std;

#define inputFile "MSS_Problems.txt"
#define ouputFile "MSS_Results.txt"

long getCount(string fileName);
int * fillArray(string fileName, int array[]);
int enumeration(int A[], long size);

int main(int argc, char* argv[])
{
	
	//int size;
	//int A[size];
	//int A[] = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};

	long count; 
	
	// Use get count to get the file size. 
	count = getCount(inputFile);
	cout << "File count: " << count << endl;

	// Put the file size into A.
	int A[count];

	// This block puts the entries into A.
	ifstream fileIn;
	fileIn.open(inputFile);	

	if(fileIn)
	{
		int i = 0;
		while (!fileIn.eof())
		{
			fileIn >> A[i];		
			i++;
		}		
		fileIn.close();	
	}

	
	

	/*switch(argc)
	{	
		// No command line argument, use inputFile.
		case '1':
		{				
			//fillArray(inputFile, A);
			long count = 0; // Use long to allow for large files.
			int entry;
			ifstream inputFile;
			string fileIn = "MSS_Problems.txt";
			inputFile.open(fileIn.c_str());
			//count = getCount();

			while (!inputFile.eof())
			{
				inputFile >> entry;		
					count++;
			}
			count--; // Can't figure out why it's one over everytime.	
			inputFile.close();	

			cout << "File count: " << count << endl;
		}			
		break;	

		// Use argv[1] if it exists.
		default:
		{			
			//fillArray(argv[1], A);
			count = getCount(argv[1]);
			cout << "File count: " << count << endl;
		}
		break;		
	}

	
	for (int i = 0; i < 10; i++)
	{
		cout << "\n" << A[i];
	}*/

	int sum = enumeration(A, count);
	cout << "\nSum: " << sum << endl;
	
	return 0;
}

/******************************************************************************
Function to get the number of integers in a file. 
Receives a string as a file name.
Returns the number of integers in the file.
******************************************************************************/
long getCount(string fileName)
{
	long count = 0; // Use long to allow for large files.
	int entry;

	ifstream fileIn;
	fileIn.open(fileName.c_str());	

	if(fileIn)
	{
		while (!fileIn.eof())
		{
			fileIn >> entry;		
				count++;
		}		
		fileIn.close();	
	}
	return count;
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
int enumeration(int A[], long size)
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
