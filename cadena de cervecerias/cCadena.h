#include <stdlib.h>
#include <iostream>
#include "cBar.h"
#include "cPuntodeVenta.h"
#include "cListaT.h"
#include "cEncargado.h"
#include "cMesero.h"
#include "cVendedor.h"

#define MAX_ENCARGADOS 6
#define MAX_VENDEDORES 8
#define MAX_MESEROS 8
#define MAX_LOCALES 6

//template<typename cBar>
//class cListaT;
//template<typename cPuntodeVenta>
//class cListaT;
//template<typename cEncargados>
//class cListaT;

class cCadena
{

public:

	cCadena();
	~cCadena();

	void Simulador();
	void RecaudoTotalDinero();
	void RecaudoTotalLitros();

	//Creo 
	void CrearListaEmpleados();
	/*void CrearListaEncargados();
	void CrearListaVendedores();
	void CrearListaMeseros();*/
	void CrearListaLocales();
	void Menu();
	void Imprimir();
	/*void CrearListaPuntosdeVenta();
	void CrearListadeBares();*/


private:

	float recaudoDinero;
	float recaudoLts;

	//objetos:
	/*cListaT <cBar> *ListaBares;
	cListaT <cPuntodeVenta>* ListaPuntosVenta;*/
	cListaT<cTipoLocal>* ListaLocales;
	// cListaT <cEmpleado>*ListaEncargados;
	// cListaT<cMesero>*ListaMeseros;
	// cListaT<cVendedor>*ListaVendedores;
	cListaT<cEmpleado>* ListaEmpleados;




};
