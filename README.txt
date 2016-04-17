Project 1 Group 28

Members:
	Joseph Cuellar
	Adam Much
	Ryan Peters

1. Building Program:
	There is a make file for building the program.  The commands 'make', 'make all', and 'make maxsum' can be 
	used to build the program.  Make creates the object code file and an executible, 'maxsum'.  'make clean',
	will remove the object code and executible files.

2. Running Program:
	The program is run from the command line by invoking maxsum.  The program can be run with an option.
	Option '-c' will run the program for correctness.  Option '-r' will run the program for testing.
	If an option is not used, the program defaults to running correctness.
	
3. Running For Correctness:
	'maxsum -c'
	Running for correctness is used to check if the algorithms work correctly.  It will read arrays from
	'MSS_Problems.txt'.  Each array is run through Algorithm1, Algorithm2, Algorithm3, and Algorithm4.  The 
	results are written to 'MSS_Results.txt'  The results for each algorithm includes the Algorithm number,
	the full array, the sub-array with the highest sum, and the highest sum.

4. Running Test:
	'maxsum -r'
	Running a test will get the running time for one of the algorithms.  The user is prompted for the algorithm
	they want to test, then the number of elements in the array used for testing.  The array is filled with 
	random number from -5 to 15.  The running time is printed to the screen.
	
5. Algorithms
	Algorithm1 uses enumeration, run time is Theta(n^3)
	Algorithm2 uses a better enumeration, run time is Theta(n^2)
	Algorithm3 uses divided and conquer, run time is Theta(nlgn)
	Algorithm4 runs in linear time, Theta(n)
	