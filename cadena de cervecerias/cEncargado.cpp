#include "cEncargado.h"


cEncargado::cEncargado() : cEmpleado()
{
	SueldoE = 0;
	this->dias = 0;
	//HorarioTrabajoE = { 6,6,6,6,8,8,4 };
}

cEncargado::cEncargado(const string cuit, string nom = "", string l = "") : cEmpleado(cuit, l)
{
	SueldoE = 0;
}



cEncargado::~cEncargado() {

}




//void cEncargado::SalarioCervezaE(){
//
//}


void cEncargado::DiadeSemana()
{
	dias++;

	if (dias > 6)
		dias = 0;
}

ostream& operator<<(ostream& out, cEncargado& e)
{
	out << (cEmpleado&)e << endl;
	out << e.getSueldoE << endl;
	return out;
}

istream& operator>>(istream& in, cEncargado& e)
{
	string local, nombre;
	in >> (cEmpleado&)e;
	cout << "\nIngrese el local donde trabaja el Mesero: " << endl;
	in >> local;
	e.setLocal(local);
	cout << "\nIngrese el Nombre del Local: " << endl;
	in >> nombre;
	e.setNombre(nombre);
}
