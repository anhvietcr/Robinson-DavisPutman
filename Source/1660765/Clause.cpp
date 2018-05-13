#include "Clause.h"

Clause::Clause()
{
	this->status = 1;
}

Clause::~Clause()
{
}

//init clause with string, create items
void Clause::init(std::string str)
{
	int n = str.length();
	for (int i = 0; i < n; i++) {
		if (str[i] == '~') {
			this->status = 0; //navigative
		} else if (str[i] == '|' || i == n - 1) {
			if (i == n - 1) this->character = str[i];
			clause.push_back(std::make_pair(this->status, this->character));

			this->status = 1; //reset status
		} else {
			this->character = str[i];
		}
	}
}

//navigate result item
void Clause::initResult(std::string str)
{
	int n = str.length();
	this->status = 0;

	for (int i = 0; i < n; i++) {
		if (str[i] == '~') {
			this->status = 1; //positive
		} else {
			this->character = str[i];
			clause.push_back(std::make_pair(this->status, this->character));
		}
	}
}

//all items in clause
void Clause::printClause()
{
	for (int i = 0; i < this->clause.size(); i++) {
		std::cout << this->clause[i].first << " ";
		std::cout << this->clause[i].second << ",";
	}
}

//get items in clause
std::vector<std::pair<int, std::string>> Clause::get()
{
	return this->clause;
}

//update items in clause
bool Clause::set(std::vector<std::pair<int, std::string>> &newClause)
{
	this->clause.clear();
	this->clause = newClause;

	return true;
}

//clause with single item
bool Clause::isClauseSingle()
{
	if (this->clause.size() == 1) return true;
	return false;
}