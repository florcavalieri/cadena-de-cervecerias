#include "cCliente.h"


cCliente::cCliente() {

	billetera = 0;
	sentado = false;
	pinta = 0;
	mediaPinta = 0;
}


cCliente::cCliente(float billetera, bool sentado, int pinta, float mediaPinta)
{
	this->billetera = billetera;
	this->sentado = sentado;
	this->pinta = pinta;
	this->mediaPinta = mediaPinta;
}


cCliente::cCliente(const cCliente& c)
{
	billetera = c.billetera;
	sentado = c.sentado;
	pinta = c.pinta;
	mediaPinta = c.mediaPinta;
}



cCliente::~cCliente() {

}





void cCliente::PedirCerveza()
{
	pinta = 0 + rand() % (2 - 0);

	mediaPinta = 0 + rand() % (4 - 0);
}
