#pragma once 
#include <iostream>
#include <string>
#include "cCadena.h"
using namespace::std;


int main(void)
{
	cCadena* Patagonia = new cCadena();

	Patagonia->Menu();

	delete Patagonia;
	return 0;
}