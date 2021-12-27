# *****************************************************
# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g
RM := rm -rf
 
# ****************************************************
# Targets

all: main

main: CSVFormater.o Lines.o Table.o
	$(CC) $(CFLAGS) -o CSVFormater CSVFormater.o Lines.o Table.o
 
CSVFormater.o: CSVFormater.cpp Lines.h Table.h
	$(CC) $(CFLAGS) -c CSVFormater.cpp
 
Lines.o: Lines.h

Table.o: Lines.h Table.h

# ****************************************************
# Run command
run:
	./CSVFormater

# ****************************************************
# Clean command
clean: 
	-$(RM) CSVFormater *.o
	-@echo ' '