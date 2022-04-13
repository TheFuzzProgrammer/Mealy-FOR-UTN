#include "Mealy.h"

int main() {
	mealy::status estado;
	estado.s_symbol('a', 'b', 'c');

	std::cout << estado.ToString();

	return 0;
}