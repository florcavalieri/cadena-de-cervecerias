#include "cListaT.h"
#include "cCadena.h"

cCadena::cCadena() {

	recaudoDinero = 0;
	recaudoLts = 0;

	/*empleado = new cEmpleado();
	bar = new cBar();
	puntoVenta = new cPuntodeVenta();*/
	/*ListaBares = new cListaT<cBar>();
	ListaPuntosVenta = new cListaT<cPuntodeVenta>();*/
	ListaLocales = new cListaT<cTipoLocal>();
	ListaEncargados = new cListaT<cEmpleado>();
	ListaEmpleados = new cListaT<cEmpleado>();

}



cCadena::~cCadena()
{
	//delete ListaEncargados;
	delete ListaLocales;
	//delete ListaMeseros;
	//delete ListaVendedores;
	delete ListaEmpleados;
}



void cCadena::Simulador()
{
	CrearListaEmpleados();
	CrearListaLocales();

	RecaudoTotalDinero();
	RecaudoTotalLitros();

	for (int i = 0; i < ListaLocales->getCA(); i++)
	{
		ListaLocales[i]->simularClientes();
	}


}

void cCadena::RecaudoTotalDinero() //ASI O COMO RECAUDO DINERO?
{
	for (int i = 0; i < ListaLocales->getCA(); i++)
	{
		cBar* bar = dynamic_cast<cBar*>(ListaLocales[i]);
		cPuntodeVenta* pdv = dynamic_cast<cPuntodeVenta*>(ListaLocales[i]);
		if (bar->getNombre() == "Bar" && bar != NULL)
			recaudoDinero = bar->getRecaudo() + recaudoDinero;
		if (pdv->getNombre() == "PDV" && pdv != NULL)
			recaudoDinero = pdv->getRecaudo() + recaudoDinero;
	}


}


void cCadena::RecaudoTotalLitros()
{
	for (int i = 0; i < ListaLocales->getCA(); i++)
	{
		cBar* bar = dynamic_cast<cBar*>(ListaLocales[i]);
		cPuntodeVenta* pdv = dynamic_cast<cPuntodeVenta*>(ListaLocales[i]);
		if (bar->getNombre() == "Bar" && bar != NULL)
			recaudoLts = bar->getLtsVendidos() + recaudoLts;
		if (pdv->getNombre() == "PDV" && pdv != NULL)
			recaudoLts = pdv->getLtsVendidos() + recaudoLts;
	}


}


void cCadena::CrearListaEmpleados()
{
	cEmpleado* encargados[MAX_ENCARGADOS];

	//cEmpleado* empleadito= new cEncargado();

	encargados[0] = new cEncargado("27-25606330-00", "1");
	encargados[1] = new cEncargado("27-17450445-02", "3");
	encargados[2] = new cEncargado("20-31220002-50", "4");
	encargados[3] = new cEncargado("20-27550445-02", "2");
	encargados[4] = new cEncargado("27-30223332-33", "5");
	encargados[5] = new cEncargado("27-00000001-12", "6");

	cListaT <cEmpleado>* ListaEncargados = new cListaT<class cEmpleado>(6);

	for (int i = 0; i < MAX_ENCARGADOS; i++)
	{
		try
		{
			(*ListaEmpleados).AgregarItem(encargados[i]);
		}
		catch (...)
		{
			cout << "Ha ocurrido una Excepcion al crear la lista de empleados" << endl;
		}
	}

	cEmpleado* vendedores[MAX_VENDEDORES];

	vendedores[0] = new cVendedor("20-888777-00", "1");
	vendedores[1] = new cVendedor("20-111000-07", "2");
	vendedores[2] = new cVendedor("20-222000-11", "3");
	vendedores[3] = new cVendedor("27-333000-12", "4");
	vendedores[4] = new cVendedor("27-444777-21", "5");
	vendedores[5] = new cVendedor("20-555333-10", "3");
	vendedores[6] = new cVendedor("27-999888-20", "4");
	vendedores[7] = new cVendedor("27-555663-30", "5");

	cListaT<cVendedor>* ListaVendedores = new cListaT<cVendedor>(12);

	for (int i = 0; i < MAX_VENDEDORES; i++)
	{
		try
		{
			(*ListaEmpleados).AgregarItem(vendedores[i]);
		}
		catch (...)
		{
			cout << "Error al crear la lista de Vendedores." << endl;
		}
	}

	cEmpleado* meseros[MAX_MESEROS];

	meseros[0] = new cMesero("27-998988-11", "1");
	meseros[1] = new cMesero("27-454545-10", "2");
	meseros[2] = new cMesero("27-363636-12", "3");
	meseros[3] = new cMesero("20-202020-13", "4");
	meseros[4] = new cMesero("20-787878-14", "5");
	meseros[5] = new cMesero("20-100000-15", "5");
	meseros[6] = new cMesero("20-000002-04", "3");
	meseros[7] = new cMesero("27-000033-55", "1");

	cListaT<cEmpleado>* ListaMeseros = new cListaT<cEmpleado>(10);


	for (int i = 0; i < MAX_MESEROS; i++)
	{
		try
		{
			(*ListaEmpleados).AgregarItem(meseros[i]);
		}
		catch (...)
		{
			cout << "Error al crear la lista de Meseros" << endl;
		}
	}

}
// 	//NO ESTOY SEGURO DE QUE SE PUEDA HACER ASI REVISAR!!!!!!!!!
// 	int MAX_EMPLEADOS=MAX_ENCARGADOS+MAX_MESEROS+MAX_VENDEDORES;
// 	cListaT<cEmpleado>*ListaEmpleados = new cListaT<cEmpleado>(MAX_EMPLEADOS);
// 	for(int i=0;i<MAX_EMPLEADOS;i++)
// 	{
// 		try
// 		{
// 			(*ListaEmpleados) + (meseros[i]);
// 		}
// 		catch (...)
// 		{
// 			cout << "Error al crear la lista de Empleados" << endl;
// 		}
// 	}
// 	for(int i=0;i<MAX_EMPLEADOS;i++)
// 	{
// 		try
// 		{
// 			(*ListaEmpleados) + (vendedores[i]);
// 		}
// 		catch (...)
// 		{
// 			cout << "Error al crear la lista de Empleados" << endl;
// 		}
// 	}
// 	for(int i=0;i<MAX_EMPLEADOS;i++)
// 	{
// 		try
// 		{
// 			(*ListaEmpleados) + (encargados[i]);
// 		}
// 		catch (...)
// 		{
// 			cout << "Error al crear la lista de Empleados" << endl;
// 		}
// 	}
// }

//void cCadena::CrearListaEncargados()
//{
//	cEmpleado *empleados[MAX_ENCARGADOS];
//
//	empleados[0] = new cEmpleado("27-25606330-00", "1");
//	empleados[1] = new cEmpleado("27-17450445-02", "3");
//	empleados[2] = new cEmpleado("20-31220002-50", "4");
//	empleados[3] = new cEmpleado("20-27550445-02", "2");
//	empleados[4] = new cEmpleado("27-30223332-33", "5");
//
//	cListaT <cEmpleado>*ListaEmpleados = new cListaT<class cEmpleado>(MAX_ENCARGADOS);
//
//	for (int i = 0; i < MAX_ENCARGADOS; i++)
//	{
//		try
//		{
//			(*ListaEmpleados) + (empleados[i]);
//		}
//		catch (...)
//		{
//			cout << "Ha ocurrido una Excepcion al crear la lista de empleados" << endl;
//		}
//	}
//}

//void cCadena::CrearListaVendedores()
//{
//	cVendedor *vendedor[MAX_VENDEDORES];
//
//	vendedor[0]=new cVendedor()
//}

//void cCadena::CrearListaMeseros()
//{
//}

void cCadena::CrearListaLocales()
{
	int rubias = 0, rojas = 0, negras = 0;

	rubias = rand() % 5;
	rojas = rand() % 5;
	negras = MAXBARRILES - (rojas + rubias);

	/*cBar *bares[MAX_LOCALES];

	bares[0] = new cBar((*ListaEncargados)[0], ListaMeseros, ListaVendedores, "1", rubias, rojas, negras, "Bar", "Recoleta");
	bares[1] = new cBar((*ListaEncargados)[4], ListaMeseros, ListaVendedores, "2", rubias, rojas, negras, "Bar", "Palermo Chico");
	bares[2] = new cBar((*ListaEncargados)[1], ListaMeseros, ListaVendedores, "3", rubias, rojas, negras, "Bar", "Urquiza");

	cPuntodeVenta *pdv[MAX_LOCALES];

	pdv[0] = new cPuntodeVenta((*ListaEncargados)[2], ListaVendedores, "4", rubias, rojas, negras, "PDV", "Palermo Soho");
	pdv[1] = new cPuntodeVenta((*ListaEncargados)[3], ListaVendedores, "5", rubias, rojas, negras, "PDV", "Quilmes");
	pdv[2] = new cPuntodeVenta((*ListaEncargados)[5], ListaVendedores, "6", rubias, rojas, negras, "PDV", "Olivos");*/

	cListaT<cTipoLocal>* Listalocales = new cListaT<cTipoLocal>(MAX_LOCALES);
	cListaT<cEncargado>* ListaEncargados = new cListaT<cEncargado>(MAX_ENCARGADOS);
	cListaT<cVendedor>* ListaEncargados = new cListaT<cVendedor>(MAX_VENDEDORES);
	cListaT<cMesero>* ListaEncargados = new cListaT<cMesero>(MAX_MESEROS);
	cEmpleado* e1 = ListaEmpleados->getItem(1);
	cEmpleado* enc = ListaEncargados->getItem(4);
	cTipoLocal* locales[MAX_LOCALES]; //DECIA CTIPOLOCAL LO CAMBIE POR CBARES NO SE SI ESTA BIEN
	locales[0] = new cBar(ListaEn, "1", rubias, rojas, negras, "Bar", "Recoleta");
	locales[1] = new cBar((*ListaEncargados)->getItem(4), ListaEmpleados, "2", rubias, rojas, negras, "Bar", "Palermo Chico");
	locales[2] = new cBar((*ListaEncargados)[1], ListaEmpleados, "3", rubias, rojas, negras, "Bar", "Urquiza");
	locales[3] = new cPuntodeVenta((*ListaEncargados)[2], ListaVendedores, "4", rubias, rojas, negras, "PDV", "Palermo Soho");
	locales[4] = new cPuntodeVenta((*ListaEncargados)[3], ListaVendedores, "5", rubias, rojas, negras, "PDV", "Quilmes");
	locales[5] = new cPuntodeVenta((*ListaEncargados)[5], ListaVendedores, "6", rubias, rojas, negras, "PDV", "Olivos");


	for (int i = 0; i < 6; i++)
	{
		try
		{
			(*ListaLocales).AgregarItem(locales[i]);
		}
		catch (...)
		{
			cout << "Error al crear la lista de Puntos de Locales" << endl;
		}
	}

}

void cCadena::Menu()
{
	int opcion = 0;

	do
	{
		cout << ".......x Patagonia Limited x......" << endl
			<< "\nMenu de opciones: " << endl
			<< "\n1) Correr Simulacion." << endl
			<< "\n2) Imprimir informacion general." << endl
			<< "\n3) Detener Programa." << endl;
		cin >> opcion;

		switch (opcion)
		{
		case 1:
		{
			Simulador();
		}
		case 2:
		{
			Imprimir();
		}

		default:
			break;
		}
	} while (opcion != 3);
}

void cCadena::Imprimir()
{
	cout << "INFORMACION DE BARES\n" << endl;
	for (int i = 0; i < ListaLocales->getCA(); i++)
	{
		if (ListaLocales[i]->getNombre() == 'Bar')
		{
			for (int k = 0; k < ListaLocales->getCA(); k++)
			{
				cout << (*ListaLocales[i]) << endl;
				cout << ListaEmpleados[k] << endl;
			}
		}
	}

	cout << "INFORMACION DE PUNTOS DE VENTA\n" << endl;
	for (int i = 0; i < ListaLocales->getCA(); i++)
	{
		if (ListaLocales->getNombre() == 'PDV')
		{
			for (int k = 0; k < ListaLocales->getCA(); k++)
			{
				cout << ListaLocales[i]->getNombre() << endl;
				cout << ListaLocales[i]->getUbicacion() << endl;
				cout << ListaLocales[i]->getNumero() << endl;
				cout << ListaEncargados[k] << endl;
			}
		}
	}
}
//void cCadena::CrearListaPuntosdeVenta()
//{
//}
//
//void cCadena::CrearListadeBares()
//{
//}

