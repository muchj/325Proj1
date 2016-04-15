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

struct results{
    int sum;
    int startIdx;
    int endIdx;
};

results mssAlgorithm1(int* array, int size){
	int i, j, k, sum;
        struct results r;
        r.sum = array[0];
        r.startIdx = -1;
        r.endIdx = -1;
	
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			sum = 0;
			for(k = i; k < j; k++){
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
//Algorithm 2
////////////////////////////////////////////

results mssAlgorithm2(int* array, int size){
	int i, j, sum;
        results r;
        r.sum = array[0];
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
//Algorithm 3
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

results mssAlgorithm4(int* array, int size)
{
    int maxNow = 0; 
    int maxBest = 0;
    int startBest = -1;
    int startNow = -1;
    int stopBest = -1;
    results r;
    
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
    r.sum = maxBest;
    r.startIdx = startBest;
    r.endIdx = stopBest;

    return r;
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
		string line;
		string delimiter = ", ";
		
		ifstream inputFile("MSS_Problems.txt");
		if (inputFile)
		{
			while(getline(inputFile, line))
			{
				//cout << line << endl;
				
			}
		}
		cout << "Now calculating line # " << lineCount +1 << endl;	
}
////////////////////////////////////////////
//	testCorrectness
//	- Used for calculating grade
////////////////////////////////////////////
void testCorrectness()
{
	int numberOfArraysForCalc = inputFileLineCount();
	
	int i = 0;
	while(i < numberOfArraysForCalc)
	{
		parseInputFile(i);
		i += 1;
	}
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
























