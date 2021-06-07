#include "cMesero.h"


cMesero::cMesero() : cEmpleado()
{
	SueldoM = 0;
}

cMesero::cMesero(const string cuit, string l) : cEmpleado(cuit, l)
{
	SueldoM = 0;
}



cMesero::~cMesero() {

}



// void cMesero::SalarioCervezaM(){

// }

ostream& operator<<(ostream& out, cMesero& m)
{
	out << (cEmpleado&)m << endl;
	out << m.getSueldoM() << endl;
	return out;
}

istream& operator>>(istream& in, cMesero& m)
{
	string local, nombre;
	in >> (cEmpleado&)m;
	cout << "\nIngrese el local donde trabaja el Mesero: " << endl;
	in >> local;
	m.setLocal(local);
	cout << "\nIngrese el Nombre del Local: " << endl;
	in >> nombre;
	m.setNombre(nombre);
}

