#include "cEmpleado.h"
//class cEmpleado;

#define SueldoXHoraM 125.5
#define HorarioTrabajoM 4
typedef enum Semana { JUEVES = 3, VIERNES = 4, SABADO = 5 };
Semana semanaM[];

//typedef enum HorarioTrabajoM { lunes = 6, martes = 6, miercoles = 6, jueves = 6, viernes = 8, sabado = 8, domingo = 4 };


class cMesero : public cEmpleado
{

public:
	cMesero();
	cMesero(const string cuit, string l);
	virtual ~cMesero();

	//void SalarioCervezaM(); 
	void DiadeSemana() { dias++; } //CADA VEZ QUE PASE 1 TICK, PASA UN DIA.

	//GETS 
	int getDia() { return semanaM[dias]; }
	float getSalarioxHoraM() { return SueldoXHoraM; }
	float getSueldoM() { return SueldoM; }
	string getCUIT() { return cEmpleado::getCUIT(); } const
		string getnombre() { return cEmpleado::getnombre(); }
	string getLocal() { return cEmpleado::getLocal(); }

	//SETS
	void setSalarioM(float salario) { SueldoM = salario; }
	void setLocal(string l) { cEmpleado::setLocal(l); }
	void setNombre(string n) { cEmpleado::setNombre(n); }
	//friend ostream & operator<<(ostream &out, cMesero&m);

private:

	//HorarioTrabajoM horario;
	float SueldoM;
};

ostream& operator<<(ostream& out, cMesero& m);
istream& operator>>(istream& in, cMesero& m);

