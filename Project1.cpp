/*
CS325 - Project 1 
Contributors - Joseph Cuellar, Adam Much, Ryan Peters
Instructions: 
*/

#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <algorithm>
#include <ctime>

#define MAX_ARRAY_SIZE 100
#define MIN_ELEMENT -5
#define MAX_ELEMENT 15

using namespace std;

struct results{
    int sum;
    int startIdx;
    int endIdx;
};

////////////////////////////////////////////
// Function Prototypes
////////////////////////////////////////////
void output(int* array, int arrSize, int sum, int startIdx, int endIdx, int algNo);
int inputFileLineCount();
void parseInputFile(int lineCount);
void testCorrectness();
void testRunTime();

////////////////////////////////////////////
// Algorithm Prototypes
////////////////////////////////////////////
results mssAlgorithm1(int* array, int size);
results mssAlgorithm2(int* array, int size);
results mssAlgorithm3(int* array, int f, int l);
results mssAlgorithm4(int* array, int size);

////////////////////////////////////////////
// MAIN
////////////////////////////////////////////
int main(int argc, char *argv[]){
	if( argc > 1)
	{
		// Had to assign a string for some reason.
		string choice = argv[1];

		if(choice == "-r") //Testing Run Time
		{
			testRunTime();
		}
		else if(choice == "-c") //Testing Correctness
		{
			testCorrectness();
		}
		else if(choice == "-e") //Testing Example
		{
			cout << "\nThis option hasn't been implemented yet.\n";
			//testExample();
		}
		else
		{
			cout << "You did not enter correct arguments.\n" << endl;
			cout << "Please add -r,-c, or -e as an argument." << endl;
		}
	}

	//This will default to test correctness if not enough arguments are entered.
	else
		testCorrectness(); 	

	return 0;
}

////////////////////////////////////////////
//START - Programs
////////////////////////////////////////////
void output(int* array, int arrSize, int sum, int startIdx, int endIdx, int algNo)
{
    ofstream out;
    
    out.open("MSS_Results.txt", ofstream::out | ofstream::app);	
    
	// Print the algorithm number.
	out << "Algorithm " << algNo << ":\n";
	cout << "Algorithm " << algNo << ":\n";

	// Print the complete array.
	out << "\nComplete array:\n";
	cout << "\nComplete array:\n";
	for(int i = 0; i < arrSize; i++)
	{
		out << array[i] << ' ';
		cout << array[i] << ' ';
	}

	// Print the maximum subsequence.
	out << "\n\nMaximum subsequence:\n";
	cout << "\n\nMaximum subsequence:\n";	
	
	for(int i = startIdx; i <= endIdx; i++)
	{
		out << array[i] << ' ';
		cout << array[i] << ' ';
	}    
	
	// Print the sum.
	out <<"\n\nSum of MSS:\n" << sum << endl << endl;
	cout <<"\n\nSum of MSS:\n" << sum << endl << endl;	
	
	out.close(); 	
}
////////////////////////////////////////////
//	inputFileLineCount
//	- Gets line count of MSS_Problems.txt
////////////////////////////////////////////
int inputFileLineCount()
{
	int lineCount = 0;
	string line;
	ifstream inputFile("MSS_Problems.txt");
	while (inputFile.good())
	{
		getline(inputFile, line);
		//cout << line << endl;
		if(line == "")
		{
			break;
		}
		else
		{
			lineCount++;
		}
	}
	//cout << "Number of lines is " << lineCount << endl;
	return lineCount;
}
////////////////////////////////////////////
// 	parseInputFile
//	- Is THE function called that is used for grading
//	- It reads in MSS_Problems.txt
//	- Crunches the sum for all four algorithms
//	- Outputs the result onto the screen AND MSS_Results.txt for grading 
////////////////////////////////////////////
void parseInputFile(int lineCount)
{
	// Delimiters
	char comma = ',';
	char leftBracket = '[';
	char rightBracket = ']';
	
	ifstream inputFile("MSS_Problems.txt");
	
	// Get characters until an int is next.
	char c; 
	int nextInt;
	
	int A[lineCount][MAX_ARRAY_SIZE]; // Make lineCount number of arrays.

	int arraySize[lineCount]; // Corresponding array sizes.

	int size = 0; // current size of one of the arrays.
	int i = 0; // Incremental number for line (array) from input lineCount.
	int j = 0; // A[i][j]
	
	if (inputFile)
	{
		while(!inputFile.eof())
		{
			inputFile >> c;
			if (c == comma || c == leftBracket)// We know an int is next.
			{					
				inputFile >> nextInt;				
				
				// Plug the int into its spot, and increment the spot and size.
				A[i][j] = nextInt;				
				j++;
				size++;
			}

			if (c == rightBracket) // End of an array.
			{				
				// Plug in the array size, reset size to 0, and move to next array.
				arraySize[i] = size;
				size = 0;
				i++;
				j = 0;				
			}			
		}
		inputFile.close();

		// Should be able to run algorithms on A[i][] and arraySize[i] here.

		results resOut;
		for (int k = 0; k < lineCount; k++)
		{
			resOut = mssAlgorithm1(A[k], arraySize[k]);
			output(A[k], arraySize[k], resOut.sum, resOut.startIdx, resOut.endIdx, 1);

			resOut = mssAlgorithm2(A[k], arraySize[k]);
			output(A[k], arraySize[k], resOut.sum, resOut.startIdx, resOut.endIdx, 2);

			// Alg 3 should always start at index 0, right?
			resOut = mssAlgorithm3(A[k], 0, arraySize[k]);		
			output(A[k], arraySize[k], resOut.sum, resOut.startIdx, resOut.endIdx, 3);

			resOut = mssAlgorithm4(A[k], arraySize[k]);
			output(A[k], arraySize[k], resOut.sum, resOut.startIdx, resOut.endIdx, 4);
		}
	}

	else
		cout << "\nUnable to open \"MSS_Problems.txt\"." << endl;
	
}
////////////////////////////////////////////
//	testCorrectness
//	- Used for calculating grade
////////////////////////////////////////////
void testCorrectness()
{	
	parseInputFile(inputFileLineCount());
}

////////////////////////////////////////////
//	testRunTime
//	- Used for algorithm analysis.
////////////////////////////////////////////
void testRunTime()
{
	// Seed the random generator.
	unsigned seed;
	seed = time(0);
	srand(seed);

	// User selects which algorithm to run.	
	cout << "\nWhich algorithm do you wish to test? (1, 2, 3, or 4) ";
	int algorithmNumber;
	cin >> algorithmNumber;

	// User selects the number of array elements.
	cout << "\nHow many elements in the array? ";
	unsigned long numberOfElements;
	cin >> numberOfElements;

	// Create the array.
	int A[numberOfElements];

	// Assign random integers to the array.
	for (unsigned long i = 0; i < numberOfElements; i++)
	{
		A[i] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) - MIN_ELEMENT; 
	}

	clock_t t;
	results testTime;

	// Time the chosen algorithm.
	t = clock();
	switch (algorithmNumber) // 1 extra calculation shouldn't hurt the results.
	{
		case 1:	testTime = mssAlgorithm1(A, numberOfElements);
				break;

		case 2:	testTime = mssAlgorithm2(A, numberOfElements);
				break;

		case 3:	testTime = mssAlgorithm3(A, 0, numberOfElements);
				break;

		default: testTime = mssAlgorithm4(A, numberOfElements);
				 algorithmNumber = 4;
	}
	t = clock() - t;

	// Report the results.
	cout << endl << numberOfElements << " array elements took " << t;
<<<<<<< HEAD
	cout << " micro seconds to process with algorithm " << algorithmNumber;
	cout << ".\n\n";
=======
	cout << " ms to process with algorithm " << algorithmNumber << ".\n\n";
>>>>>>> origin/Structs
}

////////////////////////////////////////////
//END - Programs
////////////////////////////////////////////

////////////////////////////////////////////
// START - Algorithms
////////////////////////////////////////////

////////////////////////////////////////////
// Algorithm 1 - Enumeration
////////////////////////////////////////////
results mssAlgorithm1(int* array, int size)
{
	int i, j, k, sum;
	struct results r;
	r.sum = 0;
	r.startIdx = -1;
	r.endIdx = -1;
	
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			sum = 0;
			for(k = i; k <= j; k++){
				sum += array[k];
			}
			if(sum > r.sum){
				r.sum = sum;
				r.startIdx = i;
				r.endIdx = j;
			}
		}
	}
        
        return r;
}

////////////////////////////////////////////
//Algorithm 2 - Better Enumeration
////////////////////////////////////////////
results mssAlgorithm2(int* array, int size)
{
	int i, j, sum;
        results r;
        r.sum = 0;
        r.startIdx = 0;
        r.endIdx = 0;
	
	for(i = 0; i < size; i++){
		sum = 0;
		j = i;
		for(j = i; j < size; j++){
			sum += array[j];
			if(sum > r.sum){
				r.sum = sum;
				r.startIdx = i;
				r.endIdx = j;
			}
		}
	}
        
        return r;
}
 
////////////////////////////////////////////
//Algorithm 3 - Divide and Conquer
////////////////////////////////////////////
results mssAlgorithm3(int* array, int f, int l)
{
	int sum = 0;
	int maxLeft = 0;
	int maxRight = 0;
	int maxCross = 0;
    int startIdx = -1;
    int endIdx = -1;
    int mid = (f + l) / 2;
    results r;
	r.sum = 0;
	r.startIdx = 0;
	r.endIdx = 0;
	results left;
	left.sum = 0;
	left.startIdx = 0;
	left.endIdx = 0;
	results right;
	right.sum = 0;
	right.startIdx = 0;
	right.endIdx = 0;
	
	if (l == f)
	{
            r.sum = array[l];
            r.startIdx = f;
            r.endIdx = l;
            return r;
	}
	
	for(int i = mid; i >= f; i--)
	{
		sum += array[i];
		if(sum > maxLeft)
                {
                    maxLeft = sum;
                    startIdx = i;
                }
	}
	
	sum = 0;
	
	for(int i = (mid + 1); i < l; i++)
	{
		sum += array[i];
		if(sum > maxRight)
                {
                    maxRight = sum;
                    endIdx = i;
                }
	}
		
	maxCross = (maxLeft + maxRight);
        
    r.sum = maxCross;
    r.startIdx = startIdx;
    r.endIdx = endIdx;
	left = mssAlgorithm3(array, f, mid);
	right = mssAlgorithm3(array, mid + 1, l);
	
        
        if(left.sum > r.sum)
        {
            if(left.sum > right.sum)
            {
                return left;
            }
        }
        
        if(right.sum > left.sum)
        {
            if(right.sum > r.sum)
            {
                return right;
            }
        }
    return r;   
}

////////////////////////////////////////////
//Algorithm 4 - Linear-time
////////////////////////////////////////////
results mssAlgorithm4(int* array, int size)
{
    int maxNow = 0; 
    int maxBest = 0;
    int startBest = -1;
    int startNow = -1;
    int stopBest = -1;
    results r;
	int v;
    
    for(int i = 0; i < size; i++)
    {
        v = maxNow + array[i];
        if(v > 0)
        {   
            if(maxNow == 0)
            {
                startNow = i;
            }
            maxNow = v;
        }
        else
        {
            maxNow = 0;
        }
        
        if(maxNow > maxBest)
        {
            maxBest = maxNow;
            stopBest = i;
            startBest = startNow;
        }
    }
    r.sum = maxBest;
    r.startIdx = startBest;
    r.endIdx = stopBest;

    return r;
}
////////////////////////////////////////////
//END - Algorithms
////////////////////////////////////////////
