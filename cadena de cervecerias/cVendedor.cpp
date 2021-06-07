#include "cVendedor.h"


cVendedor::cVendedor() : cEmpleado()
{
	SueldoV = 0;
	dias = 0;
	local = "";
}

cVendedor::cVendedor(const string cuit, string l) : cEmpleado(cuit, l)
{
	SueldoV = 0;
}



cVendedor::~cVendedor() {

}





//void cVendedor::SalarioCervezaV()
//{
//
//}

ostream& operator<<(ostream& out, cVendedor& v)
{
	out << (cEmpleado&)v;
	out << v.getSueldoV << endl;
	return out;
}

istream& operator>>(istream& in, cVendedor& v)
{
	string local, nombre;
	in >> (cEmpleado&)v;
	cout << "\nIngrese el local donde trabaja el Mesero: " << endl;
	in >> local;
	v.setLocal(local);
	cout << "\nIngrese el Nombre del Local: " << endl;
	in >> nombre;
	v.setNombre(nombre);
}
