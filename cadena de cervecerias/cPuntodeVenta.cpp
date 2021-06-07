#include "cPuntodeVenta.h"


cPuntodeVenta::cPuntodeVenta() {
	DineroGanadoP = 0;
}

cPuntodeVenta::cPuntodeVenta(cEncargado* encargado, cListaT<cEmpleado>* ListaVendedores, string num, int rubia, int roja, int negra, string nombre = "", string ubicacion = "") : cTipoLocal(/*listaEncargados, listaVendedores,*/ num, rubia, roja, negra, nombre, ubicacion)
{
	DineroGanadoP = 0;
}

cPuntodeVenta::cPuntodeVenta(const cPuntodeVenta& pdv)
{
	DineroGanadoP = pdv.DineroGanadoP;
}



cPuntodeVenta::~cPuntodeVenta() {

}



void cPuntodeVenta::SolicitarCerveza(int tipocerveza, int cantidad)
{
	cTipoLocal::SolicitarCerveza(tipocerveza, cantidad);
}


bool cPuntodeVenta::VerificarBarriles(int tipocerveza, int cantidad)
{
	return cTipoLocal::VerificarBarriles(tipocerveza, cantidad);
}

ostream& operator << (ostream& out, cPuntodeVenta* pdv)
{
	out << pdv->getNombre() << endl;
	out << pdv->getUbicacion() << endl;
	out << pdv->getNumero() << endl;
	return out;
}

