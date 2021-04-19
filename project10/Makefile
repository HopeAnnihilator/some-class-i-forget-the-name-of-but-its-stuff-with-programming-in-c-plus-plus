# #!/bin/bash
# make file for class Date
# Create a compilation macro to clean up code
CC=g++ -std=c++11

Project_10:  Project_10.o  Project_10_main.o
	$(CC) Project_10.o Project_10_main.o -o Project_10

Project_10.o: Project_10.cpp Project_10.h
	$(CC) -c  Project_10.cpp

Project_10_main.o:  Project_10.h  Project_10_main.cpp
	$(CC) -c  Project_10_main.cpp
clean:
	rm *.o Project_10

