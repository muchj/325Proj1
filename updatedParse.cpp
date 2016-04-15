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
using namespace std;

void output(int* array, int arrSize, int sum, int startIdx, int endIdx);
////////////////////////////////////////////
// START - Algorithms
////////////////////////////////////////////
////////////////////////////////////////////
// Algorithm 1 - Enumeration
////////////////////////////////////////////

void mssAlgorithm1(int* array, int size){
	int i, j, k, sum;
        int startIdx = -1;
        int endIdx = -1;
	int maxSum = array[0];
	
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			sum = 0;
			for(k = i; k < j; k++){
				sum += array[k];
			}
			if(sum > maxSum){ 
				maxSum = sum;
                                startIdx = i;
                                endIdx = j;
			}
		}
	}
        
        output(array, size, maxSum, startIdx, endIdx);
}
////////////////////////////////////////////
//Algorithm 2
////////////////////////////////////////////

void mssAlgorithm2(int* array, int size){
	int i, j, sum;
 	int startIdx = -1;
        int endIdx = -1;
	int maxSum = array[0];
	
	for(i = 0; i < size; i++){
		sum = 0;
		j = i;
		for(j = i; j < size; j++){
			sum += array[j];
			if(sum > maxSum){
				maxSum = sum;
                                startIdx = i;
                                endIdx = j;
			}
		}
	}
        
        output(array, size, maxSum, startIdx, endIdx);
}
////////////////////////////////////////////
//Algorithm 3
////////////////////////////////////////////
int mssAlgorithm3(int* array, int f, int l)
{
	int sum = 0;
	int maxLeft = 0;
	int maxRight = 0;
	int maxCross = 0;
        int mid = (f + l) / 2;
	
	if (f == l)
	{
		return array[0];
	}
	
	mid = (f + l) / 2;
	
	for(int i = mid; i >= f; i--)
	{
		sum += array[i];
		maxLeft = max(sum, maxLeft);
	}
	
	sum = 0;
	
	for(int i = (mid + 1); i < l; i++)
	{
		sum += array[i];
		maxRight = max(sum, maxRight);
	}
		
	maxCross = (maxLeft + maxRight);
	
	int max1 = mssAlgorithm3(array, f, mid);
	int max2 = mssAlgorithm3(array, mid + 1, l);
	
	
	return max(max(maxCross, max1), max2);
	
	
}
////////////////////////////////////////////
//Algorithm 4
////////////////////////////////////////////
void mssAlgorithm4(int* array, int size)
{
    int maxNow = 0; 
    int maxBest = 0;
    int startBest = -1;
    int startNow = -1;
    int stopBest = -1;
    
    for(int i = 0; i < size; i++)
    {
        int v = maxNow + array[i];
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
    
    output(array, size, maxBest, startBest, stopBest);    
}
////////////////////////////////////////////
//END - Algorithms
////////////////////////////////////////////

////////////////////////////////////////////
//START - Programs
////////////////////////////////////////////
void output(int* array, int arrSize, int sum, int startIdx, int endIdx)
{
    ofstream out;
    
    out.open("MSS_Results.txt", ofstream::out | ofstream::app);
    
    for(int i = 0; i < arrSize; i++)
    {
        out << array[i] << ' ';
    }
    out << '\n';
    
    for(int i = startIdx; i <= endIdx; i++)
    {
        out << array[i] << ' ';
    }
    out << '\n';
    
    out << sum << '\n';
    
    out.close();    
}
////////////////////////////////////////////
//	inputFileLineCount
//	- Gets line count of MSS_Problems.txt
////////////////////////////////////////////
int inputFileLineCount(){
	int lineCount = 0;
	string line;
	ifstream inputFile("MSS_Problems.txt");
	while (inputFile.good())
	{
		getline(inputFile, line);
		cout << line << endl;
		if(line == "")
		{
			break;
		}
		else
		{
			lineCount++;
		}
	}
	cout << "Number of lines is " << lineCount << endl;
	return lineCount;
}
////////////////////////////////////////////
// 	parseInputFile
//	- Is THE function called that is used for grading
//	- It reads in MSS_Problems.txt
//	- Crunches the sum for all for algorithms
//	- Outputs the result onto the screen AND MSS_Results.txt for grading 
////////////////////////////////////////////
void parseInputFile(int lineCount){
		
		char comma = ',';
		char leftBracket = '[';
		char rightBracket = ']';
		
		ifstream inputFile("MSS_Problems.txt");
		ofstream outputFile("tempFile"); // Used for testing.
		char c;
		int nextInt;
		
		int A[lineCount][100]; // Make lineCount number of arrays.

		int arraySize[lineCount]; // Corresponding array sizes.

		int size = 0; // current size of one of the arrays.
		int i = 0; // Incremental number for line (array) from input lineCount.
		int j = 0; // A[i][j]
		
		if (inputFile && outputFile)
		{
			while(!inputFile.eof())
			{
				inputFile >> c;
				if (c == comma || c == leftBracket)// We know an int is next.
				{
					// Used for testing.
					inputFile >> nextInt;
					outputFile << nextInt;
					outputFile << ' ';
					
					// Plug the int into its spot, and increment the spot and size.
					A[i][j] = nextInt;
					//cout << nextInt << "\t" << A[i][j] << endl;
					j++;
					size++;
				}

				if (c == rightBracket) // End of an array.
				{
					// Used for testing.
					outputFile << '\n';
					
					// Plug in the array size, reset size to 0, and move to next array.
					arraySize[i] = size;
					size = 0;
					i++;
					j = 0;
					
				}
				
			}
		}
		inputFile.close();
		outputFile.close();
		
		// Should be able to run algorithms on A[i][] and arraySize[i] here.

		for (int k = 0; k < lineCount; k++)
		{
			mssAlgorithm1(A[k], arraySize[k]);
		}
		//cout << "Now calculating line # " << lineCount + 1 << endl;	
}
////////////////////////////////////////////
//	testCorrectness
//	- Used for calculating grade
////////////////////////////////////////////
void testCorrectness()
{
	int numberOfArraysForCalc = inputFileLineCount();
	
	parseInputFile(numberOfArraysForCalc);
	/*int i = 0;
	while(i < numberOfArraysForCalc)
	{
		parseInputFile(i);
		i += 1;
	}*/
}
////////////////////////////////////////////
//END - Programs
////////////////////////////////////////////

////////////////////////////////////////////
// MAIN
////////////////////////////////////////////
int main(int argc, char *argv[]){
	if( argc > 1)
	{
		/*if(argv[1] == "-r") //Testing Run Time
		{
			testRunTime();
		}*/
		if(argv[1] == "-c") //Testing Correctness
		{
			testCorrectness();
		}
		/*else if(argv[1] == "-e") //Testing Example
		{
			testExample();
		}*/
		else
		{
			cout << "You did not enter correct arguments.\n" << endl;
			cout << "Please add -r,-c, or -e as an argument." << endl;
		}
	}
	else
	{
		testCorrectness(); //This will default to test correctness if not enough arguments are entered.	
	}
	return 0;
}
