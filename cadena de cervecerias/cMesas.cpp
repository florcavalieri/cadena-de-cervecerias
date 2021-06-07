#include "cMesas.h"
#include "cBar.h"

int cMesas::NumeroMesa = 0;

cMesas::cMesas() : cBar()
{
	NumeroMesa++;
}



cMesas::~cMesas(){

	NumeroMesa--;
}
