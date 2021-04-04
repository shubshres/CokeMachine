#Shubhayu Shrestha 1001724804
#makefile for Coding Assignment 3
SRC = Code3_1001724804.cpp
OBJ = $(SRC:.cpp=.o)
EXE = $(SRC:.cpp=.e)

HFILES = CokeMachine.h

CFLAGS = -g -std=c++11

all : $(EXE)
 
$(EXE): $(OBJ)
	g++ $(CFLAGS) $(OBJ) -o $(EXE)

$(OBJ) : $(SRC)
	g++ -c $(CFLAGS) $(SRC) -o $(OBJ)
