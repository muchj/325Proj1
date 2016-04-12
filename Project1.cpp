/*
CS325 - Project 1 
Contributors - Joseph Cuellar, Adam Much, Ryan Peters
Instructions: 
*/

#include <iostream>
#include <fstream>
#include <istream>
#include <string>
using namespace std;
////////////////////////////////////////////
// START - Algorithms
////////////////////////////////////////////
////////////////////////////////////////////
// Algorithm 1 - Enumeration
////////////////////////////////////////////

/*int mssAlgorithm1(array){
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

int mssAlgorithm2(array){
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
























