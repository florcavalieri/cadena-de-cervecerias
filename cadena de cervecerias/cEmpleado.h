#pragma once
#include <iostream>
#include <string>

using namespace::std;

class cEmpleado
{

public:

	cEmpleado();
	cEmpleado(const string cuit, string nom = "", string l = "");
	virtual ~cEmpleado();

	//sets
	string getCUIT() { return CUIT; } const
		string getnombre() { return nombre; }
	string getLocal() { return local; }

	//gets
	void setLocal(string l) { local = l; }
	void setNombre(string n) { nombre = n; }

protected:

	const string CUIT;
	string nombre;
	string local;
	int dias;

};

ostream& operator<<(ostream& out, cEmpleado& e);
istream& operator>>(istream& in, cEmpleado& e);
