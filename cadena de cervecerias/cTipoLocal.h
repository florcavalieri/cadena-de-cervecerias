#pragma once
#include <iostream>
#include <string>
#include "cEncargado.h"
#include "cMesero.h"
#include "cVendedor.h"
//#include "cListaT.h"
using namespace::std;

#define MAXBARRILES 15
#define BROJA 50
#define BNEGRA 60
#define BRUBIA 30
#define MINBARRILES 3

typedef enum Semana { LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO };
Semana semana[];

//class cEmpleado;
//class cEncargado;
//class cMesero;
//class cVendedor;
template <typename cEncargados>
class cListaT;
template <typename cVendedores>
class cListaT;
template <typename cEmpleados>
class cListaT;

class cTipoLocal
{

public:

	cTipoLocal();
	cTipoLocal(/*cListaT<cEncargado>*listaEncargados, cListaT<cMesero>*listaMeseros, cListaT<cVendedor>*listaVendedores,*/ string num, int rubia, int roja, int negra, string nombre = "", string ubicacion = "");
	//cTipoLocal(cListaT<cEmpleados>)
	virtual ~cTipoLocal();
	friend class cListaT;


	void EntradaEmpleados(); //REVISAR (cuando pasa un tick, pasa un dia o pasan horas??)
	//virtual void LtsVendidos() = 0;
	virtual void PagarEmpleados(/*cListaT<cEmpleado> *empleado,*/);
	//void SalidaEmpleados(cEmpleado * empleado); //VER 
	//virtual void SimularClientes() = 0;
	virtual void SimularClientes();
	virtual void SolicitarCerveza(int tipocerveza, int cantidad);
	virtual bool VerificarBarriles(int tipocerveza, int cantidad);

	//GETS
	int getAcumEN() { return acumEncargado; }
	int getAcumME() { return acumMesero; }
	int getAcumVE() { return acumVendedor; }
	float getRecaudo() { return recaudo; }
	float getLtsVendidos() { return ltsVendidos; }
	string getNombre() { return nombre; }
	string getUbicacion() { return ubicacion; }
	string getNumero() { return numero; }
	//static int getID() { return ID; }

protected:

	int BRubia, BRoja, BNegra;  //Barriles de cerveza: Rubia, Roja y Negra.
	//static int ID;
	string numero;
	string nombre;
	float recaudo;
	float ltsVendidos;
	string ubicacion;
	static int cantOperaciones;

	cListaT<cEncargado>* ListaEncargados;
	cListaT<cVendedor>* ListaVendedores;
	cListaT<cMesero>* ListaMeseros;

	//Acumuladores para que los empleados puedan cobrar
	int acumEncargado, acumMesero, acumVendedor, Dias;

};


