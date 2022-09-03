#include <iostream>
#include "mod2.h"
#include "mod4.h"

int main() {

        std::clog << "\nI am mod-5-calling  fun-2 of mod2.so\n";
	fun2();

	std::clog << "\nCalling mod4.a - static library funcion f4()\n";
	f4();
	return EXIT_SUCCESS;
}

