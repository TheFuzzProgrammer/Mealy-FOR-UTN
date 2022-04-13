#pragma once
#include <stdlib.h>

namespace Conversions {

	int CharToInteger(char _char) {
		char* pointer = &_char;
		int lambda = atoi(pointer);
		return lambda;
	}

}