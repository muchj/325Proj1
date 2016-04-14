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
////////////////////////////////////////////
// START - Algorithms
////////////////////////////////////////////
////////////////////////////////////////////
// Algorithm 1 - Enumeration
////////////////////////////////////////////

/*int mssAlgorithm1(int array[]){
	int i, j, k, sum;
	int maxSum = array[0];
	
	for(i = 0; i < array.length; i++){
		for(j = 0; j < array.length(); j++){
			sum = 0;
			for(k = i; k < j; k++){
				sum += array[k];
			}
			if(sum > maxSum){
				maxSum = sum;
			}
		}
	}
	return maxSum;
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
	
	int mid = (f + l) / 2;
	
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
*/
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
void parseInputFile(lineCount){
		string line;
		string delimiter = ", ";
		
		ifstream inputFile("MSS_Problems.txt");
		if (inputfile)
		{
			while(getline(inputFile, line)
			{
				
			}
		}
		
		cout << "Now calculating line # " << lineCount +1 << endl;
		
}

int main(){
	int lineCount;
	lineCount = inputFileLineCount();
	parseInputFile(lineCount);
	return 0;
}
























