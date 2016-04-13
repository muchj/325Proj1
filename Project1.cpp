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

int mssAlgorithm2(int array[]){
	int i, j, sum;
	int arrayLength = array.length() - 1;
	int maxSum = array[0];
	
	for(i = 0; i < arrayLength; i++){
		sum = 0;
		j = i;
		for(j = i; j < arrayLength; j++){
			sum += array[j];
			if(sum > maxSum){
				maxSum = sum;
			}
		}
	}
	return maxSum;
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
	
	for(int i = f; i <= mid; i++)
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

////////////////////////////////////////////
//END - Algorithms
////////////////////////////////////////////
*/
////////////////////////////////////////////
//START - Programs
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
void parseInputFile(lineCount){
		string line;
		
		ifstream inputFile("MSS_Problems.txt");
		if (inputfile)
		{
			while(getline(inputFile, line)
			{
				if
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
























