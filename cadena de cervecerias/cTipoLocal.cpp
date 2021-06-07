#include "cTipoLocal.h"

int cTipoLocal::cantOperaciones = 0;

cTipoLocal::cTipoLocal()  //REVISAR
{
	//ID++;

	ListaEncargados = new cListaT<cEmpleado>();
	ListaMeseros = new cListaT<cMesero>();
	ListaVendedores = new cListaT<cVendedor>();


	numero = "";
	Dias = 0;
	acumEncargado = 0;
	acumMesero = 0;
	acumVendedor = 0;
	BRubia = 0;
	BRoja = 0;
	BNegra = 0;
	ltsVendidos = 0;
	recaudo = 0;
}

cTipoLocal::cTipoLocal(/*cListaT<cEncargado>*listaEncargados, cListaT<cMesero>*listaMeseros, cListaT<cVendedor>*listaVendedores,*/ string num, int rubia, int roja, int negra, string nombre = "", string ubicacion = "")
{
	//ID++;
	BRubia = rubia;
	BRoja = roja;
	BNegra = negra;
	this->nombre = nombre;
	this->ubicacion = ubicacion;
	numero = num;
	recaudo = 0;
	ltsVendidos = 0;

	Dias = 0;
	acumEncargado = 0;
	acumMesero = 0;
	acumVendedor = 0;

	// ListaEncargados = listaEncargados;
	// ListaMeseros = listaMeseros;
	// ListaVendedores = listaVendedores;
}



cTipoLocal::~cTipoLocal() {

	delete ListaEncargados;
	delete ListaMeseros;
	delete ListaVendedores;
	//ID--;
}



void cTipoLocal::EntradaEmpleados()
{
	for (int i = 0; i < ListaEmpleados->getCA(); i++)
	{
		cEncargado* en = dynamic_cast<cEncargado*>(ListaEmpleados[i]);
		cMesero* me = dynamic_cast<cMesero*>(ListaEmpleados[i]);
		cVendedor* ven = dynamic_cast<cVendedor*>(ListaEmpleados[i]);

		if (en != NULL && semana[Dias] == semanaM[en->getDia()])
		{
			acumEncargado = 1 + acumEncargado;
			PagarEmpleados();
		}
		if (me != NULL && semana[Dias] == semanaM[me->getDia()])
		{
			acumMesero = 1 + acumMesero;
			PagarEmpleados();
		}

		if (ven != NULL && semana[Dias] == semanaV[ven->getDia()])
		{
			acumVendedor = 1 + acumVendedor;
			PagarEmpleados();
		}
	}

	if (Dias == 6)
		Dias = -1;

	semana[Dias++];
}


//void cTipoLocal::LtsVendidos(){
//	//COMPLETAR
//}

void cTipoLocal::PagarEmpleados(/*cListaT<cEmpleado>* empleado,*/)
{
	float totalen = 0, totalven = 0;

	for (int i = 0; i < ListaEmpleados->getCA(); i++)
	{
		cEncargado* en = dynamic_cast<cEncargado*>(ListaEmpleados[i]);
		cVendedor* ven = dynamic_cast<cVendedor*>(ListaEmpleados[i]);

		if (en != NULL)
		{
			for (int i = 0; i < Dias; i++)
			{
				if (i <= 3 && semana[i] == semana[en->getDia()])
					totalen = ((SueldoXHoraE * LaJ) * acumEncargado) + en->getSueldoE();

				if (i > 3 && i <= 5 && semana[i] == semana[en->getDia()])
					totalen = ((SueldoXHoraE * VaS) * acumEncargado) + en->getSueldoE();

				if (i = 6 && semana[i] == semana[en->getDia()])
					totalen = ((SueldoXHoraE * D) * acumEncargado) + en->getSueldoE();
			}

			en->setSalarioE(totalen);
		}

		if (ven != NULL)
		{
			totalven = ((SueldoXHoraV * HorarioTrabajoV) * acumVendedor) + ven->getSueldoV();
			ven->setSalarioV(totalven);
		}

	}
}



//void cTipoLocal::SalidaEmpleados(cEmpleado * empleado){
//
//
//	//COMPLETAR
//
//}



void cTipoLocal::SimularClientes()
{
	int cantpersonas = rand() % 10;
	int tipocerveza = 0, cantcerveza = 0; //Para puntos de venta cantcerveza es con barriles y para bar con pintas
	for (int i = 0; i < cantpersonas; i++)
	{
		for (int j = 0; j < ListaLocales->getCA(); j++)
		{
			tipocerveza = 1 + rand() % (4 - 1);
			cantcerveza = 1 + rand() % (4 - 1);
			if (VerificarBarriles(tipocerveza, cantcerveza) == true)
			{
				SolicitarCerveza(tipocerveza, cantcerveza);
				ltsVendidos = cantcerveza + ltsVendidos;
				//para el recaudo tengo que usar el precio de los barriles en las ventas de punto de venta pero para bares tengo que usar los defines de los precios de las pintas!!!
			}
		}
	}
}

void cTipoLocal::SolicitarCerveza(int tipocerveza, int cantidad)
{
	cantOperaciones++;

	if (tipocerveza == 1)
		BRubia = BRubia - cantidad;

	if (tipocerveza == 2)
		BRoja = BRoja - cantidad;

	if (tipocerveza == 3)
		BNegra = BNegra - cantidad;
}

bool cTipoLocal::VerificarBarriles(int tipocerveza, int cantidad)
{
	switch (tipocerveza)
	{
	case 1:
	{
		if (BRubia > MINBARRILES && cantidad > MINBARRILES)
			return true;
		break;
	}

	case 2:
	{
		if (BRoja<MINBARRILES && cantidad>MINBARRILES)
			return true;
		break;
	}

	case 3:
	{
		if (BNegra<MINBARRILES && cantidad>MINBARRILES)
			return true;
		break;
	}
	}
}

