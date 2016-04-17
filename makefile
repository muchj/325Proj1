all: maxsum
maxsum: Project1.o
	g++ -g Project1.o -o maxsum
Project1.o:
	g++ -g -c Project1.cpp
	
clean:
	rm Project1.o
	rm maxsum