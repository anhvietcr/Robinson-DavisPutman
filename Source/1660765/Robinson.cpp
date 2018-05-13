#include "Robinson.h"

Robinson::Robinson()
{
	std::memset(visited, 0, sizeof(visited));
}

Robinson::~Robinson()
{
}

bool Robinson::init(char * input)
{
	this->in.open(input, std::ios::in);
	if (!in) return false;

	//get, init KB
	in >> nKB;
	KB = new Clause[nKB];

	for (int i = 0; i < nKB; i++) {
		in >> buffer;

		//set index character and check visited
		this->setIndex(buffer);

		//create Clause and add to KB
		Clause clause;
		if (i == nKB - 1) {
			clause.initResult(buffer);
		} else {
			clause.init(buffer);
		}
		this->KB[i] = clause;
	}
	return true;
}

//Debug, [] KB
void Robinson::printKB()
{
	for (int i = 0; i < nKB; i++) {
		this->KB[i].printClause();
		std::cout << "\n";
	}
}
//Debug, [] visited
void Robinson::printVisited()
{
	for (int c = 0; c < MAX_CHARACTER; c++) {
		std::cout << visited[c] << " " << char(c + 65) << "\n";
	}
}

//set index all character in input
void Robinson::setIndex(std::string str)
{
	int n = str.length();
	for (int i = 0; i < n; i++) {
		for (int c = 0; c < MAX_CHARACTER; c++) {
			//if A->Z == str[i], and if !visited, mark it
			if (char(c + 65) == str[i]) {
				if (!visited[c]) visited[c] = 1;
			}
		}
	}
}

//Robinson Algorithm
bool Robinson::run()
{
	//A->Z
	for (int c = 0; c < MAX_CHARACTER; c++) {

		//character exists in input
		if (visited[c]) {

			//foreach clause in KB
			for (int i = 0; i < nKB; i++) {
				std::vector<std::pair<int, std::string>> clause = this->KB[i].get();

				for (int cl = 0; cl < clause.size(); cl++) {
					//string to char (first character in string)
					if (clause[cl].second[0] == char(c + 65)) {

						//remove character in literal
						clause.erase(clause.begin() + cl);

						//update new clause into KB
						this->KB[i].set(clause);

						//mark character is visited
						visited[c] = 0;
					}
				}

				if (this->KB[i].isClauseSingle()) {

					//foreach clause 2 in KB
					for (int j = 0; j < nKB; j++) {
						if (i != j) {
							std::vector<std::pair<int, std::string>> clause2 = this->KB[j].get();

							//p && ~p exists
							if (this->KB[j].isClauseSingle()) {
								if (clause[0].second == clause2[0].second) {
									if (clause[0].first != clause2[0].first) return true;
								}
							}
						}
					}
				}
			}
		}
	}
	return false;
}

//Print result
bool Robinson::result(char * output)
{
	this->out.open(output, std::ios::out);
	if (!out) return false;

	if (this->run()) {
		out << "true";
		std::cout << "true";
		return true;
	}

	out << "false";
	std::cout << "false";
	return false;
}