#include "Robinson.h"

int main(int argc, char * argv[])
{
	Robinson * algo = new Robinson();

	if (algo->init(argv[1]))
		algo->result(argv[2]);

	return 0;
}