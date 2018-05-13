#pragma once
#include <iostream>
#include <vector>
#include <string>

class Clause
{
	//0 = navigative
	//1 = positive
	//save 1 clause with multi pair items
	std::vector<std::pair<int, std::string>> clause;
	int status;
	std::string character;

public:
	Clause();
	~Clause();
	void init(std::string);
	void initResult(std::string);
	void printClause();
	std::vector<std::pair<int, std::string>> get();
	bool set(std::vector<std::pair<int, std::string>>&);
	bool isClauseSingle();
};

