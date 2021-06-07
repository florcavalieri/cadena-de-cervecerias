#include "cTipoLocal.h"
#include "cCliente.h"
#include "cMesas.h"
#include <iostream>
#include <string>

template<typename cMesas>
class cListaT;

#define PRUBIA 10
#define PROJA 25
#define PNEGRA 35

class cBar : public cTipoLocal
{

public:

	cBar();
	//cBar(cListaT<cEncargado>*listaEncargados, cListaT<cMesero>*listaMeseros, cListaT<cVendedor>*listaVendedores, string num, string nombre, string ubicacion, int barriles = MAXBARRILES);
	cBar(cEncargado* encargado, cListaT<cEmpleado>* listaEmpleados, string num, int rubia, int roja, int negra, string nombre = "", string ubicacion = "");
	virtual ~cBar();


	//void DineroGanado();
	void LimpiezaMesas(); //Corregir.


	//Metodos Heredados
	void EntradaEmpleados() { cTipoLocal::EntradaEmpleados(); }
	//void LtsVendidos(); 
	void PagarEmpleados(/*, int dias*/); //Error con ListaEmpleados
	//void SalidaEmpleados(cEmpleado * empleado); //Hace falta?
	void SimularClientes();
	void SolicitarCerveza(int tipocerveza, int cantidad);
	bool VerificarBarriles(int tipocerveza, int cantidad);


	int getAcumEN() { return cTipoLocal::getAcumEN(); }
	int getAcumME() { return cTipoLocal::getAcumME(); }
	int getAcumVE() { return cTipoLocal::getAcumVE(); }
	float getRecaudo() { return cTipoLocal::getRecaudo(); }
	float getLtsVendidos() { return cTipoLocal::getLtsVendidos(); }
	string getNombre() { return cTipoLocal::nombre; }
	string getUbicacion() { return cTipoLocal::ubicacion; }
	string getNumero() { return cTipoLocal::numero; }

private:

	float DineroGanadoB;
	int PintasRubia, PintasRoja, PintasNegra; //Las vendo por litro!!!
	//cListaT <cMesas> *ListaMesas; //CORREGIR

	Estado estado[];
};

ostream& operator << (ostream& out, cBar* bar);

