#pragma once
#include "Clause.h"

#include <fstream>
#include <stack>
#define MAX_CHARACTER 26

class Robinson
{
	std::ifstream in;
	std::ofstream out;

	std::string buffer;				//read input
	Clause * KB;					//[] clause
	int nKB;						//number clause
	int visited[MAX_CHARACTER];		//0->26 ~ A->Z

public:
	Robinson();
	~Robinson();
	bool init(char *);
	void printKB();
	void printVisited();
	bool run();
	bool result(char *);
	void setIndex(std::string);
};

