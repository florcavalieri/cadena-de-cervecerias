#include "cEmpleado.h"

#define SueldoXHoraV 150.5
#define HorarioTrabajoV 6
//class cEmpleado;

typedef enum Semana { LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO };
Semana semanaV[];

//typedef enum HorarioTrabajoV { lunes = 4, martes = 4, miercoles = 4, jueves = 6, viernes = 8, sabado = 8 };



class cVendedor : public cEmpleado
{

public:
	cVendedor();
	cVendedor(const string cuit, string l);
	virtual ~cVendedor();

	//void SalarioCervezaV();
	void DiadeSemana() { if (dias > 6) dias = 0; dias++; } //CADA VEZ QUE PASE 1 TICK, PASA UN DIA.

	//GETS 
	int getDia() { return semanaV[dias]; }
	float getSalarioxHoraV() { return SueldoXHoraV; }
	float getSueldoV() { return SueldoV; }
	string getCUIT() { return CUIT; } const
		string getnombre() { return nombre; }
	string getLocal() { return local; }


	//SETS
	void setSalarioV(float salario) { SueldoV = salario; }
	void setLocal(string l) { local = l; }
	void setNombre(string n) { nombre = n; }


private:
	//HorarioTrabajoV horario;
	float SueldoV;
};

ostream& operator<<(ostream& out, cVendedor& v);
istream& operator>>(istream& in, cVendedor& v);

