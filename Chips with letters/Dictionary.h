#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Dictionary
{
public:
	Dictionary();
	~Dictionary();
	Dictionary(const char letters[], int size, int costs[], int Size2);


	void findWord(std::string adress);
	int cost(std::string buffer);
	void printres()const;

private:
	bool StarFactor;
	int Stars;
	char Letters[8];
	int Costs[33];
	std::string Buffer;
	int maxCost;
	std::string Last;
	int BufferSize;
};

