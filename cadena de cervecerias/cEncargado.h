#include "cEmpleado.h"
//class cEmpleado;

#define SueldoXHoraE 200.5

typedef enum Semana { LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO };
Semana semanaE[];

//typedef enum HorarioTrabajoE { lunes = 6, martes = 6, miercoles = 6, jueves = 6, viernes = 8, sabado = 8, domingo = 4 };

#define LaJ 6
#define VaS 8
#define D 4

class cEncargado : public cEmpleado
{

public:

	cEncargado();
	cEncargado(const string cuit, string nom = "", string l = "");
	virtual ~cEncargado();

	//void SalarioCervezaE();
	void DiadeSemana(); //CADA VEZ QUE PASE 1 TICK, PASA UN DIA. (REVISAR)!!!!


	//GETS 
	int getDia() { return semanaE[dias]; }
	float getSalarioxHoraE() { return SueldoXHoraE; }
	float getSueldoE() { return SueldoE; }
	string getCUIT() { return cEmpleado::getCUIT(); } const
		string getnombre() { return cEmpleado::getnombre(); }
	string getLocal() { return cEmpleado::getLocal(); }


	//SETS
	void setSalarioE(float salario) { SueldoE = salario; }
	void setLocal(string l) { cEmpleado::setLocal(l); }
	void setNombre(string n) { cEmpleado::setNombre(n); }

private:

	//int HorarioTrabajoE[7];
	float SueldoE;

};

ostream& operator<<(ostream& out, cEncargado& e);
istream& operator>>(istream& in, cEncargado& e);

