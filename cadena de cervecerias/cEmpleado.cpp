#include "cEmpleado.h"
#include "cMesero.h"



cEmpleado::cEmpleado() : CUIT(0)
{
	local = "";
}

cEmpleado::cEmpleado(const string cuit, string nom = "", string l) : CUIT(cuit)
{
	this->dias = dias;
	local = l;
	//tipoempleado = tipo;
}



cEmpleado::~cEmpleado() {

}

ostream& operator<<(ostream& out, cEmpleado& e)
{
	out << e.getnombre() << endl;
	out << e.getCUIT() << endl;
	out << e.getLocal() << endl;
	return out;
}


istream& operator>>(istream& in, cEmpleado& e)
{
	string nombre, local;
	cout << "\nIngrese el Nombre del Empleado: " << endl;
	in >> nombre;
	e.setNombre(nombre);
	cout << "\nIngrese el Local en el que trabaja: " << endl;
	in >> local;
	e.setLocal(local);
	return in;
}

